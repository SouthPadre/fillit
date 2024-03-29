/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:52:58 by mraymon           #+#    #+#             */
/*   Updated: 2019/04/12 16:30:42 by mraymon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;
	char	*s1;

	n = 0;
	s1 = (char*)str;
	while (*s1)
	{
		n++;
		s1++;
	}
	return (n);
}
