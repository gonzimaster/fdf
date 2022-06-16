/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:04:50 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/16 12:59:12 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "graphics.h"
#include "parse_map.h"
#include "libft.h"
#include "error_message.h"
#include "utils.h"
#include "scale_coord.h"
#include "line.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
/*
void	ft_draw_line(t_data *img, t_coord start, t_coord end,
			t_screen screen)
{
	t_coord_2d	coord;
	int			tmp_y;
	float		slope;

	slope = (end.y - start.y) / (float)(end.x - start.x);
	if (start.x < end.x)
	{
		coord.x = start.x + 1;
		tmp_y = start.y;
		while (coord.x <= end.x)
		{
			coord.y = (int)(slope * (coord.x - start.x) + start.y);
			if (start.y < end.y)
			{
				while (tmp_y < coord.y)
				{
					if (ft_pixel_in_screen(coord.x, tmp_y, screen))
						my_mlx_pixel_put(img, coord.x - 1, tmp_y, 0xFFFF00);
					tmp_y++;
				}
			}
			else
			{
				while (tmp_y > coord.y)
				{
					if (ft_pixel_in_screen(coord.x, tmp_y, screen))
						my_mlx_pixel_put(img, coord.x - 1, tmp_y, 0xFFFF00);
					tmp_y--;
				}

			}
			if (ft_pixel_in_screen(coord.x, coord.y, screen))
				my_mlx_pixel_put(img, coord.x, coord.y, 0xFF0000);
			tmp_y = coord.y;
			(coord.x)++;
		}
	}
	else
	{
		coord.x = start.x - 1;
		tmp_y = start.y;
		while (coord.x >= end.x)
		{
			coord.y = (int)(slope * (coord.x - start.x) + start.y);
			if (start.y < end.y)
			{
				while (tmp_y < coord.y)
				{
					if (ft_pixel_in_screen(coord.x, tmp_y, screen))
						my_mlx_pixel_put(img, coord.x + 1, tmp_y, 0xFFFF00);
					tmp_y++;
				}
			}
			else
			{
				while (tmp_y > coord.y)
				{
					if (ft_pixel_in_screen(coord.x, tmp_y, screen))
						my_mlx_pixel_put(img, coord.x - 1, tmp_y, 0xFFFF00);
					tmp_y--;
				}

			}
			if (ft_pixel_in_screen(coord.x, coord.y, screen))
				my_mlx_pixel_put(img, coord.x, coord.y, 0xFF0000);
			tmp_y = coord.y;
			(coord.x)--;
		}
	}
}
*/
static void	ft_print_image(t_data *img, t_coord *coord, t_screen screen,
			t_size size)
{
	unsigned int	i;

	i = 0;
	while (i < size.map)
	{
		if ((i + 1) % size.line)
			ft_draw_line(img, coord[i], coord[i + 1], screen);
		if (i + size.line < size.map)
			ft_draw_line(img, coord[i], coord[i + size.line], screen);
		if (ft_pixel_in_screen(coord[i].x, coord[i].y, screen))
			my_mlx_pixel_put(img, coord[i].x, coord[i].y, 0xFFFFFF);
		i++;
	}
}

void	ft_handle_graphics(t_coord *coord, t_size size)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_screen	screen;

	mlx = mlx_init();
	screen.width = 1920;
	screen.height = 1080;
	mlx_win = mlx_new_window(mlx, screen.width, screen.height, "FDF");
	img.img = mlx_new_image(mlx, screen.width, screen.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_scale_and_center(coord, screen, size.map);
	ft_print_image(&img, coord, screen, size);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}	
