/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:04:50 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/22 13:25:08 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "utils_bonus.h"
#include "scale_coord_bonus.h"
#include "hooks_bonus.h"

/*
 * Function that mimics mlx_pixel_put but is many times faster. The address of
 * dst is the address of data plus an offset, which is a function of the current
 * position (x,y), line_lenght and bits_per_pixel.
 */

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
 * A dot (x, y) will be connected to the next dot (x + 1, y) if not at the end
 * of the line.
 * A dot (x, y) will be connected to the next dot (x, y + 1) if not at the last
 * line.
 */

static void	ft_connect_dots(t_img img, t_map_data map_data, unsigned int i)
{
	if ((i + 1) % map_data.size.line)
		ft_draw_line(img, map_data.tr_coord[i], map_data.tr_coord[i + 1],
			map_data.max_dims);
	if (i + map_data.size.line < map_data.size.map)
		ft_draw_line(img, map_data.tr_coord[i],
			map_data.tr_coord[i + map_data.size.line], map_data.max_dims);
}

/*
 * The color gradient is initialized to two hardcoded colors. The number of steps
 * is directly proportional to the altitude.
 * A check is always performed to determine if the pixel is drawable (is inside
 * the viewable screen.
 * The color is calculated as a function of the current z, the altitude and the
 * gradient.
 */

void	ft_print_image(t_data *img_data, t_map_data map_data,
			t_screen screen)
{
	unsigned int	i;
	unsigned int	color;
	t_grad			gradient;
	t_img			img;

	ft_init_gradient(&gradient);
	ft_init_img(&img, screen, img_data);
	i = 0;
	while (i < map_data.size.map)
	{
		ft_connect_dots(img, map_data, i);
		if (ft_pixel_in_screen(map_data.tr_coord[i].x, map_data.tr_coord[i].y,
				screen))
		{
			color = ft_get_color(map_data.tr_coord[i].z
					+ ft_abs_value(map_data.max_dims.z.min),
					map_data.max_dims.altitude, gradient);
			my_mlx_pixel_put(img_data, map_data.tr_coord[i].x, map_data.tr_coord[i].y,
				color);
		}
		i++;
	}
}

void	ft_handle_graphics(t_map_data map_data)
{
	t_vars		vars;
	t_data		img;
	t_screen	screen;

	ft_init_mlx(&vars, &img, &screen, &map_data);
	vars.img = &img;
	vars.screen = screen;
	ft_to_projection(&map_data, screen);
	ft_print_image(&img, map_data, screen);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	ft_loop_hooks(&vars);
}	
