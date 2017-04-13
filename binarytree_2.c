/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarytree_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:04:39 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 17:40:48 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			type_cmd(char *str)
{
	if (ft_strchrskipquote(str, ';'))
		return (1);
	if (ft_strchrskipquote(str, '|'))
		return (2);
	return (0);
}

char		*ft_strchrskipquote(char *s, char c)
{
	char d;

	if (!s)
		return (NULL);
	while (*s != c)
	{
		if (*s == 0)
			return (NULL);
		if (*s == '\'' || *s == '\"')
		{
			d = *s;
			s++;
			while (*s != d)
				s++;
		}
		s++;
	}
	return (s);
}

void		read_tree(t_tree *tree)
{
	if (tree == NULL)
		return ;
	if (tree->type == 0)
		ft_putendl(tree->str);
	if (tree->type == 1)
		ft_putendl(";");
	if (tree->type == 2)
		ft_putendl("|");
	read_tree(tree->left);
	read_tree(tree->right);
}
