/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraymon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:44:46 by mraymon           #+#    #+#             */
/*   Updated: 2019/05/11 15:45:40 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_flist
{
	int				x[4];
	int				y[4];
	char			alpha;
	struct s_flist	*next;
	struct s_flist	*back;
}				t_flist;

int				list_size(t_flist *begin);
char			**tetr(int fd);
t_flist			*create_flist(char **tetr);
void			print_puzzle(t_flist *begin);
void			print_twin(char **field);
void			free_twin(char **field);
char			**create_field(int size);
int				solution(char **field, t_flist **begin, int size);
void			free_lst(t_flist *begin, char **field);
int				ft_valid_symb(char **tetr);
int				ft_valid_len(char **tetr);
int				ft_valid_4(char **tetr);
int				ft_valid_max(char **tetr);
int				ft_valid_tetrimo(char **tetr);
void			print_twin(char **field);

#endif
