/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:23:10 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/23 11:20:33 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "graphics.h"

# if __APPLE__
# define ESC_KEY 53
# elif __linux__
# define ESC_KEY 65307
# endif

void	ft_loop_hooks(t_vars *vars);

#endif
