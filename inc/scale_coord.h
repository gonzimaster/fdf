/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:06:44 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/17 08:56:48 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALE_COORD_H
# define SCALE_COORD_H

# include "parse_map.h"
# include "graphics.h"

typedef struct s_lim
{
	int	min;
	int	max;
}		t_lim;

typedef struct s_dim
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	altitude;
	t_lim			x;
	t_lim			y;
	t_lim			z;
}					t_dim;

typedef struct s_coord_2d
{
	float	x;
	float	y;
}			t_coord_2d;			

/* scale_coord_1.c */

void	ft_to_projection(t_coord *coord, t_screen screen, unsigned int size);
float	ft_scale_to_fit(t_dim max_dims, t_screen screen, float occ_screen);

/* scale_coord_2.c */

void	ft_initialize_dim(t_dim *dim, t_coord *coord);
void	ft_initialize_view(t_dim max_dims, t_screen screen, t_view *view);

#endif
