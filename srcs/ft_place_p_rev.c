/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_p_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:07:12 by tluzing           #+#    #+#             */
/*   Updated: 2018/08/14 16:21:54 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	rev_place_piece(t_map_info *info, t_player *me)
{
	while (info->piece_y >= info->p_top_start)
	{
		info->place_ret = (info->y_place - (info->p_bottom_end -
					info->p_top_start + 1) < 0 ? 2 : 0);
		if (info->place_ret == 2)
			return ;
		info->map_x = info->x_place1;
		info->piece_x = info->p_left_start;
		while (info->piece_x <= info->p_right_end)
		{
			info->place_ret = (info->x_place1 + (info->p_right_end -
						info->p_left_start + 1) > info->x_col ? 1 : 0);
			if (info->place_ret == 1)
				return ;
			if (info->piece[info->piece_y][info->piece_x] != '.')
				info->tmp_map[info->map_y][info->map_x] = me->letter;
			info->place_coord_x = info->x_place1 - info->p_left_start;
			info->place_coord_y = info->map_y - info->p_top_start;
			info->map_x++;
			info->piece_x++;
		}
		info->map_y--;
		info->piece_y--;
	}
}

int		rev_movement(t_map_info *info)
{
	if (info->place_ret == 1)
	{
		info->y_place--;
		info->x_place1 = 0;
	}
	else if (info->place_ret == 2)
		return (1);
	else
		info->x_place1++;
	return (0);
}

void	rev_algo2(t_map_info *info, t_player *me)
{
	store_tmp_map(info);
	get_shape_count(info);
	piece_start(info);
	rev_place_piece(info, me);
	letter_count(info);
	get_tmp_letter(info);
}

void	rev_algo4(t_map_info *info, t_player *me)
{
	rev_algo2(info, me);
	if (!(place_piece_check(info, me)))
	{
		send_coordinate(info);
		info->modulo++;
		info->y_place = info->y_row - 1;
		algo3(info);
	}
	else
	{
		if (!rev_movement(info))
			store_tmp_map(info);
		else
		{
			ft_putendl("0 0");
			return ;
		}
	}
}

void	algorithm1(t_map_info *info, t_player *me)
{
	if (me->letter == 'X')
	{
		if (info->modulo % 2)
			algo4(info, me);
		else
			rev_algo4_1(info, me);
	}
	else
	{
		if (info->modulo % 2)
			rev_algo4(info, me);
		else
			algo4_1(info, me);
	}
}
