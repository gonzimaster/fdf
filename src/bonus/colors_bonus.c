/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:46:05 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/21 12:04:03 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

static unsigned int	ft_rgb_to_hex(t_rgb rgb)
{
	return (((rgb.r & 0xFF) << 16) + ((rgb.g & 0xFF) << 8) + (rgb.b & 0xFF));
}

static t_rgb	ft_hex_to_rgb(unsigned int hex)
{
	t_rgb	rgb;

	rgb.r = (hex >> 16) & 0xFF;
	rgb.g = (hex >> 8) & 0xFF;
	rgb.b = hex & 0xFF;
	return (rgb);
}

static void	ft_get_step_size(t_step_size *step_size, unsigned int steps,
			t_rgb start, t_rgb end)
{
	step_size->r = (end.r - start.r) / (float)steps;
	step_size->g = (end.g - start.g) / (float)steps;
	step_size->b = (end.b - start.b) / (float)steps;
}

/*
 * The RGB values of the start and end of the gradient are computed and used
 * to compute the step size for each color. Then the variable scale is computed.
 * For example, if z = 3, altitude = 12, steps = 6 -> scale = 1.5. Therefore
 * it gives a position in the gradient (1.5 out of 6), 0 would be the starting
 * color and 6 the ending color. The RGB values for z are calculated using the
 * corresponding step sizes for each color and the computed scale.
 */

unsigned int	ft_get_color(int z, unsigned int altitude, t_grad gradient)
{
	t_color			color;
	t_step_size		step_size;
	float			scale;
	unsigned int	hex_color;

	color.rgb_start = ft_hex_to_rgb(gradient.start);
	color.rgb_end = ft_hex_to_rgb(gradient.end);
	ft_get_step_size(&step_size, gradient.steps, color.rgb_start,
		color.rgb_end);
	if (altitude)
		scale = (z / (float)altitude) * gradient.steps;
	else
		scale = 0.0;
	color.rgb_z.r = color.rgb_start.r + step_size.r * scale;
	color.rgb_z.g = color.rgb_start.g + step_size.g * scale;
	color.rgb_z.b = color.rgb_start.b + step_size.b * scale;
	hex_color = ft_rgb_to_hex(color.rgb_z);
	return (hex_color);
}
