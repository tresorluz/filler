/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:49:14 by tluzing           #+#    #+#             */
/*   Updated: 2018/05/31 15:45:37 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t i;
	size_t j;

	i = 0;
	if (*str2 == '\0')
		return ((char*)str1);
	while (str1[i] != '\0')
	{
		j = 0;
		while (str2[j] == str1[i + j])
		{
			if (str2[j + 1] == '\0')
				return ((char*)str1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
