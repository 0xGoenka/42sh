/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:29:39 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:24:16 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	check_redir2(char *str)
{
	int i;

	if (!str)
		return (1);
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		i = skip_quote(str, i);
		if (chvrndroit(str, i) == -1 || chvrngauche(str, i) == -1)
		{
			ft_putendl_fd("parsing error", 2);
			return (0);
		}
		i = i + chvrndroit(str, i) % 10;
		i = i + chvrngauche(str, i) % 10;
		i++;
	}
	return (1);
}

int		chvrndroit(char *str, int i)
{
	if (str[i] != '>')
		return (0);
	if (i > 0 && ft_strncmp(str + i - 1, " > ", 3) == 0)
		return (11);
	if (i > 0 && ft_strlen(str) - i >= 2 &&
		ft_strncmp(str + i - 1, " >> ", 4) == 0)
		return (22);
	if ((i > 1 && ft_strlen(str) - i >= 2) &&
		ft_strncmp(str + i, ">> ", 3) == 0
		&& ft_numbtw('0', '2', str[i - 1]) && str[i - 2] == ' ')
		return (132);
	if (i > 0 && ft_strlen(str) - i >= 3 && str[i + 3] == ' ' &&
		ft_strncmp(str + i - 1, " >&", 3) == 0 &&
		(ft_numbtw('0', '2', str[i + 2]) || str[i + 2] == '-'))
		return (43);
	if (i > 1 && ft_strlen(str + i) >= 3 && ft_numbtw('0', '2', str[i - 1])
		&& str[i - 2] == ' ' && ft_strncmp(">&", str + i, 2) == 0 &&
		(ft_numbtw('0', '2', str[i + 2]) || str[i + 2] == '-')
		&& str[i + 3] == 32)
		return (153);
	if (i > 1 && ft_strlen(str + i) > 1 && ft_strncmp("> ", str + i, 2) == 0
			&& ft_numbtw('0', '2', str[i - 1]) && str[i - 2] == ' ')
		return (161);
	return ((str[i] == '>' ? -1 : 0));
}

int		chvrngauche(char *str, int i)
{
	if (str[i] != '<')
		return (0);
	if (i > 0 && ft_strncmp(str + i - 1, " < ", 3) == 0)
		return (71);
	if (i > 0 && ft_strlen(str + i) > 1
		&& ft_strncmp(str + i - 1, " << ", 4) == 0)
		return (82);
	if (str[i] == '<')
		return (-1);
	return (0);
}
