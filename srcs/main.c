/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:00:16 by memelia           #+#    #+#             */
/*   Updated: 2019/05/14 11:03:07 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static	char	**main_help(char *av)
{
	char	**tetra;
	int		fd;

	if ((fd = open(av, O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	if ((tetra = tetr(fd)) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (tetra);
}

static	int		check_ac(int ac)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		return (0);
	}
	return (1);
}

static	char	**cr_m(int size)
{
	char **tetra;

	if (!(tetra = create_field(size)))
	{
		ft_putstr("error\n");
		return (0);
	}
	return (tetra);
}

int				main(int ac, char **av)
{
	char	**tetra;
	t_flist	*begin;
	int		size;

	if (!check_ac(ac))
		return (0);
	if (!(tetra = main_help(av[1])))
		return (0);
	begin = create_flist(tetra);
	free_twin(tetra);
	size = 2;
	while (size * size < list_size(begin) * 4)
		size++;
	if (!(tetra = cr_m(size)))
		return (0);
	while ((solution(tetra, &begin, size)) != 1)
	{
		size++;
		free_twin(tetra);
		tetra = create_field(size);
	}
	print_twin(tetra);
	free_lst(begin, tetra);
	return (0);
}
