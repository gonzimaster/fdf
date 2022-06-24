/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:23:10 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/24 19:09:40 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_BONUS_H
# define HOOKS_BONUS_H

# include "graphics_bonus.h"

# if __APPLE__
#  define ESC_KEY 53

#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2

#  define Z_KEY 6
#  define X_KEY 7

#  define ZOOM_IN_KEY 5
#  define ZOOM_OUT_KEY 4

#  define UP_KEY 126
#  define RIGHT_KEY 124
#  define LEFT_KEY 123
#  define DOWN_KEY 125

# elif __linux__
#  define ESC_KEY 65307

#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100

#  define Z_KEY 122
#  define X_KEY 120

#  define ZOOM_IN_KEY 4
#  define ZOOM_OUT_KEY 5

#  define UP_KEY 65362
#  define RIGHT_KEY 65363
#  define LEFT_KEY 65361
#  define DOWN_KEY 65364
# endif

void	ft_loop_hooks(t_vars *vars);

#endif
