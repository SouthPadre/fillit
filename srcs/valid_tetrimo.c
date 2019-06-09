/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetrimo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:17:05 by memelia           #+#    #+#             */
/*   Updated: 2019/05/11 13:23:25 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static	int		ft_valid_tetrimo_str(char **tetr, int i, int j, int connect)
{
	while (tetr[j][i])
	{
		if (tetr[j][i] == '#')
		{
			if (i != 3 && tetr[j][i + 1] == '#')
				connect++;
			if (i != 0 && tetr[j][i - 1] == '#')
				connect++;
			if (tetr[j + 1] && tetr[j + 1][i] && tetr[j + 1][i] == '#')
				connect++;
			if (j != 0 && tetr[j - 1][i] == '#')
				connect++;
		}
		i++;
	}
	return (connect);
}

int				ft_valid_tetrimo(char **tetr)
{
	int i;
	int j;
	int connect;

	connect = 0;
	j = 0;
	while (tetr[j])
	{
		i = 0;
		connect = ft_valid_tetrimo_str(tetr, i, j, connect);
		if (j % 5 == 4 || !tetr[j + 1])
		{
			if (connect != 6 && connect != 8)
				return (0);
			connect = 0;
			j++;
		}
		else
			j++;
	}
	return (1);
}
