/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:28:13 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:19:27 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_hist	*hist_init(void)
{
	t_hist	*h;
	int		i;

	i = 0;
	h = (t_hist *)malloc(sizeof(t_hist));
	h->tab = (char **)malloc(sizeof(char*) * HLEN);
	h->pos = 0;
	h->index = 0;
	h->quote = NULL;
	h->status = 0;
	while (i < HLEN)
	{
		h->tab[i] = NULL;
		i++;
	}
	return (h);
}

void	hist_add(t_hist *h, char *s)
{
	if (s && *s && !h->status)
	{
		ft_strdel(&h->tab[h->index]);
		h->tab[h->index] = ft_strdup(s);
		h->index++;
		if (h->index == HLEN)
			h->index = 0;
	}
}

void	hist_read_up(t_line *l)
{
	l->h->pos = (l->h->pos == -1) ? 0 : l->h->pos;
	if (l->h->art)
		if (l->h->pos == 0)
			l->h->pos = HLEN - 1;
		else
			l->h->pos--;
	else
		l->h->art = 1;
	if (l->h->pos != l->h->index && l->h->tab[l->h->pos])
	{
		free(l->str);
		l->str = ft_strdup(l->h->tab[l->h->pos]);
		move_curs(0, *l);
		tputs(tgetstr("cd", 0), 0, outc);
		l->len = ft_strlen(l->str);
		l->pos = l->len;
		printn(l->str, l->h->fd);
	}
	else
	{
		if (l->h->pos == HLEN - 1)
			l->h->pos = 0;
		else
			l->h->pos++;
	}
}

void	hist_read_do(t_line *l)
{
	if ((l->h->pos + 1) % HLEN != l->h->index)
	{
		if (l->h->pos == HLEN - 1)
			l->h->pos = 0;
		else
			l->h->pos++;
		free(l->str);
		l->str = ft_strdup(l->h->tab[l->h->pos]);
		move_curs(0, *l);
		l->pos = ft_strlen(l->str);
		tputs(tgetstr("cd", 0), 0, outc);
		printn(l->str, l->h->fd);
	}
	else if (l->h->art)
	{
		l->h->art = 0;
		ft_strdel(&l->str);
		move_curs(0, *l);
		l->pos = 0;
		l->len = 0;
		tputs(tgetstr("cd", 0), 0, outc);
	}
}
