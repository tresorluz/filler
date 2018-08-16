/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:31:29 by tluzing           #+#    #+#             */
/*   Updated: 2018/05/31 12:32:41 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*j;
	char	*k;

	i = 0;
	j = (char*)dest;
	k = (char*)src;
	while (i < n)
	{
		j[i] = k[i];
		if (j[i] == (char)c)
			return (j + i + 1);
		i++;
	}
	return (NULL);
}
