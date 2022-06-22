/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:19:57 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/22 15:35:37 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_BONUS_H
# define GRAPHICS_BONUS_H

# include "parse_map_bonus.h"

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_screen
{
	int	width;
	int	height;		
}		t_screen;

typedef struct s_view
{
	float	angle;
	float	window_occ;
	float	scale;
	float	z_scale;
}			t_view;

typedef struct s_lim
{
	int	min;
	int	max;
}		t_lim;

typedef struct s_dim
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	altitude;
	t_lim			x;
	t_lim			y;
	t_lim			z;
}					t_dim;

typedef struct s_coord_2d
{
	float	x;
	float	y;
}			t_coord_2d;			

typedef struct s_map_data
{
	t_coord	*coord;
	t_coord	*tr_coord;
	t_size	size;
	t_dim	max_dims;
}			t_map_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map_data	*map_data;
	t_data		*img;
	t_screen	screen;
	t_view		view;
}			t_vars;

void	ft_handle_graphics(t_map_data map_data);
void	ft_print_image(t_data *img_data, t_map_data map_data, t_screen screen);
void	my_mlx_pixel_put(t_data *img, int x, int y, unsigned int color);
#endif
