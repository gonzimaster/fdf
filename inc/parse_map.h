/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:26:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/14 16:51:42 by ogonzale         ###   ########.fr       */
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
}						t_coord;

typedef struct s_size
{
	unsigned int	line;
	unsigned int	map;
}					t_size;

void	ft_parse_map(char *map_path, t_coord *coord, t_size *size);
#endif
