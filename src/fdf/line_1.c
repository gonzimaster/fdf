/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:59:50 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/27 10:23:22 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "scale_coord.h"
#include "line.h"
#include "utils.h"
#include "libft.h"
#include <math.h>

/*
 * To get an estimation of the current z position in a line the following
 * operations are performed:
 * 1. The line length is computed.
 * 2. The distance from the current position to the end of the line is computed.
 * 3. A ratio (r) representing the current position in the line is computed.
 * 4. z = z_o + (z_f - z_o) * r + abs(z_min) 
 * 4(bis). abs(z_min) is added so that the min value of z is always 0 and the
 * max is altitude.
 */

static void	ft_get_relative_position(t_line line, t_coord_2d coord,
		t_dim max_dims, t_line_param *line_param)
{
	line_param->line_length = sqrt(pow(line.end.x - line.start.x, 2)
			+ pow(line.end.y - line.start.y, 2));
	line_param->dist_to_end = sqrt(pow(line.end.x - coord.x, 2)
			+ pow(line.end.y - coord.y, 2));
	line_param->line_pos = (line_param->line_length - line_param->dist_to_end)
		/ line_param->line_length;
	line_param->z = line.start.z + (int)((line.end.z - line.start.z)
			* (line_param->line_pos)) + ft_abs_value(max_dims.z.min);
}

void	ft_put_printable_pixel(t_coord_2d coord, int *tmp_y, t_img img,
			unsigned int color)
{
	if (ft_pixel_in_screen(coord.x, *tmp_y, img.screen))
		my_mlx_pixel_put(img.img_data, coord.x, *tmp_y, color);
}

/*
 * The y coordinate is calculated using: y = m(x - x_o) + y_o
 * An interpolation for the z coordinate is performed in 
 * ft_get_relative_position to estimate the color for the current height in 
 * the line.
 * Since any slope that is not 45º will produce gaps, 
 * ft_fill_upwards/downwards is called to fill the gaps with additional points.
 * tmp_y is used to keep track of the last y and be able to fill from the last
 * y (tmp_y) to the current y.
 */

static void	ft_fill_and_print(t_line line, int *tmp_y, t_img img,
			t_dim max_dims)
{
	unsigned int	color;
	t_grad			gradient;
	t_line_param	line_param;

	ft_init_gradient(&gradient);
	if (!line.vertical)
	{
		line.coord.y = (int)(line.slope * (line.coord.x - line.start.x)
				+ line.start.y);
	}
	else
		line.coord.y = line.end.y;
	ft_get_relative_position(line, line.coord, max_dims, &line_param);
	color = ft_get_color(line_param.z, max_dims.altitude, gradient);
	if (line.start.y < line.end.y)
		ft_fill_upwards(line.coord, tmp_y, img, color);
	else
		ft_fill_downwards(line.coord, tmp_y, img, color);
	ft_put_printable_pixel(line.coord, tmp_y, img, color);
	*tmp_y = line.coord.y;
}	

static void	ft_init_line(t_line *line, t_coord start, t_coord end)
{
	line->start = start;
	line->end = end;
	line->vertical = 0;
	if (start.x != end.x)
		line->slope = (end.y - start.y) / (float)(end.x - start.x);
	else
		line->vertical = 1;
}

/*
 * Three scenarios: 
 * - if the the starting x is smaller than the ending x, then 
 *   the x will advance one by one, and a y value will be calculated for each.
 * - if the starting x is larger than the ending x, then the x
 *   will be reduced one by one, and a y value will be calculated for each.
 * - if the starting x is equal than the ending x, then a vertical line will
 *   be printed (t_line has a parameter named vertical which is 1 in this case).
 */

void	ft_draw_line(t_img img, t_coord start, t_coord end, t_dim max_dims)
{
	t_line		line;
	int			tmp_y;

	ft_init_line(&line, start, end);
	tmp_y = start.y;
	line.coord.x = start.x;
	if (start.x < end.x)
		while (++(line.coord.x) <= end.x)
			ft_fill_and_print(line, &tmp_y, img, max_dims);
	else if (start.x > end.x)
		while (--(line.coord.x) >= end.x)
			ft_fill_and_print(line, &tmp_y, img, max_dims);
	else
		ft_fill_and_print(line, &tmp_y, img, max_dims);
}
