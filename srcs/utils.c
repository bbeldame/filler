/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:05:41 by bbeldame          #+#    #+#             */
/*   Updated: 2017/07/16 19:07:21 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		err_found(char *str)
{
	ft_putendl_fd(str, 2);
	exit(3);
}

void		free_board_or_piece(t_mop *mop)
{
	int i;

	i = 0;
	while (i < mop->max_y)
		free(mop->tab[i++]);
	free(mop->tab);
}
