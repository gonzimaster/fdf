/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:28:57 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/18 10:00:34 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "parse_map.h"
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
#endif
