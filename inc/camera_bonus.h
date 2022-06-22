/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:48:14 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/22 16:53:50 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_BONUS_H
# define CAMERA_BONUS_H

#include "graphics_bonus.h"

/* translate_bonus.c */

void	ft_translate_and_put(t_vars *vars, int key);
void	ft_rotate_and_put(t_vars *vars, int key);

/* image_bonus.c */

void	ft_clear_image(t_vars *vars);

#endif
