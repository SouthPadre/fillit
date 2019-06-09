/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_puzzle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:01:48 by mraymon           #+#    #+#             */
/*   Updated: 2019/05/10 16:02:27 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static	void	print_lst(t_flist *lst)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putstr("x = ");
		ft_putnbr(lst->x[i]);
		ft_putstr(" && y = ");
		ft_putnbr(lst->y[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("\n");
}

void			print_puzzle(t_flist *begin)
{
	t_flist *wl;

	wl = begin;
	while (wl)
	{
		print_lst(wl);
		wl = wl->next;
	}
}
