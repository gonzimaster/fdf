/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:26:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/21 16:21:13 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_BONUS_H
# define PARSE_MAP_BONUS_H

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

void	ft_parse_map(char *map_path, t_size *size, t_coord *coord,
			int read_flag);
#endif