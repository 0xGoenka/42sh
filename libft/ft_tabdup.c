/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:41:26 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 12:05:18 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **src)
{
	char	**r;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	r = NULL;
	r = (char **)malloc(sizeof(char *) * (ft_tablen(src) + 1));
	r[ft_tablen(src)] = 0;
	while (src[i])
	{
		r[i] = ft_strdup(src[i]);
		i++;
	}
	return (r);
}
