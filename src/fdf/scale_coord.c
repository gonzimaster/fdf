/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:04:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/09 19:19:40 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scale_coord.h"
#include "parse_map.h"
#include "libft.h"
#include <stdio.h>

static t_dim	ft_get_max_dims(t_coord *coord, unsigned int size)
{
	unsigned int	i;
	t_dim			max_dims;
	t_coord			tmp;

	tmp = *coord;
	i = 0;
	max_dims.width = 0;
	max_dims.height = 0;
	max_dims.min_elevation = 0;
	max_dims.max_elevation = 0;
	while (i < size)
	{
		if (ft_abs_value(tmp[i].x) > max_dims.width)
			max_dims.width = tmp[i].x;
		if (ft_abs_value(tmp[i].y) > max_dims.height)
			max_dims.height = tmp[i].y;
		if (tmp[i].z < max_dims.min_elevation)
			max_dims.min_elevation = tmp[i].z;
		if (tmp[i].z > max_dims.max_elevation)
			max_dims.max_elevation = tmp[i].z;
		i++;
	}
	return (max_dims);
}

void	ft_scale_and_center(t_coord *coord, unsigned int size)
{
	unsigned int	i;
	t_dim			max_dims;
	t_coord			tmp;

	tmp = *coord;
	max_dims = ft_get_max_dims(coord, size);
	printf("%d, %d, %d, %d\n", max_dims.width, max_dims.height,
				max_dims.min_elevation, max_dims.max_elevation);
}
