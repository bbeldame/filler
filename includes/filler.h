/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:10:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/16 00:04:26 by bbeldame         ###   ########.fr       */
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

typedef	struct	s_board
{
	int			**tab;
	int			max_x;
	int			max_y;
}				t_board;

typedef	struct	s_piece
{
	int			**tab;
	int			max_x;
	int			max_y;
}				t_piece;

typedef struct	s_filler
{
	int			fd;
	int			player;
	char		letter;
	int			nb_loop;
	t_piece		piece;
	t_board		board;
}				t_fill;

int			get_next_line(int const fd, char **line);
void		err_found(char *str);
void		free_splited_str(char **str);
void		*semalloc(size_t size);
int			len_of_tab(char **tab);
void		parse_player(t_fill *env, char *str);
void		parse_board(t_fill *env, char *line);
void		parse_piece(t_fill *env, char *line);
int			*parse_board_line(t_fill *env, char *line);
int			*parse_piece_line(t_fill *env, char *line);

/* Debug utils */
void		debug_print_map(t_fill *env);
void		debug_print_piece(t_fill *env);
void		debug_new_round(t_fill *env);

#endif
