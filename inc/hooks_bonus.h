/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:23:10 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/22 16:48:01 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_BONUS_H
# define HOOKS_BONUS_H

# include "graphics_bonus.h"

# define LINUX_ESC_KEY 65307
# define MAC_ESC_KEY 53

# define LINUX_W_KEY 119
# define LINUX_A_KEY 97
# define LINUX_S_KEY 115
# define LINUX_D_KEY 100
# define MAC_W_KEY 13
# define MAC_A_KEY 0
# define MAC_S_KEY 1
# define MAC_D_KEY 2

# define MAC_ZOOM_IN_KEY 5
# define MAC_ZOOM_OUT_KEY 4

# define MAC_UP_KEY 126
# define MAC_RIGHT_KEY 124
# define MAC_LEFT_KEY 123
# define MAC_DOWN_KEY 125

void	ft_loop_hooks(t_vars *vars);

#endif
