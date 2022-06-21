/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:56:12 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/21 12:04:24 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx.h"
#include "error_message.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_protect_line_split(char ***line_split, int fd, int read_flag,
			t_coord **coord)
{
	ft_free_two_dims(*line_split);
	close(fd);
	if (!read_flag)
		free(*coord);
	terminate(ERR_SPLIT);
}

void	ft_init_gradient(t_grad *gradient)
{
	gradient->start = 0xC6FFDD;
	gradient->end = 0xF7797D;
	gradient->steps = 100;
}

void	ft_init_map_data(t_map_data *map_data)
{
	map_data->size.line = 0;
	map_data->size.map = 0;
	map_data->coord = NULL;
}

void	ft_init_img(t_img *img, t_screen screen, t_data *img_data)
{
	img->screen = screen;
	img->img_data = img_data;
}

void	ft_init_mlx(t_vars *vars, t_data *img, t_screen *screen,
				t_map_data *map_data)
{
	vars->mlx = mlx_init();
	vars->map_data = map_data;
	screen->width = 1920;
	screen->height = 1080;
	vars->win = mlx_new_window(vars->mlx, screen->width, screen->height,
			"FDF");
	img->img = mlx_new_image(vars->mlx, screen->width, screen->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}
