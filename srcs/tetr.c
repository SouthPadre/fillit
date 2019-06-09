/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:24:31 by memelia           #+#    #+#             */
/*   Updated: 2019/05/11 13:58:50 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static	char	*read_txt(int fd)
{
	int		ret;
	char	*str;
	char	buf[546];
	char	*tmp;

	ret = 0;
	str = ft_strnew(1);
	while ((ret = read(fd, buf, 100)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	return (str);
}

static	void	ft(char ***tetr1, char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tetr;

	tetr = *tetr1;
	i = 0;
	j = 0;
	k = 0;
	while (str[k])
	{
		while (str[k] != '\n' && str[k] != '\0')
			k++;
		tetr[j++] = ft_strsub(str, i, k - i);
		i = ++k;
	}
	tetr[j] = NULL;
}

char			**tetr(int fd)
{
	char	*str;
	char	**tetr;
	int		i;

	str = read_txt(fd);
	i = ft_strlen(str);
	if (str[i - 1] != '\n' || (i + 1) % 21 != 0)
		return (0);
	if (!(tetr = (char **)malloc(sizeof(char*) * 130)))
		return (0);
	ft(&tetr, str);
	free(str);
	if (!ft_valid_symb(tetr) || !ft_valid_4(tetr) || !ft_valid_max(tetr)
		|| !ft_valid_len(tetr) || !ft_valid_tetrimo(tetr))
		return (0);
	return (tetr);
}
