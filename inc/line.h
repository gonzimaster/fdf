/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:16:02 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/16 12:54:58 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H
# include "mlx.h"
# include "parse_map.h"
# include "graphics.h"
# include "scale_coord.h"

typedef struct s_line
{
	t_coord		start;
	t_coord		end;
	float		slope;

}				t_line;

typedef struct s_img
{
	t_data		*img_data;
	t_screen	screen;
}				t_img;

void	ft_draw_line(t_data *img, t_coord start, t_coord end, t_screen screen);

#endif
