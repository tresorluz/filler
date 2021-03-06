/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:01:55 by tluzing           #+#    #+#             */
/*   Updated: 2018/05/30 14:48:03 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		while (*s1 != '\0' && n > 0)
		{
			if (*s1++ != *s2++)
				return (0);
			n--;
		}
		if (*s1-- == *s2--)
			return (1);
		if (*s1++ == *s2++)
			return (1);
		else
			return (0);
	}
	return (0);
}
