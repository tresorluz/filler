/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:02:47 by tluzing           #+#    #+#             */
/*   Updated: 2018/08/14 15:10:45 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

# include <fcntl.h>

int		find_nl(char **save_buff, char **line);
int		get_next_line(int const fd, char **line);
char	*join(char *s1, char *s2);

#endif
