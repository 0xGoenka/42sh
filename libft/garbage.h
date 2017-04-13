/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:14:26 by eleclet           #+#    #+#             */
/*   Updated: 2017/04/10 22:18:00 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGE_H
# define FT_GARBAGE_H

typedef struct			s_garbage
{
	void				*p;
	struct s_garbage	*next;
}						t_garbage;
void					gc_free(void);
void					*gc_alloc(size_t size);
void					*gc_add(void *p);

t_garbage				*g_gc;
t_garbage				*g_current_gc;
#endif
