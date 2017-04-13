/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:54:19 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/13 18:21:53 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			open_file(char *filename, int red_type)
{
	int		fd;
	int		i;
	char	*name;

	name = ft_strtrim(filename);
	i = 0;
	fd = -1;
	if (red_type == 1 || red_type == 6)
		fd = open(name, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (red_type == 2 || red_type == 5)
		fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (red_type == 3)
		fd = open(name, O_RDONLY);
	ft_strdel(&name);
	if (fd == -1)
		return (ft_err("Open failed", NULL, NULL, -1));
	return (fd);
}
