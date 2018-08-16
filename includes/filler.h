/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 10:10:02 by tluzing           #+#    #+#             */
/*   Updated: 2018/08/14 16:27:54 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef struct	s_player
{
	char		player_nbr;
	char		letter;
	char		current_letter;

}				t_player;

typedef struct	s_map_piece
{
	int			x_col;
	int			y_row;
	int			x_pce;
	int			y_pce;
	int			x_place;
	int			x_place1;
	int			y_place;
	int			y_place1;
	int			place_ret;
	int			place_ret1;
	int			modulo;
	int			p_left_start;
	int			p_top_start;
	int			p_bottom_end;
	int			p_right_end;
	int			add_num;
	int			os_num;
	int			xs_num;
	int			tmp_os;
	int			tmp_xs;
	int			place_coord_x;
	int			place_coord_y;
	int			piece_y;
	int			piece_x;
	int			map_x;
	int			map_y;

	char		**map;
	char		**piece;
	char		**tmp_map;

}				t_map_info;

void			player_id(t_player *player);
void			map_size(t_map_info *map);
void			get_map(t_map_info *read_map_into);
void			store_tmp_map(t_map_info *read_tmp_into);
void			get_piece(t_map_info *read_piece_into);
void			get_piece_size(t_map_info *piece);
void			piece_start(t_map_info *info);
void			piece_start1(t_map_info *info);
void			place_piece(t_map_info *info, t_player *me);
void			get_shape_count(t_map_info *p_info);
void			letter_count(t_map_info *p_info);
void			get_tmp_letter(t_map_info *p_info);
void			send_coordinate(t_map_info *info);
void			initialize_struct(t_map_info *info);
void			piece_left_side(t_map_info *info);
void			piece_top_side(t_map_info *info);
void			piece_right_side(t_map_info *info);
void			piece_bottom_side(t_map_info *info);
void			trim_piece_map(t_map_info *info);
void			algo1(t_map_info *info, t_player *me);
void			algo2(t_map_info *info, t_player *me);
void			algo3(t_map_info *info);
void			algo4(t_map_info *info, t_player *me);
void			algo4_1(t_map_info *info, t_player *me);
void			algorithm(t_map_info *info, t_player *me);
void			algorithm1(t_map_info *info, t_player *me);
void			rev_place_piece(t_map_info *info, t_player *me);
void			rev_algo2(t_map_info *info, t_player *me);
void			rev_algo4(t_map_info *info, t_player *me);
void			rev_place_piece1(t_map_info *info, t_player *me);
void			rev_algo2_1(t_map_info *info, t_player *me);
void			rev_algo4_1(t_map_info *info, t_player *me);
int				rev_movement(t_map_info *info);
int				rev_movement1(t_map_info *info);
int				place_piece_check(t_map_info *piece_info, t_player *shape);
int				piece_movement(t_map_info *info);
int				rev_move(t_map_info *info);
#endif
