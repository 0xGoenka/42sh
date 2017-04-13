/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:50:21 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/22 21:19:13 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	disp_err(int code)
{
	if (code == 0)
	{
		ft_putendl("an error occured : usage setenv key=value");
		return (1);
	}
	else if (code == 1)
	{
		ft_putendl("Usage : 'unsetenv key'");
		return (1);
	}
	else if (code == 2)
	{
		ft_putendl("Empty env, program will exit now.");
		exit(-1);
	}
	else
	{
		printf("%d\n", code);
		return (0);
	}
	return (0);
}
