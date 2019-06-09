/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:23:16 by mraymon           #+#    #+#             */
/*   Updated: 2019/05/10 16:00:05 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void		rebuild(t_flist *lst)
{
	int i;
	int min_x;
	int min_y;

	i = 1;
	min_y = lst->y[0];
	min_x = lst->x[0];
	while (i < 4)
	{
		if (lst->y[i] < min_y)
			min_y = lst->y[i];
		if (lst->x[i] < min_x)
			min_x = lst->x[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		lst->x[i] -= min_x;
		lst->y[i] -= min_y;
		i++;
	}
}

static	t_flist	*new_elem(t_flist *elem)
{
	t_flist *new;

	new = (t_flist*)malloc(sizeof(t_flist));
	if (elem)
	{
		elem->next = new;
		new->back = elem;
		new->alpha = elem->alpha + 1;
	}
	else
	{
		new->back = NULL;
		new->alpha = 'A';
	}
	new->next = NULL;
	return (new);
}

static	void	fiveth_str(int k, t_flist **wl, int *d)
{
	if (k)
		rebuild(*wl);
	*wl = new_elem(*wl);
	*d = 0;
}

static	void	r_n(int i, int k, int *d, t_flist **wl)
{
	(*wl)->x[*d] = i;
	(*wl)->y[*d] = k % 5;
	(*d)++;
}

t_flist			*create_flist(char **tetr)
{
	t_flist	*wl;
	int		i;
	int		k;
	int		d;

	k = 0;
	wl = NULL;
	while (tetr[k])
	{
		i = 0;
		if (k % 5 == 0)
			fiveth_str(k, &wl, &d);
		while (tetr[k][i])
		{
			if (tetr[k][i] == '#')
				r_n(i, k, &d, &wl);
			i++;
		}
		k++;
	}
	rebuild(wl);
	while (wl->back)
		wl = wl->back;
	return (wl);
}
