/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:06:44 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/11 12:26:52 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALE_COORD_H
# define SCALE_COORD_H

# include "parse_map.h"
# include "graphics.h"

typedef struct s_dim
{
	unsigned int	width;
	unsigned int	height;
	int				min_elevation;
	int				max_elevation;
}					t_dim;

typedef struct s_lim_dim
{
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;
}		t_lim_dim;

typedef struct s_angles
{
	float	horizontal_rotation;
	float	vertical_rotation;
}			t_angles;			

void	ft_scale_and_center(t_coord *coord, t_screen screen, unsigned int size);

#endif
