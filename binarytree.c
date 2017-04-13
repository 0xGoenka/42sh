/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarytree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:04:39 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 17:39:58 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		tree_exec(t_tree *tree, t_env *env)
{
	if (tree == NULL)
		return ;
	if (tree->type == 0)
	{
		if (ft_strchr(tree->str, '>') == 0 && ft_strchr(tree->str, '<') == 0)
		{
			parser(tree->str, env, 1);
			ft_strdel(&tree->str);
		}
		else
		{
			main_redir(tree->str, env);
			ft_strdel(&tree->str);
		}
	}
	tree_exec_ext(tree, env);
	if (tree->type == 1)
	{
		tree_exec(tree->left, env);
		isfirstfork(0);
		tree_exec(tree->right, env);
	}
}

t_tree		*fill_tree(char *str, char **t)
{
	t_tree *tree;

	tree = NULL;
	if (ft_strlen(str) == 0)
	{
		ft_strdel(&str);
		return (NULL);
	}
	if (tree == NULL)
		tree = malloc(sizeof(t_tree));
	fill_tree_ext(str, tree);
	if (tree->type == 0)
	{
		tree->str = parse_quote(replace_dollar(str, t));
		if (ft_strlen(tree->str) == 0)
			tree->type = 4;
	}
	else
	{
		tree->str = NULL;
		tree->left = fill_tree(ft_strndup(str, find_next(str)), t);
		tree->right = fill_tree(ft_strdup(str + find_next(str) + 1), t);
		ft_strdel(&str);
	}
	return (tree);
}

void		tree_clean(t_tree *tree)
{
	if (!tree)
		return ;
	ft_strdel(&tree->str);
	tree_clean(tree->left);
	tree_clean(tree->right);
	free(tree);
	tree = NULL;
}

int			find_next(char *str)
{
	if (ft_strchrskipquote(str, ';'))
		return (ft_strchrskipquote(str, ';') - str);
	return (ft_strchrskipquote(str, '|') - str);
}
