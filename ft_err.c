/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 20:35:14 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:09:45 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_err(char *msg, char *var1, char *var2, int ret)
{
	ft_putstr_fd("\x1B[31m", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\x1B[0m", 2);
	printn(var1, 2);
	ft_putendl_fd(var2, 2);
	return (ret);
}

char	**red_err(char *msg, char **t)
{
	if (t)
		ft_tabdel(t);
	ft_putstr_fd("\x1B[31m", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\x1B[0m", 2);
	return (NULL);
}
