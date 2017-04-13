/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:50:21 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 19:03:45 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	disp_err(int code)
{
	if (code == 0)
	{
		ft_putendl_fd("an error occured : usage setenv key=value", 2);
		return (1);
	}
	else if (code == 1)
	{
		ft_putendl_fd("Usage : 'unsetenv key'", 2);
		return (1);
	}
	else if (code == 2)
	{
		ft_putendl_fd("Empty env, program will exit now.", 2);
		exit(-1);
	}
	else
	{
		ft_putnbr(code);
		return (0);
	}
	return (0);
}
