/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:40:52 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 17:54:58 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool		set_env(char **line, t_env *env)
{
	int		i;
	char	**arg;
	char	*ptr;
	char	*ptr2;

	arg = ft_strsplit(line[1], '=');
	if (ft_tablen(line) != 2 || ft_strcnt(line[1], '=') != 1 ||
			ft_tablen(arg) != 2)
	{
		ft_tabdel(arg);
		return (disp_err(0));
	}
	ptr = ft_strjoin(arg[0], "=");
	if ((i = ft_tabchr(env->t, ptr, '=')) >= 0)
	{
		free(env->t[i]);
		ptr2 = ft_strjoin("=", arg[1]);
		env->t[i] = ft_strjoin(arg[0], ptr2);
		ft_strdel(&ptr2);
	}
	else
		env->t = ft_tabaddstr(env->t, line[1]);
	return (cde(ptr, arg));
}

bool		unset_env(char **line, t_env *env)
{
	int i;

	if (!line || ft_tablen(line) != 2)
		return (disp_err(1));
	i = ft_tabchr(env->t, line[1], '=');
	if (i == -1)
		ft_putendl("Entry not found");
	else
	{
		env->t = ft_tabrmstr(env->t, env->t[i]);
	}
	return (1);
}
