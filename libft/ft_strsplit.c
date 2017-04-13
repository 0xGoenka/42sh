/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:28:07 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 12:06:10 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char *s, char c)
{
	char	**r;
	char	*ptr;
	int		i;
	int		wrd;

	if (!s)
		return (NULL);
	if ((wrd = ft_wrdnbr(s, c)) == 0)
		return (NULL);
	i = 0;
	r = (char **)malloc(sizeof(char *) * (wrd + 1));
	r[wrd] = NULL;
	while (i < wrd)
	{
		while (*s && *s == c)
			s++;
		ptr = s;
		while (*ptr && *ptr != c)
			ptr++;
		r[i] = ft_strndup(s, ptr - s);
		s = ptr;
		i++;
	}
	return (r);
}
