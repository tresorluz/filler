/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:38:03 by tluzing           #+#    #+#             */
/*   Updated: 2018/08/11 12:19:23 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			sign;
	long long	nbr;

	sign = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n'
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str && ft_isdigit(*str))
	{
		if (nbr == 2147483648 && sign == -1)
			return (-2147483648);
		if (nbr > 2147483647)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * sign);
}
