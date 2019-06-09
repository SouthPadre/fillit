/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:03:33 by mraymon           #+#    #+#             */
/*   Updated: 2019/05/10 16:09:47 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static	int		try_point(char **field, t_flist **begin, int i, int j)
{
	int		a;
	int		x;
	int		y;
	char	c;

	a = 0;
	while (a < 4)
	{
		x = (*begin)->x[a];
		y = (*begin)->y[a];
		if (!(field[j + y])
				|| !(field[j + y][i + x]) || (field[j + y][i + x] != '.'))
			return (0);
		a++;
	}
	while (--a >= 0)
	{
		x = (*begin)->x[a];
		y = (*begin)->y[a];
		c = (*begin)->alpha;
		field[j + y][i + x] = c;
	}
	return (1);
}

static	int		reset_field(char **field, t_flist **begin, int i, int j)
{
	int		a;
	int		x;
	int		y;
	char	c;

	a = 0;
	while (a < 4)
	{
		x = (*begin)->x[a];
		y = (*begin)->y[a];
		c = (*begin)->alpha;
		field[j + y][i + x] = '.';
		a++;
	}
	return (1);
}

int				solution(char **field, t_flist **begin, int size)
{
	int i;
	int j;

	j = 0;
	if (!(*begin))
		return (1);
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if ((try_point(field, begin, i, j) == 1))
			{
				if ((solution(field, &((*begin)->next), size) == 1))
					return (1);
				else
					reset_field(field, begin, i, j);
			}
			i++;
		}
		j++;
	}
	return (-1);
}
