/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:59:50 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/16 14:07:53 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "parse_map.h"
#include "graphics.h"
#include "scale_coord.h"
#include "line.h"
#include "utils.h"

static void	ft_fill_and_print(t_coord_2d coord, t_line line, int *tmp_y,
				t_img img)
{
	coord.y = (int)(line.slope * (coord.x - line.start.x) + line.start.y);
	if (line.start.y < line.end.y)
	{
		while (*tmp_y < coord.y)
		{
			if (ft_pixel_in_screen(coord.x, *tmp_y, img.screen))
				my_mlx_pixel_put(img.img_data, coord.x, *tmp_y, 0xFFFF00);
			(*tmp_y)++;
		}
	}
	else
	{
		while (*tmp_y > coord.y)
		{
			if (ft_pixel_in_screen(coord.x, *tmp_y, img.screen))
				my_mlx_pixel_put(img.img_data, coord.x, *tmp_y, 0xFFFF00);
			(*tmp_y)--;
		}
	}
	if (ft_pixel_in_screen(coord.x, coord.y, img.screen))
		my_mlx_pixel_put(img.img_data, coord.x, coord.y, 0xFFFF00);
	*tmp_y = coord.y;
}	

static void	ft_init_line(t_line *line, t_coord start, t_coord end)
{
	line->start = start;
	line->end = end;
	line->slope = (end.y - start.y) / (float)(end.x - start.x);
}

static void	ft_init_img(t_img *img, t_screen screen, t_data *img_data)
{
	img->screen = screen;
	img->img_data = img_data;
}

void	ft_draw_line(t_data *img_data, t_coord start, t_coord end,
			t_screen screen)
{
	t_coord_2d	coord;
	t_line		line;
	t_img		img;
	int			tmp_y;

	ft_init_line(&line, start, end);
	ft_init_img(&img, screen, img_data);
	tmp_y = start.y;
	if (start.x < end.x)
	{
		coord.x = start.x;
		while (++(coord.x) <= end.x)
			ft_fill_and_print(coord, line, &tmp_y, img);
	}
	else
	{
		coord.x = start.x;
		while (--(coord.x) >= end.x)
			ft_fill_and_print(coord, line, &tmp_y, img);
	}
}
