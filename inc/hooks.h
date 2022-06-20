/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:23:10 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/20 11:45:10 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "graphics.h"

# define LINUX_ESC 65307 

int		ft_key_router(int key, t_vars *vars);
void	ft_loop_hooks(t_vars *vars);

#endif
