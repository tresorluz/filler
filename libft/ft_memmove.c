/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:08:32 by tluzing           #+#    #+#             */
/*   Updated: 2018/05/30 16:13:31 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *j;
	char *k;

	j = (char*)dest;
	k = (char*)src;
	if (j < k)
		return (ft_memcpy(dest, src, len));
	if (j > k)
	{
		while (len)
		{
			j[len - 1] = k[len - 1];
			len--;
		}
	}
	return (dest);
}
