/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:36:48 by tluzing           #+#    #+#             */
/*   Updated: 2018/06/01 17:39:31 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = ((char)c);
	while (*str != ch)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char*)str);
}
