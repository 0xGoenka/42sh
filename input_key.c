/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:02:32 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 15:50:32 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	key_pressed(char *s, t_line *line)
{
	if (IS_CHAR)
		return (letter(line, s[0]));
	if (KEY_LE)
		return (key_le(line));
	if (KEY_RI)
		return (key_ri(line));
	if (BACKSPACE)
		return (key_del(line));
	if (DEL)
		return (key_suppr(line));
	if (CTRL_D)
		return (ctrl_d(line));
	if (CTRL_DO)
		return (key_do(line));
	if (CTRL_UP)
		return (key_upp(line));
	if (HOME)
		return (key_ho(line));
	return (key_press_ext(s, line));
}

char	key_press_ext(char *s, t_line *line)
{
	if (END)
		return (key_en(line));
	if (CTRL_RIGHT)
		return (key_next_word(line));
	if (CTRL_LEFT)
		return (key_prev_word(line));
	if (ALT_C)
		return (copy(line));
	if (ALT_V)
		paste(line);
	if (ENTER)
		return (-1);
	if (KEY_UPP)
		hist_read_up(line);
	if (KEY_DO)
		hist_read_do(line);
	return (0);
}

int		letter(t_line *line, char c)
{
	line->str = s_add(line->str, c, line->pos);
	line->len++;
	line->pos++;
	ft_putchar_fd(c, line->h->fd);
	check_eol(line, 0);
	print_end(*line);
	return (0);
}

bool	key_suppr(t_line *line)
{
	if (line->pos == line->len)
		return (0);
	line->str = s_del(line->str, line->pos);
	line->len--;
	print_end(*line);
	return (0);
}

int		key_del(t_line *line)
{
	if (!line->pos)
		return (0);
	line->str = s_del(line->str, (line->pos - 1));
	line->len--;
	line->pos--;
	if (!check_bol(line, 0))
		tputs(tgetstr("le", 0), 0, outc);
	print_end(*line);
	return (0);
}
