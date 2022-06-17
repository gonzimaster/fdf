/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:59:50 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/17 18:36:59 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "parse_map.h"
#include "graphics.h"
#include "scale_coord.h"
#include "line.h"
#include "utils.h"
#include "colors.h"
#include <stdio.h>
#include <math.h>

static void	ft_fill_and_print(t_coord_2d coord, t_line line, int *tmp_y,
				t_img img, t_dim max_dims)
{
	unsigned int	color;
	t_grad			gradient;
	float			line_length;
	float			dist_to_end;
	float			line_pos;
	int				z;

	gradient.start = 0xC6FFDD;
	gradient.end = 0xF7797D;
	gradient.steps = 100;
	coord.y = (int)(line.slope * (coord.x - line.start.x) + line.start.y);
	line_length = sqrt(pow(line.end.x - line.start.x, 2)
			+ pow(line.end.y - line.start.y, 2));
	dist_to_end = sqrt(pow(line.end.x - coord.x, 2)
			+ pow(line.end.y - coord.y, 2));
	line_pos = (line_length - dist_to_end) / line_length;
	z = line.start.z + (int)((line.end.z - line.start.z) * line_pos)
		+ abs(max_dims.z.min);
	color = ft_get_color(z, max_dims.altitude, gradient);
	if (line.start.y < line.end.y)
	{
		while (*tmp_y < coord.y)
		{
			if (ft_pixel_in_screen(coord.x, *tmp_y, img.screen))
				my_mlx_pixel_put(img.img_data, coord.x, *tmp_y, color);
			(*tmp_y)++;
		}
	}
	else
	{
		while (*tmp_y > coord.y)
		{
			if (ft_pixel_in_screen(coord.x, *tmp_y, img.screen))
				my_mlx_pixel_put(img.img_data, coord.x, *tmp_y, color);
			(*tmp_y)--;
		}
	}
	if (ft_pixel_in_screen(coord.x, coord.y, img.screen))
		my_mlx_pixel_put(img.img_data, coord.x, coord.y, color);
	*tmp_y = coord.y;
}	

static void	ft_init_line(t_line *line, t_coord start, t_coord end)
{
	line->start = start;
	line->end = end;
	line->slope = (end.y - start.y) / (float)(end.x - start.x);
}

void	ft_draw_line(t_img img, t_coord start, t_coord end, t_dim max_dims)
{
	t_coord_2d	coord;
	t_line		line;
	int			tmp_y;

	ft_init_line(&line, start, end);
	tmp_y = start.y;
	if (start.x < end.x)
	{
		coord.x = start.x;
		while (++(coord.x) <= end.x)
			ft_fill_and_print(coord, line, &tmp_y, img, max_dims);
	}
	else
	{
		coord.x = start.x;
		while (--(coord.x) >= end.x)
			ft_fill_and_print(coord, line, &tmp_y, img, max_dims);
	}
}
