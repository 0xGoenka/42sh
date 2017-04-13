/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:15:13 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 12:03:35 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wrdnbr(char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	if (s[i - 1] == c)
		j--;
	return (j);
}
