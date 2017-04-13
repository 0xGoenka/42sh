/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:02:32 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 15:53:00 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	key_en(t_line *line)
{
	if (line->pos == line->len)
		return (0);
	move_curs(line->len, *line);
	line->pos = line->len;
	return (1);
}

bool	key_next_word(t_line *line)
{
	int i;

	i = line->pos;
	while (line->str[i] && line->str[i] != 32)
		i++;
	while (line->str[i] && line->str[i] == 32)
		i++;
	if (i != line->len)
	{
		move_curs(i, *line);
		line->pos = i;
	}
	return (1);
}

bool	key_prev_word(t_line *line)
{
	int i;
	int k;

	k = 0;
	i = line->pos;
	while (i && line->str[i] != 32)
		i--;
	while (i && line->str[i] == 32)
		i--;
	while (i && line->str[i] != 32)
		i--;
	if (i)
		k = 1;
	move_curs(i + k, *line);
	line->pos = i + k;
	return (1);
}
