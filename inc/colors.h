/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:49:01 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/17 10:04:54 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct	s_grad
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

unsigned int	ft_to_hex_color(t_rgb rgb);
