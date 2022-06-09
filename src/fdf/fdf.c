/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:41:52 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/09 11:49:40 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_message.h"
#include "parse_map.h"
#include "utils.h"
#include <stdio.h>

static void	print_list(t_list **lst)
{
	t_list	*current_node;

	current_node = *lst;
	while (current_node)
	{
		printf("(%d %d %d)\n", ((t_coord)current_node->content)->x,
								((t_coord)current_node->content)->y,
								((t_coord)current_node->content)->z);
		current_node = current_node->next;;
	}
}

static void	ft_free_list(t_list **lst)
{
	t_list *tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

static void	ft_allocate_coord(t_coord *coord)
{
	*coord = malloc(sizeof(t_coord));
	if (!(*coord))
		terminate(ERR_MEM);
}

int	main(int argc, char *argv[])
{
	t_coord			coord;
	t_list			*lst;
	unsigned int	map_size;

	if (argc != 2)
		terminate(ERR_ARGS);
	map_size = 0;
	ft_allocate_coord(&coord);
	ft_parse_map(argv[1], &coord, &map_size);
	ft_create_list(&coord, &lst, &map_size);
	print_list(&lst);
	ft_free_list(&lst);
	free(coord);
	return (0);
}
