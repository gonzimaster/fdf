/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:53:37 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/24 12:03:31 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_bonus.h"
#include "mlx.h"

void	ft_clear_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	vars->img->img = mlx_new_image(vars->mlx, vars->screen.width,
			vars->screen.height);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->line_length,
			&vars->img->endian);
}
