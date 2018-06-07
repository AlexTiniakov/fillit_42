/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:11:35 by otiniako          #+#    #+#             */
/*   Updated: 2018/04/13 11:55:32 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 546
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_rez
{
	int				size;
	char			map[20][20];
}					t_rez;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tet
{
	char			symbol;
	t_point			point[4];
	int				x_max;
	int				y_max;
}					t_tet;

typedef struct		s_list
{
	t_tet			tet[26];
	int				nb_of_tets;
}					t_list;

void				ft_open_read_tetr(int ret, int fd, char *source_file);
void				ft_error(int fd, char *buf);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
t_list				*ft_create_list(char *buf, int i, int k, int j);
void				ft_map(t_list *list);
void				ft_print_rez(t_rez *rez, int i);
int					ft_sqrt(int i, int qrt);
void				ft_free_rez(t_rez *rez, int i, int j);
void				ft_free_list(t_list *list, int i, int j);

#endif
