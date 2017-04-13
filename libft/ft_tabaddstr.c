/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabaddstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:43:57 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/02 16:53:23 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabaddstr(char **src, char *str)
{
	char	**r;
	int		len;

	if (!str)
		return (NULL);
	len = ft_tablen(src);
	r = (char **)malloc(sizeof(char *) * (len + 2));
	r[len + 1] = NULL;
	r[len] = ft_strdup(str);
	while (--len >= 0)
		r[len] = ft_strdup(src[len]);
	if (src && *src)
		ft_tabdel(src);
	return (r);
}
