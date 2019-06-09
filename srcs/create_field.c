/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:21:30 by mraymon           #+#    #+#             */
/*   Updated: 2019/05/10 15:23:03 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

char	**create_field(int size)
{
	char	**field;
	int		j;

	j = 0;
	if (!(field = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (j < size)
	{
		field[j] = ft_strnew(size);
		field[j] = ft_memset(field[j], '.', size);
		j++;
	}
	field[j] = NULL;
	return (field);
}
