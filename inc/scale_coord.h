/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:06:44 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/09 19:16:10 by ogonzale         ###   ########.fr       */
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

void	ft_scale_and_center(t_coord *coord, unsigned int size);

#endif
