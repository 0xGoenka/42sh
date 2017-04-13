/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:44:58 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:27:07 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	chk_t(t_tree *t)
{
	if (!t)
		return ;
	if (t->type)
	{
		if (!t->left || !t->right)
		{
			ft_putendl_fd("Parsing error", 2);
			tree_error(1);
			return ;
		}
	}
	if (ft_strisonly(t->str, ' ') && t->type == 0)
	{
		ft_putendl_fd("Parsing error 3", 2);
		tree_error(1);
		return ;
	}
	chk_t(t->right);
	chk_t(t->left);
}

int		tree_error(int i)
{
	static int status = 0;

	if (i == 42)
		return (status);
	return ((status = i));
}

int		isfirstfork(int i)
{
	static int n = 0;

	if (i == 42)
		return (n);
	return ((n = i));
}

int		ft_fork(t_tree *tree, t_env *env)
{
	int		pipefd[2];
	pid_t	pid;

	if (!tree)
		return (1);
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		tree_exec(tree->left, env);
	}
	else
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		tree_exec(tree->right, env);
		wait(&pid);
	}
	exit(1);
	return (1);
}
