/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 21:54:33 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:36:09 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		leny(t_line line)
{
	int i;

	i = (line.len + line.plen - 1) / col();
	return (i);
}

void	printn(char *s, int fd)
{
	if (!ft_strchr(s, '\n'))
		ft_putstr_fd(s, fd);
	else
	{
		while (*s)
		{
			if (*s == '\n')
			{
				ft_putstr_fd(RED, fd);
				ft_putchar_fd('N', fd);
				ft_putstr_fd(RESET, fd);
			}
			else
				ft_putchar_fd(*s, fd);
			s++;
		}
	}
}
