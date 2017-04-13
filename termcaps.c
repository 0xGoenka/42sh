/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defterm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:53:28 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:32:44 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				problem(void)
{
	ft_putendl_fd("Probleme termcaps", 2);
	exit(0);
}

struct	termios		*def_term(void)
{
	char			*term_name;
	struct termios	term;
	struct termios	*old_term;

	old_term = malloc(sizeof(struct termios));
	if (!(term_name = getenv("TERM")))
		problem();
	if (tgetent(NULL, term_name) == ERR)
		problem();
	if (tcgetattr(0, &term) == -1)
		problem();
	if (tcgetattr(0, old_term) == -1)
		problem();
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		problem();
	return (old_term);
}

bool				restore_term(struct termios *term_restore)
{
	t_line *l;

	l = stock(NULL, 1);
	if (tcsetattr(0, TCSANOW, term_restore) == -1)
		problem();
	free(term_restore);
	ft_putchar_fd('\n', l->h->fd);
	return (1);
}

bool				clean_exit(t_line *line)
{
	line->pos = line->pos;
	return (0);
}
