/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/07/13 21:33:55 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

# define BUFF_SIZE 4032
# define P1 'O'
# define P2 'X'

typedef struct	s_filler
{
	int		player;
	char	letter;
}				t_filler;

int			get_next_line(int const fd, char **line);
void		parse_player(t_filler *fill, char *str);
