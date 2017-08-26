/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 22:19:50 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/26 14:08:51 by bbeldame         ###   ########.fr       */
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

/*
** Endless loop to get the infos from the VM on each round
** we make a strstr to verify that the VM send us the board
** or the piece. Basically this is the whole filler :
** Parse Board - Parse Piece - Find Placement - Print it
*/

void		loop(t_env *env)
{
	char		*str;
	t_choice	choice;

	env->nb_loop += 1;
	debug_new_round(env);
	get_next_line(0, &str);
	ft_putendl_fd(str, env->fd);
	if (ft_strstr(str, "Plateau") != NULL)
	{
		parse_board(env, str);
		get_next_line(0, &str);
	}
	parse_piece(env, str);
	choice = find_placement(env);
	send_coor(choice.y, choice.x);
}

void		init(t_env *env)
{
	env->nb_loop = 0;
	BOARD.max_x = 0;
	BOARD.max_y = 0;
	BOARD.tab = NULL;
	PIECE.max_x = 0;
	PIECE.max_y = 0;
	env->trimmed_piece.max_x = 0;
	env->trimmed_piece.max_y = 0;
}

/*
** We init the debug (open the filler.log file)
** and then a gnl to get the first line of the VM
** which tells our player number
*/

int			main(void)
{
	char	*line;
	t_env	env;

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
