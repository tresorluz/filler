/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:18:06 by tluzing           #+#    #+#             */
/*   Updated: 2018/06/02 14:55:30 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *j;
	unsigned char *k;

	j = (unsigned char *)dest;
	k = (unsigned char *)src;
	while (n > 0)
	{
		*j = *k;
		k++;
		j++;
		n--;
	}
	return (dest);
}
