/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:21:45 by memelia           #+#    #+#             */
/*   Updated: 2019/05/11 13:22:18 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		ft_valid_symb(char **tetr)
{
	int i;
	int j;

	j = 0;
	while (tetr[j])
	{
		i = 0;
		while (tetr[j][i])
		{
			if (tetr[j][i] != '.' && tetr[j][i] != '#')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_valid_4(char **tetr)
{
	int i;
	int j;
	int counter;

	j = 0;
	counter = 0;
	while (tetr[j])
	{
		if (j % 5 == 4 && !tetr[j][0])
			counter = 0;
		i = 0;
		while (tetr[j][i])
		{
			if (tetr[j][i] == '#')
				counter++;
			i++;
		}
		j++;
		if ((j % 5 == 4 && counter < 4) || counter > 4)
			return (0);
	}
	return (1);
}

int		ft_valid_max(char **tetr)
{
	int j;
	int counter;

	j = 0;
	counter = 1;
	while (tetr[j])
	{
		if (!tetr[j][0])
			counter++;
		j++;
	}
	if (counter > 26)
		return (0);
	return (1);
}

int		ft_valid_len(char **tetr)
{
	int j;
	int len;

	j = 0;
	while (tetr[j])
	{
		len = 0;
		if (j % 5 == 4)
			j++;
		if (!tetr[j])
			continue;
		len = ft_strlen(tetr[j]);
		if (len != 4 || (j % 5 == 4 && len != 0))
			return (0);
		j++;
	}
	return (1);
}
