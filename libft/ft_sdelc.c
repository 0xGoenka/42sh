/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdelc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:36:41 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 12:13:25 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sdelc(char *s, int pos)
{
	char	*r;
	int		len;
	int		i;
	int		k;

	k = 0;
	i = 0;
	len = ft_strlen(s) - 1;
	if (pos < 0 || pos > len)
		return (s);
	r = (char *)malloc(sizeof(char) * len + 1);
	r[len] = 0;
	while (i <= len)
	{
		if (pos == i)
			k = 1;
		r[i] = s[i + k];
		i++;
	}
	ft_strdel(&s);
	return (r);
}
