/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:50:27 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/11 13:18:19 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s2;
	int		start;
	int		end;

	start = 0;
	if (!s)
		return (0);
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start >= end + 1)
		return (NULL);
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (!(s2 = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (0);
	s2[end - start + 1] = 0;
	ft_strncpy(s2, s + start, end - start + 1);
	return (s2);
}
