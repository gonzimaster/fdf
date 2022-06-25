/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:04:50 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/25 12:05:29 by ogonzale         ###   ########.fr       */
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

static void	ft_connect_dots(t_img img, t_vars *vars, unsigned int i)
{
	if ((i + 1) % vars->map_data->size.line)
		ft_draw_line(img, vars->map_data->tr_coord[i],
			vars->map_data->tr_coord[i + 1], vars);
	if (i + vars->map_data->size.line < vars->map_data->size.map)
		ft_draw_line(img, vars->map_data->tr_coord[i],
			vars->map_data->tr_coord[i + vars->map_data->size.line], vars);
}

/*
 * The color gradient is initialized to two hardcoded colors. The number of steps
 * is directly proportional to the altitude.
 * A check is always performed to determine if the pixel is drawable (is inside
 * the viewable screen.
 * The color is calculated as a function of the current z, the altitude and the
 * gradient.
 */

void	ft_print_image(t_vars *vars)
{
	unsigned int	i;
	unsigned int	color;
	t_grad			gradient;
	t_img			img;

	ft_init_gradient(&gradient);
	ft_init_img(&img, vars->screen, vars->img);
	i = 0;
	while (i < vars->map_data->size.map)
	{
		ft_connect_dots(img, vars, i);
		if (ft_pixel_in_screen(vars->map_data->tr_coord[i].x,
				vars->map_data->tr_coord[i].y, vars->screen))
		{
			color = ft_get_color(vars->map_data->tr_coord[i].z
					+ ft_abs_value(vars->map_data->max_dims.z.min),
					vars->map_data->max_dims.altitude * vars->view.z_scale,
					gradient);
			my_mlx_pixel_put(vars->img, vars->map_data->tr_coord[i].x,
				vars->map_data->tr_coord[i].y, color);
		}
		i++;
	}
}

void	ft_print_menu(t_vars *vars)
{
	unsigned int	y;

	y = 0;
	mlx_string_put(vars->mlx, vars->win, 50, y += 50, 0xFFFFFF,
		"Press 'ESC' or click the X to close window");
	mlx_string_put(vars->mlx, vars->win, 50, y += 50, 0xFFFFFF,
		"Translate: use WASD keys");
	mlx_string_put(vars->mlx, vars->win, 50, y += 25, 0xFFFFFF,
		"Rotate: use left and right arrows");
	mlx_string_put(vars->mlx, vars->win, 50, y += 25, 0xFFFFFF,
		"Modify the camera viewing angle: use up and down arrows");
	mlx_string_put(vars->mlx, vars->win, 50, y += 25, 0xFFFFFF,
		"Change z scale: press X to increase and Z to decrease");
	mlx_string_put(vars->mlx, vars->win, 50, y += 40, 0xFFFFFF,
		"Zoom in and out: use the mouse scroll wheel");
	mlx_string_put(vars->mlx, vars->win, 50, y += 40, 0xFFFFFF,
		"Change to side view projection: press P");
	mlx_string_put(vars->mlx, vars->win, 50, y += 25, 0xFFFFFF,
		"Reset to original parameters: press R or I");
}

void	ft_handle_graphics(t_map_data map_data)
{
	t_vars		vars;
	t_data		img;
	t_screen	screen;

	ft_init_mlx(&vars, &img, &screen, &map_data);
	vars.img = &img;
	vars.screen = screen;
	ft_to_projection(&vars);
	ft_print_image(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	ft_print_menu(&vars);
	ft_loop_hooks(&vars);
}	
