/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:24:46 by tluzing           #+#    #+#             */
/*   Updated: 2018/08/14 16:21:39 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	place_piece(t_map_info *info, t_player *me)
{
	while (info->piece_y >= info->p_top_start)
	{
		info->place_ret = (info->y_place -
				(info->p_bottom_end - info->p_top_start) < 0 ? 2 : 0);
		if (info->place_ret == 2)
			return ;
		info->map_x = info->x_place;
		info->piece_x = info->p_right_end;
		while (info->piece_x >= info->p_left_start)
		{
			if (info->x_place - (info->p_right_end - info->p_left_start) < 0)
			{
				info->place_ret = 1;
				return ;
			}
			if (info->piece[info->piece_y][info->piece_x] != '.')
				info->tmp_map[info->map_y][info->map_x] = me->letter;
			info->place_coord_x = info->map_x - info->p_left_start;
			info->place_coord_y = info->map_y - info->p_top_start;
			info->map_x--;
			info->piece_x--;
		}
		info->map_y--;
		info->piece_y--;
	}
}

void	piece_start(t_map_info *info)
{
	info->place_ret = 0;
	info->piece_y = info->p_bottom_end;
	info->map_y = info->y_place;
}

void	get_shape_count(t_map_info *p_info)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < p_info->y_pce)
	{
		x = 0;
		while (x < p_info->x_pce)
		{
			if (p_info->piece[y][x] == '*')
				count++;
			x++;
		}
		y++;
	}
	p_info->add_num = count;
}

void	letter_count(t_map_info *p_info)
{
	int	x;
	int	y;
	int	o_count;
	int	x_count;

	y = 0;
	o_count = 0;
	x_count = 0;
	while (y < p_info->y_row)
	{
		x = 0;
		while (x < p_info->x_col)
		{
			if (p_info->map[y][x] == 'O' || p_info->map[y][x] == 'o')
				o_count++;
			else if (p_info->map[y][x] == 'X' || p_info->map[y][x] == 'x')
				x_count++;
			x++;
		}
		y++;
	}
	p_info->os_num = o_count;
	p_info->xs_num = x_count;
}

void	get_tmp_letter(t_map_info *p_info)
{
	int x;
	int y;
	int o_count;
	int x_count;

	y = 0;
	o_count = 0;
	x_count = 0;
	while (y < p_info->y_row)
	{
		x = 0;
		while (x < p_info->x_col)
		{
			if (p_info->tmp_map[y][x] == 'O' || p_info->tmp_map[y][x] == 'o')
				o_count++;
			else if (p_info->tmp_map[y][x] == 'X' ||
					p_info->tmp_map[y][x] == 'x')
				x_count++;
			x++;
		}
		y++;
	}
	p_info->tmp_os = o_count;
	p_info->tmp_xs = x_count;
}
