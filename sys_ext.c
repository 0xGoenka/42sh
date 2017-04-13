/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_ext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:12:13 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:31:57 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		free_ret(char *s1, char *s2, int r)
{
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (r);
}

int		cde(char *tmp, char **arg)
{
	ft_strdel(&tmp);
	ft_tabdel(arg);
	return (1);
}

int		tree_exec_ext(t_tree *tree, t_env *env)
{
	pid_t pid;

	if (tree->type == 2)
	{
		if (isfirstfork(42) != 0)
			ft_fork(tree, env);
		else
		{
			isfirstfork(1);
			pid = fork();
			if (pid == 0)
				ft_fork(tree, env);
			else
				wait(&pid);
		}
	}
	return (1);
}

int		fill_tree_ext(char *str, t_tree *tree)
{
	tree->left = NULL;
	tree->right = NULL;
	tree->type = type_cmd(str);
	return (0);
}
