/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:03:45 by tluzing           #+#    #+#             */
/*   Updated: 2018/06/05 15:38:15 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		new[i] = (*f)(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
