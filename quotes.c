/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 00:30:02 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 17:44:29 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		skip_quote(char *str, int i)
{
	char c;

	if (!str)
		return (i);
	if (str[i] == '\'' || str[i] == '\"')
		c = str[i];
	else
		return (i);
	i++;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

bool	main_quote(t_line *line)
{
	char *tmp;

	if (line->quote)
		line->str = ft_saddc(line->str, '\n', 0);
	tmp = ft_strjoin(line->quote, line->str);
	ft_strdel(&line->quote);
	line->quote = tmp;
	if (!need_quote(line->quote))
	{
		ft_strdel(&line->str);
		line->str = line->quote;
		line->plen = 8;
		return (0);
	}
	ft_strdel(&line->str);
	line->pos = 0;
	line->len = 0;
	line->plen = ft_strlen("quotes !> ");
	ft_putstr_fd("\nquotes !> ", line->h->fd);
	return (1);
}

bool	need_quote(char *str)
{
	while (str && *str)
	{
		if (*str == '\'')
		{
			str++;
			while (*str && *str != '\'')
				str++;
			if (*str == 0)
				return (1);
		}
		if (*str == '\"')
		{
			str++;
			while (*str && *str != '\"')
				str++;
			if (*str == 0)
				return (1);
		}
		str++;
	}
	return (0);
}

char	*replace_dollar(char *s, char **tab)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	r = NULL;
	while (s && s[i])
	{
		i = skip_quote(s, i);
		if (s[i] == '$')
		{
			j = i + 1;
			while (s[j] && ft_isletternum(s[j]) && s[j] != ' ')
				j++;
			r = ft_strndup(s + i + 1, j - i - 1);
			if ((j = ft_tabchr(tab, r, '=')) == -1)
				while (s[i] && s[i] != ' ')
					s = ft_sdelc(s, i);
			else
				s = dol_ext(s, tab[j] + ft_strlen(r), i, ft_strlen(r) + 1);
		}
		i = s[i] ? i + 1 : i;
	}
	ft_strdel(&r);
	return (s);
}

char	*parse_quote(char *s)
{
	int		i;
	char	c;
	char	*r;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			c = s[i];
			s = ft_sdelc(s, i);
			while (s[i] && s[i] != c)
				i++;
			s = ft_sdelc(s, i--);
		}
		i++;
	}
	r = ft_strdup(s);
	ft_strdel(&s);
	return (r);
}
