/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:59:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/07 19:23:07 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_message.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}
/*
t_coord_list	*ft_lstnew_coord(int x, int y, int z)
{
	t_coord_list	*new_node;

	new_node = malloc(sizeof(t_coord_list));
	if (!new_node)
		terminate(ERR_MEM);
	new_node->x = x;
	new_node->y = y;
	new_node->z = z;
	new_node->next = NULL;
}
*/
void	ft_free_two_dims(char	**twod_arr)
{
	int	i;

	i = 0;
	while (twod_arr[i])
	{
		free(twod_arr[i]);
		i++;
	}
	free(twod_arr);
}
