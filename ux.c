/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 21:54:33 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:36:29 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	check_eol(t_line *line, int p)
{
	int len;

	len = line->pos + line->plen;
	if (len % col() == 0)
	{
		tputs(tgetstr("do", 0), 0, outc);
		if (p)
		{
			line->pos++;
		}
		return (1);
	}
	else
		return (0);
}

bool	check_bol(t_line *line, int p)
{
	if ((line->pos + line->plen) % col() == col() - 1)
	{
		tputs(tgetstr("up", 0), 0, outc);
		tputs(tgoto(tgetstr("ch", 0), 0, col() - 1), 0, outc);
		if (p)
			line->pos--;
		return (1);
	}
	else
		return (0);
}

void	print_end(t_line line)
{
	char *s;

	tputs(tgetstr("cd", NULL), 0, outc);
	s = line.str + line.pos;
	printn(line.str + line.pos, line.h->fd);
	restore_curs(line);
}

int		posx(t_line line)
{
	return ((line.pos + line.plen) % col());
}

int		posy(t_line line)
{
	int i;

	i = (line.pos + line.plen) / col();
	return (i);
}
