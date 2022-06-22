/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:06:44 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/22 15:38:14 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALE_COORD_BONUS_H
# define SCALE_COORD_BONUS_H

# include "graphics_bonus.h"

/* scale_coord_1.c */

void	ft_to_isometric(t_map_data map_data, t_screen screen, t_view view);
void	ft_to_projection(t_vars *vars);
float	ft_scale_to_fit(t_dim max_dims, t_screen screen, float occ_screen);

/* scale_coord_2.c */

void	ft_initialize_dim(t_dim *dim, t_coord *coord);
void	ft_initialize_view(t_dim max_dims, t_screen screen, t_view *view);

#endif
