/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:10:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/23 00:54:01 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define BUFF_SIZE 4032
# define NBMAXFD 2
# define BOARD env->board
# define PIECE env->piece

typedef struct	s_choice
{
	int			y;
	int			x;
	int			score;
}				t_choice;

typedef	struct	s_map_or_piece
{
	int			**tab;
	int			max_x;
	int			max_y;
	int			current_x;
	int			current_y;
	int			on_zero_x;
	int			on_zero_y;
}				t_mop;

typedef struct	s_filler
{
	int			fd;
	int			player;
	char		letter;
	int			nb_loop;
	t_mop		piece;
	t_mop		trimmed_piece;
	t_mop		board;
}				t_fill;

void			free_board_or_piece(t_mop *mop);
void			parse_player(t_fill *env, char *str);
void			parse_board(t_fill *env, char *line);
void			parse_piece(t_fill *env, char *line);
int				*parse_board_line(t_fill *env, char *line, int index);
int				*parse_piece_line(t_fill *env, char *line);
void			send_coor(int y, int x);
t_choice		find_placement(t_fill *env);

/*
** Debug utils
*/

void			debug_print_map(t_fill *env);
void			debug_print_piece(t_fill *env);
void			debug_new_round(t_fill *env);
void			debug_init(t_fill *env);
void			debug_print_score(t_fill *env, t_choice choice);

#endif
