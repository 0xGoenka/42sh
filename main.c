/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:30:22 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:29:26 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	t_env	*env;
	char	*str;
	t_tree	*t;
	t_line	*l;

	env = env_init();
	while (1)
	{
		str = readline("21sh #> ", env->hist);
		t = fill_tree(ft_strdup(str), env->t);
		chk_t(t);
		if (tree_error(42) == 0)
			tree_exec(t, env);
		isfirstfork(0);
		tree_error(0);
		tree_clean(t);
		l = stock(NULL, 1);
		clean_line(l);
	}
	return (0);
}
