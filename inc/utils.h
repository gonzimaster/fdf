/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:28:57 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/20 12:17:30 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "graphics.h"
# include "colors.h"

/* ft_utils_1.c */

void	ft_free_two_dims(char **twod_arr);
void	ft_allocate_coord(t_coord **coord, t_size size);
void	terminate(char *s);
double	ft_degree_to_rad(float degrees);
int		ft_pixel_in_screen(int x, int y, t_screen screen);

/* ft_utils_2.c */

void	ft_init_gradient(t_grad *gradient, unsigned int altitude);
void	ft_init_map_data(t_map_data *map_data);
void	ft_init_mlx(t_vars *vars, t_data *img, t_screen *screen,
			t_map_data *map_data);
#endif
