/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:59:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/21 16:31:09 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_message_bonus.h"
#include "utils_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

/*
 * If there is no error code given by errno, add error message to stdout 2.
 * If there is an error code, the custom error message is printed, followed by 
 * and error message corresponding to the current value of errno.
 */

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void	ft_allocate_coord(t_map_data *map_data)
{
	map_data->coord = malloc(sizeof(t_coord) * map_data->size.map);
	if (!map_data->coord)
		terminate(ERR_MEM);
	map_data->tr_coord = malloc(sizeof(t_coord) * map_data->size.map);
	if (!map_data->tr_coord)
		terminate(ERR_MEM);
}

double	ft_degree_to_rad(float degrees)
{
	double	radians;

	radians = degrees * (M_PI / 180.0);
	return (radians);
}

int	ft_pixel_in_screen(int x, int y, t_screen screen)
{
	if (x >= 0 && x < screen.width && y >= 0 && y < screen.height)
		return (1);
	return (0);
}

void	ft_free_two_dims(char **twod_arr)
{
	int	i;

	i = 0;
	while (twod_arr[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(twod_arr[i]);
		twod_arr[i] = NULL;
		i--;
	}
	free(twod_arr);
	twod_arr = NULL;
}
