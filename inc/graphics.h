/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:19:57 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/16 13:01:30 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "parse_map.h"

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
}			t_view;

void	ft_handle_graphics(t_coord *coord, t_size size);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
#endif
