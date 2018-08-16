/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:04:16 by tluzing           #+#    #+#             */
/*   Updated: 2018/06/04 16:25:11 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*new;

	if (s)
	{
		start = 0;
		end = ft_strlen((char *)(s)) - 1;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		if ((end - start) <= 0)
			return (ft_strdup(""));
		if (!(new = (char*)malloc(sizeof(*new) * ((end - start) + 2))))
			return (NULL);
		i = 0;
		while (start <= end)
			new[i++] = s[start++];
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
