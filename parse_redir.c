/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:48:48 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 16:20:51 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		**redir_to_tab(char *str)
{
	char	**t;
	int		i;
	char	*tmp;

	i = -1;
	t = NULL;
	while (str[++i])
	{
		if (str[i] == '>' || str[i] == '<')
		{
			tmp = redir_to_tab_ext(str, &i);
			t = ft_tabaddstr(t, tmp);
			ft_strdel(&tmp);
		}
		else
		{
			if ((tmp = cmd_to_tab(str, &i)) != NULL)
			{
				t = ft_tabaddstr(t, tmp);
				ft_strdel(&tmp);
				i--;
			}
		}
	}
	return (t);
}

char		**check_redir(char **t)
{
	int i;
	int j;

	j = 0;
	i = 1;
	t = tab_rmemptyline(t);
	if ((which_redir2(t[0]) > 0 && which_redir2(t[0]) < 7)
			|| (which_redir2(t[ft_tablen(t) - 1]) > 0
				&& which_redir2(t[ft_tablen(t) - 1]) < 7))
		return (red_err("Parsing error 1\n", t));
	while (t[i])
		if ((which_redir2(t[i]) > 0 && which_redir2(t[i]) < 7) &&
				(which_redir2(t[i - 1]) > 0 && which_redir2(t[i - 1]) < 7))
			return (red_err("Parsing error  redir 2", t));
		else
			i++;
	i = -1;
	while (t[++i])
	{
		if (which_redir2(t[i]) == -1)
			j = 1;
		if (which_redir2(t[i]) > 0 && which_redir2(t[i]) < 7 && j == 0)
			return (red_err("Parsing error 3\n", t));
	}
	return (t);
}

bool		check_redir3(char **t)
{
	int i;
	int red;
	int red2;

	i = 0;
	while (t[i])
	{
		red = which_redir2(t[i]);
		if (red != 7 && red != 8 && red != -1)
		{
			red2 = which_redir2(t[i + 1]);
			if (red2 == 7 || red2 == 8)
			{
				ft_putendl_fd("parsing error 4", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

char		**tab_rmemptyline(char **t)
{
	char	**r;
	int		i;

	r = NULL;
	i = 0;
	while (t[i])
	{
		if (ft_strlen(t[i]) != 0 && !ft_strisonly(t[i], ' '))
			r = ft_tabaddstr(r, t[i]);
		i++;
	}
	ft_tabdel(t);
	return (r);
}

char		*cmd_to_tab(char *str, int *i)
{
	int		j;

	j = *i;
	while (str[*i] && str[*i] != '>' && str[*i] != '<')
	{
		*i = skip_quote(str, *i);
		*i = *i + 1;
	}
	if (str[*i] == '>' && chvrndroit(str, *i) != -1 && chvrndroit(str, *i) != 0)
	{
		return (ft_strndup(str + j, *i - j - chvrndroit(str, *i) / 100));
	}
	if (*i - j <= 0)
		return (NULL);
	return (ft_strndup(str + j, *i - j));
}
