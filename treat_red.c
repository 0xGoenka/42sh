/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 13:05:30 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 17:05:12 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		treat_redir(char **tl, t_env *env)
{
	int fd[3];

	fd[0] = 0;
	fd[1] = 1;
	fd[2] = 2;
	parse_fd(&fd[0], tl);
	exec_redir(&fd[0], tl, env);
	return (0);
}

int		exec_redir(int *fd, char **t, t_env *env)
{
	int	exec;
	int savefd[3];

	savefd[0] = dup(0);
	savefd[1] = dup(1);
	savefd[2] = dup(2);
	exec = find_exec(t);
	exec_redir2(&fd[0], t[exec], env, &savefd[0]);
	return (0);
}

int		exec_redir2(int *fd, char *cmd, t_env *env, int *savefd)
{
	int i;

	fd[0] = fd[0];
	i = -1;
	while (++i <= 2)
	{
		if (fd[i] == -3)
			close(i);
		else
			dup2(fd[i], i);
	}
	parser(cmd, env, 1);
	dup2(savefd[0], 0);
	dup2(savefd[1], 1);
	dup2(savefd[2], 2);
	close(savefd[0]);
	close(savefd[1]);
	close(savefd[2]);
	i = 0;
	while (++i < 3)
		if (fd[i] > 2)
			close(fd[i]);
	return (0);
}

int		parse_fd(int *fd, char **t)
{
	int i;
	int red;

	i = 0;
	while (t[i])
	{
		if (((red = which_redir2(t[i])) > 0 && red < 9) || red == 3 || red == 4)
		{
			if (red == 1 || red == 2)
				fd[1] = open_file(t[i + 1], red);
			if (red == 5 || red == 6)
				fd[(t[i][0] - '0')] = open_file(t[i + 1], red);
			if (red == 7)
				fd[1] = (t[i][2] == '-') ? -3 : fd[t[i][2] - '0'];
			if (red == 8)
				fd[t[i][0] - '0'] = (t[i][3] == '-') ? -3 : fd[t[i][3] - '0'];
			if (red == 3)
				fd[0] = open_file(t[i + 1], red);
			if (red == 4)
				fd[0] = main_heredoc(t);
		}
		i++;
	}
	return (0);
}
