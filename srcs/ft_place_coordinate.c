/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_coordinate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:20:50 by tluzing           #+#    #+#             */
/*   Updated: 2018/08/14 16:23:04 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/libft.h"

void	store_tmp_map(t_map_info *info)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(info->tmp_map = (char**)malloc(sizeof(char *) * info->y_row)))
		return ;
	while (y < info->y_row)
	{
		x = 0;
		info->tmp_map[y] = (char *)malloc(sizeof(char) * info->x_col);
		while (x < info->x_col)
		{
			info->tmp_map[y][x] = info->map[y][x];
			x++;
		}
		y++;
	}
}

int		place_piece_check(t_map_info *piece_info, t_player *shape)
{
	if (shape->letter == 'O')
	{
		if ((piece_info->os_num + piece_info->add_num - 1) ==
				piece_info->tmp_os && (piece_info->xs_num ==
					piece_info->tmp_xs))
			return (0);
		else
			return (1);
	}
	else if (shape->letter == 'X')
	{
		if ((piece_info->xs_num + piece_info->add_num - 1) ==
				piece_info->tmp_xs && (piece_info->os_num ==
					piece_info->tmp_os))
			return (0);
		else
			return (1);
	}
	return (-1);
}

int		piece_movement(t_map_info *info)
{
	if (info->place_ret == 1)
	{
		info->y_place--;
		info->x_place = info->x_col - 1;
	}
	else if (info->place_ret == 2)
		return (1);
	else
		info->x_place--;
	return (0);
}

void	send_coordinate(t_map_info *info)
{
	ft_putnbr(info->place_coord_y);
	ft_putchar(' ');
	ft_putnbr(info->place_coord_x);
	ft_putchar('\n');
}

int		main(void)
{
	t_player	*me;
	t_map_info	*map_size;

	me = (t_player *)malloc(sizeof(*me));
	map_size = (t_map_info *)malloc(sizeof(*map_size));
	algo1(map_size, me);
	algorithm(map_size, me);
	return (0);
}
