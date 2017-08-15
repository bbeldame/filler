/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:10:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/13 16:32:16 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define BOARD env->board
# define PIECE env->piece
# define TRIM env->trimmed_piece

typedef struct	s_choice
{
	int			y;
	int			x;
	int			dist;
}				t_choice;

typedef struct	s_cleaner
{
	int			min_x;
	int			min_y;
	int			max_x;
	int			max_y;
}				t_cleaner;

typedef	struct	s_map_or_piece
{
	int			**tab;
	int			max_x;
	int			max_y;
	int			current_x;
	int			current_y;
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
}				t_env;

void			free_board_or_piece(t_mop *mop);
void			parse_player(t_env *env, char *str);
void			parse_board(t_env *env, char *line);
void			parse_piece(t_env *env, char *line);
int				*parse_board_line(t_env *env, char *line, int index);
int				*parse_piece_line(t_env *env, char *line);
t_choice		find_placement(t_env *env);
t_cleaner		get_piece_cleaner(t_env *env);
int				*parse_trim_line(t_env *env, int y, int x, t_cleaner cleaner);

/*
** Debug utils
*/

void			debug_print_map(t_env *env);
void			debug_print_piece(t_env *env);
void			debug_new_round(t_env *env);
void			debug_init(t_env *env);
void			debug_print_score(t_env *env, t_choice choice);

#endif
