/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:01:05 by mraymon           #+#    #+#             */
/*   Updated: 2019/05/10 16:01:35 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int	list_size(t_flist *begin)
{
	t_flist	*wl;
	int		i;

	wl = begin;
	i = 0;
	while (wl)
	{
		i++;
		wl = wl->next;
	}
	return (i);
}
