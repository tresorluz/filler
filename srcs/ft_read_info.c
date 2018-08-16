/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 09:27:19 by tluzing           #+#    #+#             */
/*   Updated: 2018/08/14 16:22:06 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	player_id(t_player *player)
{
	char	*line;

	get_next_line(0, &line);
	if ((!(ft_strncmp(line, "$$$ exec p", 10))))
	{
		if (line[10] == '1')
		{
			player->player_nbr = '1';
			player->letter = 'O';
			player->current_letter = 'o';
		}
		else
		{
			player->player_nbr = '2';
			player->letter = 'X';
			player->current_letter = 'x';
		}
		ft_strdel(&line);
		return ;
	}
	return ;
}

void	map_size(t_map_info *map)
{
	char	*line;
	char	*x_axis;
	char	*y_axis;

	get_next_line(0, &line);
	while (ft_strncmp(line, "Plateau ", 8)                       )
		get_next_line(0, &line);
	if (!(ft_strncmp(line, "Plateau ", 8)))
	{
		y_axis = ft_strchr(line, ' ');
		map->y_row = ft_atoi(y_axis);
		map->y_place = map->y_row - 1;
		map->y_place1 = 0;
		y_axis++;
		x_axis = ft_strchr(y_axis, ' ');
		map->x_col = ft_atoi(x_axis);
		map->x_place = map->x_col - 1;
		free(line);
		return ;
	}
}

void	get_map(t_map_info *info)
{
	char	**map;
	char	*begin;
	int		i;
	int		x;

	i = 0;
	info->map = (char**)malloc(sizeof(*map) * info->y_row);
	get_next_line(0, &begin);
	while (ft_strncmp(begin, "000 ", 4))
		get_next_line(0, &begin);
	while (i < (info->y_row))
	{
		x = 0;
		info->map[i] = (char *)malloc(sizeof(char) * info->x_col + 1);
		while (x < info->x_col)
		{
			info->map[i][x] = begin[x + 4];
			x++;
		}
		info->map[i][x] = '\0';
		if (i < (info->y_row - 1))
			get_next_line(0, &begin);
		i++;
	}
}

void	get_piece(t_map_info *info)
{
	char	**piece;
	char	*start;
	int		i;
	int		x;

	i = 0;
	if (!(info->piece = (char**)malloc(sizeof(*piece) * info->y_pce)))
		return ;
	get_next_line(0, &start);
	while (ft_strncmp(start, ".", 1) && ft_strncmp(start, "*", 1))
		get_next_line(0, &start);
	while (i < (info->y_pce))
	{
		x = 0;
		info->piece[i] = (char *)malloc(sizeof(char) * info->x_pce + 1);
		while (x < info->x_pce)
		{
			info->piece[i][x] = start[x];
			x++;
		}
		info->piece[i][x] = '\0';
		if (i < (info->y_pce - 1))
			get_next_line(0, &start);
		i++;
	}
}

void	get_piece_size(t_map_info *piece)
{
	char	*line;
	char	*x_axis;
	char	*y_axis;

	get_next_line(0, &line);
	while (ft_strncmp(line, "Piece ", 6))
		get_next_line(0, &line);
	if (!(ft_strncmp(line, "Piece ", 6)))
	{
		y_axis = ft_strchr(line, ' ');
		piece->y_pce = ft_atoi(y_axis);
		y_axis++;
		x_axis = ft_strchr(y_axis, ' ');
		piece->x_pce = ft_atoi(x_axis);
		free(line);
		return ;
	}
}
