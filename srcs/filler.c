/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/07/16 00:04:13 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		loop(t_fill *env)
{
	char	*str;

	env->nb_loop += 1;
	debug_new_round(env);
	get_next_line(0, &str);
	parse_board(env, str);
	get_next_line(0, &str);
	parse_piece(env, str);
	ft_putstr("8 2\n");
}

int			main()
{
	char	*line;
	t_fill	env;

	env.fd = open("filler.log", O_WRONLY | O_CREAT);
	env.nb_loop = 0;
	get_next_line(0, &line);
	parse_player(&env, line);
	while (1)
		loop(&env);
	close(env.fd);
	return (0);
}
