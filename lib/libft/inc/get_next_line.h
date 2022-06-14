/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:14:14 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 20:15:03 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

/* get_next_line.c */

char			*get_next_line(int fd);

/* get_next_line_utils.c */

void			ft_append(char *line, char c);
void			*ft_my_realloc(void *ptr, size_t original_size,
					size_t new_size);
#endif
