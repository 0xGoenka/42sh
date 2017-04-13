/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:43:27 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 17:55:30 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	error(void)
{
	if (!init_error())
		return (0);
	return (1);
}

bool	init_error(void)
{
	if (!def_term())
	{
		ft_putendl_fd("Init Termcaps failed!", 2);
		return (1);
	}
	return (1);
}
