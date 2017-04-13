/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 12:28:50 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:29:41 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main_heredoc(char **t)
{
	int		last;
	char	**split;
	char	*ptr;
	int		fd;

	if ((last = parse_heredoc(t)) == -1)
	{
		ft_putendl_fd("error last heredoc", 2);
		return (0);
	}
	split = ft_strsplit(t[last + 1], ' ');
	ptr = ft_strtrim(split[0]);
	fd = heredoc(t, ptr);
	ft_strdel(&ptr);
	ft_tabdel(split);
	return (fd);
}

int		heredoc(char **t, char *strstop)
{
	t_line	*l;
	char	*str;
	int		pipefd[2];

	l = stock(NULL, 1);
	ft_putstr_fd(t[0], 100);
	pipe(pipefd);
	while (42)
	{
		str = readline("Heredoc &> ", l->h);
		if (ft_strlen(str) && ft_strcmp(strstop, str) == 0)
			break ;
		ft_putendl_fd(str, pipefd[1]);
		clean_line(stock(NULL, 1));
	}
	clean_line(stock(NULL, 1));
	stock(l, 0);
	close(pipefd[1]);
	return (pipefd[0]);
}

int		parse_heredoc(char **t)
{
	int end;

	end = ft_tablen(t) - 1;
	while (end)
	{
		if (which_redir2(t[end]) == 4)
			return (end);
		end--;
	}
	return (-1);
}
