/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/07/13 21:35:35 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			main()
{
	int			fd;
	int			ret;
	char		buf[99999 + 1];
	char		**tab;
	int			player;
	int			i;
	t_filler	*fill;

	i = 0;
	player = 0;
	fill = malloc(sizeof(t_filler));
	if (fill == NULL)
		return (0);
	fd = open("filler.log", O_WRONLY | O_CREAT);
	ret = read(0, buf, 99999);
	buf[ret] = '\0';
	write(fd, "-----\n", 7);
	tab = ft_strsplit(buf, '\n');
	while (tab[i] != '\0')
	{
		if (**tab == '\0' || **tab == '\n')
			write(fd, "\n", 2);
		write(fd, tab[i], (ft_strlen(tab[i])));
		write(fd, "\n", 2);
		i++;
	}
	parse_player(fill, tab[0]);
	if (fill->player == 1)
		write(fd, "IM THE FIRST PLAYER\n", 21);
	else if (fill->player == 2)
		write(fd, "fuck\n", 5);
	close(fd);
	ft_putstr("8 1\n");
	return (0);
}

void		parse_player(t_filler *fill, char *str)
{
	while (*str != '\0')
	{
		if (str[10] == '1')
		{
			fill->player = 1;
			fill->letter = P1;
		}
		else if (str[10] == '2')
		{
			fill->player = 2;
			fill->letter = P2;
		}
		else
			ft_putstr("bad player");
		str++;
	}
}
