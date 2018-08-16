/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 09:55:03 by tluzing           #+#    #+#             */
/*   Updated: 2018/06/01 17:18:50 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	const char	*t;

	i = 0;
	t = NULL;
	while (str[i])
	{
		if (str[i] == c)
			t = str + i;
		i++;
	}
	if (str[i] == c)
		return ((char*)(str + i));
	return ((char*)t);
}
