/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:16:02 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/24 12:32:56 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_BONUS_H
# define LINE_BONUS_H

# include "graphics_bonus.h"

typedef struct s_line
{
	t_coord		start;
	t_coord		end;
	t_coord_2d	coord;
	float		slope;
	int			vertical;

}				t_line;

typedef struct s_img
{
	t_data		*img_data;
	t_screen	screen;
}				t_img;

typedef struct s_line_param
{
	float			line_length;
	float			dist_to_end;
	float			line_pos;
	int				z;
}			t_line_param;

/* line_1.c */

void	ft_draw_line(t_img img, t_coord start, t_coord end, t_dim max_dims);
void	ft_put_printable_pixel(t_coord_2d coord, int *tmp_y, t_img img,
			unsigned int color);

/* line_2.c */

void	ft_fill_upwards(t_coord_2d coord, int *tmp_y, t_img img,
			unsigned int color);
void	ft_fill_downwards(t_coord_2d coord, int *tmp_y, t_img img,
			unsigned int color);
#endif
