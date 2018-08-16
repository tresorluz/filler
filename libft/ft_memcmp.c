/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:17:57 by tluzing           #+#    #+#             */
/*   Updated: 2018/06/02 15:09:17 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *dest;
	unsigned char *src;

	dest = (unsigned char*)s1;
	src = (unsigned char*)s2;
	while (n > 0)
	{
		if (*dest != *src)
			return (*dest - *src);
		dest++;
		src++;
		n--;
	}
	return (0);
}
