/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:06:44 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/17 15:14:02 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALE_COORD_H
# define SCALE_COORD_H

# include "parse_map.h"
# include "graphics.h"

/* scale_coord_1.c */

void	ft_to_projection(t_map_data *map_data, t_screen screen);
float	ft_scale_to_fit(t_dim max_dims, t_screen screen, float occ_screen);

/* scale_coord_2.c */

void	ft_initialize_dim(t_dim *dim, t_coord *coord);
void	ft_initialize_view(t_dim max_dims, t_screen screen, t_view *view);

#endif
