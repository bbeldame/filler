/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/07/17 18:23:56 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Send the coordonate of the piece to the VM
*/

void		send_coor(int y, int x)
{
	char	*str_y;
	char	*str_x;

	str_y = ft_itoa(y);
	str_x = ft_itoa(x);
	ft_putstr(str_y);
	ft_putchar(' ');
	ft_putstr(str_x);
	ft_putchar('\n');
	free(str_y);
	free(str_x);
}

void		loop(t_fill *env)
{
	char	*str;

	env->nb_loop += 1;
	debug_new_round(env);
	get_next_line(0, &str);
	parse_board(env, str);
	get_next_line(0, &str);
	parse_piece(env, str);
	send_coor(8, 2);
}

void		init(t_fill *env)
{
	env->nb_loop = 0;
	env->board.max_x = 0;
	env->board.max_y = 0;
	env->piece.max_x = 0;
	env->piece.max_y = 0;
	env->trimmed_piece.max_x = 0;
	env->trimmed_piece.max_y = 0;
}

int			main(void)
{
	char	*line;
	t_fill	env;

	env.fd = open("filler.log", O_WRONLY | O_CREAT);
	debug_init(&env);
	init(&env);
	get_next_line(0, &line);
	parse_player(&env, line);
	while (1)
		loop(&env);
	close(env.fd);
	return (0);
}
