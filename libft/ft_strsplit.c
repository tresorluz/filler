/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:02:50 by tluzing           #+#    #+#             */
/*   Updated: 2018/06/05 13:43:42 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static	char	*word_len(const char *s, char c)
{
	size_t	len;
	char	*word;
	int		i;

	i = 0;
	len = ft_strlen(s);
	if (!(word = (char*)malloc(len + 1)))
		return (NULL);
	while (*s && *s != c)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_words;
	int		i;

	if (!s)
		return (NULL);
	nb_words = word_count(s, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * (nb_words + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			tab[i] = word_len(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
