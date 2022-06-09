/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:26:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/09 10:53:55 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include <fcntl.h>
# include "libft.h"

typedef struct s_coord
{
	int					x;
	int					y;
	int					z;
}						*t_coord;

void	ft_parse_map(char *map_path, t_coord *coord, unsigned int *map_size);
void	ft_create_list(t_coord *coord, t_list **lst, unsigned int *map_size);
#endif
