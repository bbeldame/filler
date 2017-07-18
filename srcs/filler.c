/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 22:19:50 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/18 22:19:52 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Send the coordonate of the piece to the VM
*/

void		send_coor(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
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
	env->board.tab = NULL;
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
