/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_terminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconnat <mconnat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:52:53 by mconnat           #+#    #+#             */
/*   Updated: 2015/12/10 02:19:33 by mconnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_file(char *buf, int ret)
{
	int line;
	int i;
	int char_nb;
	int pieces;

	line = 0;
	i = 0;
	char_nb = 0;
	pieces = 0;
	while (buf[i] != '\0')
	{
		if ((line == 4 && char_nb != 20) || (line != 4 && char_nb == 20))
		{
			ft_putstr_fd("Invalid entries, end of process.\n", 2);
			return (1);
		}

		if (line == 4 && char_nb == 20)
		{
			line = -1;
			char_nb = -1;
			pieces++;
		}
		if (buf[i] == '\n')
			line++;
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
		{
			ft_putstr_fd("Invalid entries, end of process.\n", 2);
			return (1);
		}
		i++;
		char_nb++;
	}		
	pieces++;
	if (ret <= 420 && pieces != (ret / 20))
	{
		ft_putstr_fd("Invalid entries, end of process.\n", 2);
		return (1);
	}
	if (ret > 420 && pieces != ((ret / 20) - 1))
	{
		ft_putstr_fd("Invalid entries, end of process.\n", 2);
		return (1);
	}
	return (0);
}
