/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyandpast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:36:13 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 17:51:45 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	copy(t_line *line)
{
	int i;

	i = line->pos;
	copy_read(line);
	move_curs(i, *line);
	if (line->buffer_copy != NULL)
	{
		free(line->buffer_copy);
		line->buffer_copy = NULL;
	}
	line->buffer_copy = (char *)malloc(sizeof(char) * line->pos - i + 1);
	line->buffer_copy[line->pos - i] = 0;
	ft_strncpy(line->buffer_copy, line->str + i, line->pos - i);
	line->pos = i;
	print_end(*line);
	return (0);
}

void	copy_read(t_line *line)
{
	char	s[7];
	int		start;

	start = line->pos;
	read(0, s, 6);
	while (s[0] != -61 || s[1] != -89 || s[2] != 0)
	{
		ft_bzero(s, 7);
		read(0, s, 6);
		if (KEY_RI && line->len > line->pos)
		{
			tputs(tgetstr("mr", 0), 0, outc);
			ft_putchar_fd(line->str[line->pos], line->h->fd);
			tputs(tgetstr("me", 0), 0, outc);
			line->pos++;
		}
		if (KEY_LE && line->pos != start)
		{
			move_curs(line->pos, *line);
			ft_putchar_fd(line->str[line->pos], line->h->fd);
			line->pos--;
			move_curs(line->pos, *line);
			check_bol(line, 0);
		}
	}
}

void	paste(t_line *line)
{
	s_add_s(line);
}
