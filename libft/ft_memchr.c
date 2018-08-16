/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:45:12 by tluzing           #+#    #+#             */
/*   Updated: 2018/05/29 15:12:31 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*j;
	size_t	i;

	i = 0;
	j = (char*)str;
	while (n > 0)
	{
		if (j[i] == (char)c)
			return ((char*)(j + i));
		n--;
		i++;
	}
	return (NULL);
}
