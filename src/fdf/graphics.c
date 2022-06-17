/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:04:50 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/17 13:30:33 by ogonzale         ###   ########.fr       */
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
#include "colors.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	ft_print_image(t_data *img, t_map_data map_data, t_screen screen)
{
	unsigned int	i;
	unsigned int	color;
	t_grad			gradient;

	gradient.start = 0xF9FCFC;
	gradient.end = 0x43F6FF;
	i = 0;
	while (i < map_data.size.map)
	{
		if ((i + 1) % map_data.size.line)
			ft_draw_line(img, map_data.coord[i], map_data.coord[i + 1], screen);
		if (i + map_data.size.line < map_data.size.map)
			ft_draw_line(img, map_data.coord[i], map_data.coord[i + map_data.size.line], screen);
		if (ft_pixel_in_screen(map_data.coord[i].x, map_data.coord[i].y, screen))
		{
			color = ft_get_color(20, 50, gradient);
			my_mlx_pixel_put(img, map_data.coord[i].x, map_data.coord[i].y, 0xFFFFFF);
		}
		i++;
	}
}

void	ft_handle_graphics(t_map_data map_data)
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
	ft_to_projection(map_data, screen);
	ft_print_image(&img, map_data, screen);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}	
