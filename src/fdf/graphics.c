/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:04:50 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/11 12:25:41 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "graphics.h"
#include "parse_map.h"
#include "libft.h"
#include "error_message.h"
#include "utils.h"
#include "scale_coord.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	ft_print_image(t_data *img, t_coord *coord, t_screen screen, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (coord[i].x >= 0 && coord[i].x <= screen.width
				&& coord[i].y >= 0 && coord[i].y <= screen.height)
		my_mlx_pixel_put(img, coord[i].x, coord[i].y, 0xFFFFFF);
		i++;
	}
}

void	ft_handle_graphics(t_coord *coord, unsigned int map_size)
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
	ft_scale_and_center(coord, screen, map_size);
	ft_print_image(&img, coord, screen, map_size);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}	
