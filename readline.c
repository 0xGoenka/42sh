/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:38:40 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:29:16 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*readline(char *prompt, t_hist *hist)
{
	char			buf[7];
	t_line			*line;
	struct termios	*old_term;

	if (!(old_term = def_term()))
		disp_err(2);
	line = struct_init(prompt, hist);
	stock(line, 0);
	ft_putchar_fd('\n', line->h->fd);
	ft_putstr_fd(line->prompt, line->h->fd);
	ft_signal();
	while (42)
	{
		ft_bzero(buf, 7);
		read(0, buf, 6);
		if (key_pressed(buf, line) == -1 && !main_quote(line))
			break ;
	}
	ft_signal2();
	move_curs(line->len, *line);
	restore_term(old_term);
	hist_add(hist, line->str);
	return (line->str);
}
