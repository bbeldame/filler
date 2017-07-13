/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:10:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/14 00:34:38 by bbeldame         ###   ########.fr       */
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
# define P1 'O'
# define P2 'X'

typedef struct	s_filler
{
	int		fd;
	int		player;
	char	letter;
	char	**board;
	int		map_x;
	int		map_y;
	int		piece_x;
	int		piece_y;
}				t_fill;

int			get_next_line(int const fd, char **line);
void		err_found(char *str);
void		free_splited_str(char **str);
void		*semalloc(size_t size);
int			len_of_tab(char **tab);
void		parse_player(t_fill *env, char *str);
void		parse_board(t_fill *env, char *line);
void		parse_piece(t_fill *env, char *line);
char		*parse_board_line(t_fill *env, char *line);

#endif
