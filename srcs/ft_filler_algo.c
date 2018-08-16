/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:47:23 by tluzing           #+#    #+#             */
/*   Updated: 2018/08/14 16:22:20 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	initialize_struct(t_map_info *info)
{
	info->x_place = 0;
	info->y_place = 0;
	info->modulo = 0;
	info->place_ret = 0;
	info->add_num = 0;
	info->os_num = 0;
	info->xs_num = 0;
	info->tmp_os = 0;
	info->tmp_xs = 0;
	info->place_coord_x = 0;
	info->place_coord_y = 0;
}

void	algo1(t_map_info *info, t_player *me)
{
	player_id(me);
	map_size(info);
	get_map(info);
	get_piece_size(info);
	get_piece(info);
	trim_piece_map(info);
	store_tmp_map(info);
}

void	algo2(t_map_info *info, t_player *me)
{
	store_tmp_map(info);
	get_shape_count(info);
	piece_start(info);
	place_piece(info, me);
	letter_count(info);
	get_tmp_letter(info);
}

void	algo3(t_map_info *info)
{
	free(info->map);
	get_map(info);
	info->x_pce = 0;
	info->y_pce = 0;
	get_piece_size(info);
	free(info->piece);
	get_piece(info);
	trim_piece_map(info);
}

void	algo4(t_map_info *info, t_player *me)
{
	algo2(info, me);
	if (!(place_piece_check(info, me)))
	{
		send_coordinate(info);
		info->modulo++;
		info->y_place = info->y_row - 1;
		algo3(info);
	}
	else
	{
		if (!piece_movement(info))
			store_tmp_map(info);
		else
		{
			ft_putendl("0 0");
			return ;
		}
	}
}
