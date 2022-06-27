/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:48:14 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/27 09:41:21 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_BONUS_H
# define CAMERA_BONUS_H

# include "graphics_bonus.h"

/* translate_bonus.c */

void	ft_save_trans(t_vars *vars, int key);
void	ft_save_rotation(t_vars *vars, int key);
void	ft_rotate_to_angle(t_vars *vars);
void	ft_translate_to_pos(t_vars *vars);

#endif
