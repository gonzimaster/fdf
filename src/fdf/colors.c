/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:46:05 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/17 10:16:11 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

unsigned int	ft_rgb_to_hex(t_rgb rgb)
{
	return (((rgb.r & 0xFF) << 16) + ((rgb.g & 0xFF) << 8) + (rgb.b & 0xFF));
}

t_rgb	ft_hex_to_rgb(unsigned int hex)
{
	t_rgb rgb;

	rgb.r = (hex & 0xFF) >> 16;
	rgb.g = (hex & 0xFF) >> 8;
	rgb.b = hex & 0xFF;
	return (rgb);
}

void	ft_get_step_size(t_step_size *step_size, unsigned int steps,
			t_rgb start, t_rgb end)
{
	step_size->r = (end.r - start.r) / (float)steps;
	step_size->g = (end.g - start.g) / (float)steps;
	step_size->b = (end.b - start.b) / (float)steps;
}

unsigned int	ft_get_color(int z, unsigned int altitude, t_grad gradient)
{
	t_rgb 			rgb_start;
	t_rgb 			rgb_end;
	t_rgb			rgb_z;
	t_step_size		step_size;
	float			scale;
	unsigned int	hex_color;
	
	rgb_start = ft_hex_to_rgb(gradient.start);
	rgb_end = ft_hex_to_rgb(gradient.end);
	ft_get_step_size(&step_size, gradient.steps, rgb_start, rgb_end);
	scale = (z / (float)altitude) * gradient.steps;
	rgb_z.r = rgb_start.r + step_size.r * scale;
	rgb_z.g = rgb_start.g + step_size.g * scale;
	rgb_z.b = rgb_start.b + step_size.b * scale;
	hex_color = ft_rgb_to_hex(rgb_z);
	return (hex_color);
}
