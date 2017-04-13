/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:02:32 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 15:49:01 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	key_ri(t_line *line)
{
	if (line->pos == line->len)
		return (1);
	else
	{
		tputs(tgetstr("nd", 0), 0, outc);
		line->pos++;
		check_eol(line, 0);
	}
	return (1);
}

bool	key_le(t_line *line)
{
	if (!line->pos)
		return (1);
	else
	{
		line->pos--;
		if (!check_bol(line, 0))
			tputs(tgetstr("le", 0), 0, outc);
	}
	return (1);
}

bool	key_upp(t_line *line)
{
	if (posy(*line) == 0)
		return (0);
	if (posy(*line) == 1 && posx(*line) < line->plen)
		return (0);
	move_curs(line->pos - col(), *line);
	line->pos = line->pos - col();
	return (1);
}

bool	key_do(t_line *line)
{
	if (line->pos + col() > line->len)
		return (0);
	move_curs(line->pos + col(), *line);
	line->pos = line->pos + col();
	return (1);
}

bool	key_ho(t_line *line)
{
	if (line->pos == 0)
		return (0);
	move_curs(0, *line);
	line->pos = 0;
	return (1);
}
