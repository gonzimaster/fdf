/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:17:00 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/24 12:20:08 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_bonus.h"

void	ft_fill_upwards(t_coord_2d coord, int *tmp_y, t_img img,
			unsigned int color)
{
	while (*tmp_y < coord.y)
	{
		ft_put_printable_pixel(coord, tmp_y, img, color);
		(*tmp_y)++;
	}
}

void	ft_fill_downwards(t_coord_2d coord, int *tmp_y, t_img img,
			unsigned int color)
{
	while (*tmp_y > coord.y)
	{
		ft_put_printable_pixel(coord, tmp_y, img, color);
		(*tmp_y)--;
	}
}
