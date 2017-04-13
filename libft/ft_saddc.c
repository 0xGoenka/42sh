/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:32:36 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 12:13:53 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_saddc(char *s, char c, int pos)
{
	char	*r;
	int		i;
	int		k;
	int		len;

	k = 0;
	i = 0;
	len = ft_strlen(s) + 1;
	if (pos > ((int)ft_strlen(s) + 1) || pos < 0)
		return (s);
	r = (char *)malloc(sizeof(char) * len + 1);
	r[ft_strlen(s) + 1] = 0;
	while (i < len)
	{
		if (i == pos)
		{
			r[i] = c;
			k = 1;
		}
		if (s)
			r[i + k] = s[i];
		i++;
	}
	ft_strdel(&s);
	return (r);
}
