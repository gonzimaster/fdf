/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:26:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/09 09:26:04 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include <fcntl.h>

typedef struct s_coord
{
	int					x;
	int					y;
	int					z;
}						t_coord[100000];

void	ft_parse_map(char *map_path);
#endif
