/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:56:12 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/18 11:56:54 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "graphics.h"

void	ft_init_gradient(t_grad *gradient, unsigned int altitude)
{
	gradient->start = 0xC6FFDD;
	gradient->end = 0xF7797D;
	gradient->steps = altitude;
}

void	ft_init_map_data(t_map_data *map_data)
{
	map_data->size.line = 0;
	map_data->size.map = 0;
	map_data->coord = NULL;
}
