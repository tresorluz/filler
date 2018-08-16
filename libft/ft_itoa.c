/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:05:08 by tluzing           #+#    #+#             */
/*   Updated: 2018/06/06 15:28:21 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	int				len_nbr;
	size_t			i;

	len_nbr = n;
	i = 1;
	while (len_nbr /= 10)
		i++;
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		i++;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[--i] = nbr % 10 + '0';
	while (nbr /= 10)
		str[--i] = nbr % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
