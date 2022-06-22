/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:23:10 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/22 13:03:15 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_BONUS_H
# define HOOKS_BONUS_H

# include "graphics_bonus.h"

# define LINUX_ESC_KEY 65307
# define MAC_ESC_KEY 53

# define LINUX_UP_KEY 119
# define LINUX_LEFT_KEY 97
# define LINUX_RIGHT_KEY 100
# define LINUX_DOWN_KEY 115
# define MAC_UP_KEY 13
# define MAC_LEFT_KEY 0
# define MAC_RIGHT_KEY 2
# define MAC_DOWN_KEY 1

void	ft_loop_hooks(t_vars *vars);

#endif
