/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:06:13 by mraymon           #+#    #+#             */
/*   Updated: 2019/04/10 15:40:36 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	char *s1;

	if (s)
	{
		s1 = (char*)s;
		while (*s1)
			ft_putchar(*s1++);
		ft_putchar('\n');
	}
}
