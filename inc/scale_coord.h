/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:06:44 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/10 17:41:52 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALE_COORD_H
# define SCALE_COORD_H

# include "parse_map.h"

typedef struct		s_dim
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

void	ft_scale_and_center(t_coord *coord, unsigned int size);

#endif
