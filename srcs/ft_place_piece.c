/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:28:08 by tluzing           #+#    #+#             */
/*   Updated: 2018/08/14 16:23:18 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	place_piece1(t_map_info *info, t_player *me)
{
	while (info->piece_y <= info->p_bottom_end)
	{
		info->place_ret = (info->y_place1 + (info->p_bottom_end -
					info->p_top_start + 1) > (info->y_row) ? 2 : 0);
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
			info->place_coord_y = info->y_place1 - info->p_top_start;
			info->map_x--;
			info->piece_x--;
		}
		info->map_y++;
		info->piece_y++;
	}
}

void	piece_start1(t_map_info *info)
{
	info->place_ret = 0;
	info->piece_y = info->p_top_start;
	info->map_y = info->y_place1;
}

int		movement1(t_map_info *info)
{
	if (info->place_ret == 1)
	{
		info->y_place1++;
		info->x_place = info->x_col - 1;
	}
	else if (info->place_ret == 2)
		return (1);
	else
		info->x_place--;
	return (0);
}

void	algo2_1(t_map_info *info, t_player *me)
{
	store_tmp_map(info);
	get_shape_count(info);
	piece_start1(info);
	place_piece1(info, me);
	letter_count(info);
	get_tmp_letter(info);
}

void	algo4_1(t_map_info *info, t_player *me)
{
	algo2_1(info, me);
	if (!(place_piece_check(info, me)))
	{
		send_coordinate(info);
		info->modulo++;
		info->y_place1 = 0;
		algo3(info);
	}
	else
	{
		if (!movement1(info))
			store_tmp_map(info);
		else
		{
			ft_putendl("0 0");
			return ;
		}
	}
}
