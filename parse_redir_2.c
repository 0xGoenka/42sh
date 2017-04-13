/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:48:48 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 16:48:04 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*redir_to_tab_ext(char *str, int *i)
{
	char *tmp;

	if (str[*i] == '>')
	{
		tmp = ft_strndup(str + *i - chvrndroit(str, *i) / 100,
				chvrndroit(str, *i) / 100 + chvrndroit(str, *i) % 10);
		*i = *i + chvrndroit(str, *i) % 10;
		return (tmp);
	}
	if (str[*i] == '<')
	{
		tmp = ft_strndup(str + *i, chvrngauche(str, *i) % 10);
		*i = *i + chvrngauche(str, *i) % 10;
		return (tmp);
	}
	return (NULL);
}

int			which_redir2(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	if (ft_strcmp(str, ">") == 0)
		return (1);
	if (ft_strcmp(str, ">>") == 0)
		return (2);
	if (ft_strcmp(str, "<") == 0)
		return (3);
	if (ft_strcmp(str, "<<") == 0)
		return (4);
	if (ft_strcmp(str + 1, ">>") == 0)
		return (5);
	if (ft_strcmp(str + 1, ">") == 0)
		return (6);
	if (ft_strncmp(str, ">&", 2) == 0)
		return (7);
	if (ft_strncmp(str + 1, ">&", 2) == 0)
		return (8);
	return (-1);
}

int			which_redir(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '<' && str[i] != '>')
	{
		i = skip_quote(str, i);
		i++;
	}
	if (str[i] != '>' || str[i] != '<')
		return (-1);
	if (chvrndroit(str, i) != 0 && chvrndroit(str, i) != -1)
		return (chvrndroit(str, i) % 100 / 10);
	if (chvrngauche(str, i) != 0 && chvrngauche(str, i) != -1)
		return (chvrngauche(str, i) % 100 / 10);
	return (-1);
}
