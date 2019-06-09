/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:21:06 by memelia           #+#    #+#             */
/*   Updated: 2019/05/11 14:32:27 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	free_lst(t_flist *begin, char **field)
{
	free_twin(field);
	while (begin->next)
	{
		begin = begin->next;
		free(begin->back);
	}
	free(begin);
}
