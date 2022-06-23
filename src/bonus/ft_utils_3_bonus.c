/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:12:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/23 17:17:48 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_bonus.h"
#include <stdlib.h>

void	ft_free_all(t_vars *vars)
{
	free(vars->map_data->coord);
	free(vars->map_data->tr_coord);
}
