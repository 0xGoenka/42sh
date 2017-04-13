/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:40:52 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 17:54:57 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_env		*env_init(void)
{
	extern char **environ;
	t_env		*env;
	char		*s;
	int			shlvl;

	env = (t_env *)malloc(sizeof(t_env));
	env->hist = hist_init();
	env->t = ft_tabdup(environ);
	if ((s = get_env_val(env->t, "SHLVL")))
	{
		shlvl = ft_atoi(s);
		ft_strdel(&s);
		++shlvl;
		change_env_val(env->t, ft_strdup("SHLVL"), (s = ft_itoa(shlvl)));
		ft_strdel(&s);
	}
	return (env);
}

bool		display_env(char **line, t_env *env)
{
	t_opt	opt;
	char	**tmpenv;

	tmpenv = NULL;
	tmpenv = ft_tabdup(env->t);
	opt = ft_getopt(line, "ui");
	if (opt.status != 1)
		if (!env_alone(tmpenv, opt))
			if (!env_i(opt))
				env_u(tmpenv, opt);
	ft_tabdel(tmpenv);
	ft_tabdel(opt.arg);
	ft_strdel(&opt.opt);
	return (1);
}

bool		env_alone(char **env, t_opt opt)
{
	if (!opt.opt && !opt.arg)
		ft_printtab(env);
	else if (ft_tablen(env) == 0)
		ft_putendl("Env is empty.");
	else if (!opt.opt && opt.arg)
	{
		if (basic_exec(opt.arg, env, 1))
			exec_bin(env, opt.arg, split_path(env), 1);
	}
	else
		return (0);
	return (1);
}

bool		env_i(t_opt opt)
{
	if (!ft_strchr(opt.opt, 'i'))
		return (0);
	if (!ft_strchr(opt.opt, 'u'))
	{
		if (opt.arg)
			if (basic_exec(opt.arg, NULL, 1))
				exec_bin(NULL, opt.arg, NULL, 1);
		return (1);
	}
	else
	{
		if (!opt.arg)
			ft_putendl("missing arg for -u");
		if (ft_tablen(opt.arg) > 1)
		{
			if (basic_exec(opt.arg, NULL, 1))
				exec_bin(opt.arg, NULL, NULL, 1);
		}
		return (1);
	}
	return (0);
}

bool		env_u(char **env, t_opt opt)
{
	int		i;
	char	**tmp;

	if (!opt.arg)
		return (ft_err("missing arg for -u", NULL, NULL, 0));
	tmp = ft_tabdup(env);
	i = ft_tabchr(env, opt.arg[0], '=');
	if (i != -1)
		tmp = ft_tabrmstr(tmp, env[i]);
	if (ft_tablen(opt.arg) == 1)
		ft_printtab(tmp);
	else
	{
		if (basic_exec(opt.arg + 1, env, 1))
			exec_bin(env, opt.arg + 1, split_path(env), 1);
	}
	ft_tabdel(tmp);
	return (1);
}
