/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:30:30 by ogonzale          #+#    #+#             */
/*   Updated: 2022/05/16 20:10:52 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Function: ft_append
 * -------------------
 * Appends a signle char to the end of a string and adds the '\0' char. 
 * Memory needs to be allocated accordingly.
 */

void	ft_append(char *s, char c)
{
	unsigned int	len;

	if (!s)
		return ;
	len = 0;
	while (s[len] != '\0')
		len++;
	s[len] = c;
	s[len + 1] = '\0';
}

/*
 * Function: ft_memcpy
 * -------------------
 * Copies n bytes from memory area src to memory area dest. The memory
 * areas must not overlap.
 * Returns a pointer to dest.
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
 * Function: ft_my_realloc
 * --------------------
 * Simplified version of realloc (man realloc).
 */

void	*ft_my_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*ptr_new;

	if (new_size == 0)
	{
		free(ptr);
		return (0);
	}
	else if (!ptr)
		return (malloc(new_size));
	else if (new_size <= original_size)
		return (ptr);
	else
	{
		ptr_new = malloc(new_size);
		if (ptr_new)
		{
			ptr_new = ft_memcpy(ptr_new, ptr, original_size);
			free(ptr);
		}
		return (ptr_new);
	}
}
