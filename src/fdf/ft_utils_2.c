/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:56:12 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/18 10:05:25 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

void	ft_init_gradient(t_grad *gradient, unsigned int altitude)
{
	gradient->start = 0xC6FFDD;
	gradient->end = 0xF7797D;
	gradient->steps = altitude;
}
