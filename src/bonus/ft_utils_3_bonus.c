/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:12:34 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/27 08:39:17 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_bonus.h"
#include <stdlib.h>

void	ft_free_all(t_map_data *map_data)
{
	free(map_data->coord);
	free(map_data->tr_coord);
}
