/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:22:19 by tluzing           #+#    #+#             */
/*   Updated: 2018/05/31 15:16:37 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	k;
	size_t	d_len;

	j = ft_strlen(src) + size;
	k = ft_strlen(src) + ft_strlen(dst);
	if (j <= k)
		return (j);
	j -= k + 1;
	d_len = ft_strlen(dst);
	while (j-- && *src)
		dst[d_len++] = *src++;
	dst[d_len] = '\0';
	return (k);
}
