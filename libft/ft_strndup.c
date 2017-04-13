/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftstrndup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:40:22 by eleclet           #+#    #+#             */
/*   Updated: 2017/03/17 12:10:07 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s, int len)
{
	char *r;

	r = (char *)malloc(sizeof(char) * len + 1);
	r[len] = 0;
	ft_strncpy(r, s, len);
	return (r);
}
