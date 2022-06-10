/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:04:50 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/10 15:43:32 by ogonzale         ###   ########.fr       */
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

static void	ft_print_image(t_data *img, t_coord *coord, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		my_mlx_pixel_put(img, coord[i].x, coord[i].y, 0xFFFFFF);
		i++;
	}
}

void	ft_handle_graphics(t_coord *coord, unsigned int map_size)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	ft_scale_and_center(coord, map_size);
	ft_print_image(&img, coord, map_size);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}	
