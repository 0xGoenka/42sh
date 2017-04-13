/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrmstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:02:07 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/05 13:33:32 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabrmstr(char **t, char *s)
{
	char	**r;
	int		i;

	r = NULL;
	i = 0;
	if (!t || !*t || !s || !*s)
		return (t);
	while (t[i])
	{
		if (strcmp(s, t[i]) != 0)
			r = ft_tabaddstr(r, t[i]);
		i++;
	}
	ft_tabdel(t);
	return (r);
}
