/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:58:01 by tluzing           #+#    #+#             */
/*   Updated: 2018/06/04 16:13:18 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s)
	{
		i = 0;
		if (!(new = (char *)malloc(sizeof(*s) * (len + 1))))
			return (NULL);
		while (s[start] && len > 0)
		{
			new[i] = s[start];
			i++;
			start++;
			len--;
			new[i] = '\0';
		}
		return (new);
	}
	return (NULL);
}
