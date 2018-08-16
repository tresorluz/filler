/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:36:54 by tluzing           #+#    #+#             */
/*   Updated: 2018/05/28 15:00:23 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while ((unsigned char)str1[i] != '\0' && (unsigned char)str2[i] != '\0'
			&& ((unsigned char)str1[i] == (unsigned char)str2[i]))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
