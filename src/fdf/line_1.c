/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:59:50 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/20 12:10:29 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "scale_coord.h"
#include "line.h"
#include "utils.h"
#include "libft.h"
#include <math.h>

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

static void	ft_fill_and_print(t_line line, int *tmp_y, t_img img,
			t_dim max_dims)
{
	unsigned int	color;
	t_grad			gradient;
	t_line_param	line_param;

	ft_init_gradient(&gradient, max_dims.altitude);
	line.coord.y = (int)(line.slope * (line.coord.x - line.start.x)
			+ line.start.y);
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
	line->slope = (end.y - start.y) / (float)(end.x - start.x);
}

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
	else
		while (--(line.coord.x) >= end.x)
			ft_fill_and_print(line, &tmp_y, img, max_dims);
}
