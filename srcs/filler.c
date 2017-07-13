/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:36:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/07/13 20:59:27 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			main()
{
	int		fd;
	int		ret;
	char	buf[99999 + 1];
	char	**tab;
	int		player;
	int		i;

	i = 0;
	player = 0;
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
	player = tab[1][10] == 1 ? 1 : 2;
	write(fd, "-----\n", 7);
	if (player == 1)
		write(fd, "IM THE FIRST PLAYER\n", 21);
	else if (player == 2)
		write(fd, "fuck\n", 5);
	close(fd);
	ft_putstr("8 3\n");
	ft_putstr("8 5\n");
	return (0);
}
