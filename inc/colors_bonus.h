/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:49:01 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/21 16:18:45 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_BONUS_H
# define COLORS_BONUS_H

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct s_color
{
	t_rgb	rgb_start;
	t_rgb	rgb_end;
	t_rgb	rgb_z;
}			t_color;

typedef struct s_grad
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	steps;
}					t_grad;

typedef struct s_step_size
{
	float	r;
	float	g;
	float	b;
}			t_step_size;

unsigned int	ft_get_color(int z, unsigned int altitude, t_grad gradient);
#endif
