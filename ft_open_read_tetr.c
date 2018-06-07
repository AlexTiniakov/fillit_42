/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_read_tetr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:47:34 by otiniako          #+#    #+#             */
/*   Updated: 2018/04/13 11:12:22 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_bond(char *buf, int i, int tet)
{
	while (*buf)
	{
		i = -1;
		tet = 0;
		while (++i < 20)
			if (buf[i] == '#')
			{
				tet += ((i + 1) < 20 && buf[i + 1] == '#') ? 1 : 0;
				tet += ((i - 1) >= 0 && buf[i - 1] == '#') ? 1 : 0;
				tet += ((i + 5) < 20 && buf[i + 5] == '#') ? 1 : 0;
				tet += ((i - 5) >= 0 && buf[i - 5] == '#') ? 1 : 0;
			}
		if (tet != 6)
			if (tet != 8)
				return (1);
		buf += 21;
	}
	return (0);
}

int		ft_check_tetr(char *buf, int i, int sum)
{
	while (*buf)
	{
		i = -1;
		sum = 0;
		while (++i < 20)
		{
			if ((i + 1) % 5 != 0)
			{
				if (buf[i] != '#' && buf[i] != '.')
					return (1);
				if (buf[i] == '#' && ++sum > 4)
					return (2);
			}
			if ((i + 1) % 5 == 0)
				if (buf[i] != '\n')
					return (3);
		}
		if (buf[19] != '\n')
			return (4);
		buf += 21;
	}
	return (0);
}

void	ft_open_read_tetr(int ret, int fd, char *source_file)
{
	char	*buf;
	t_list	*list;

	list = NULL;
	if ((fd = open(source_file, O_RDONLY)) == -1)
		ft_error(fd, NULL);
	buf = ft_strnew(BUF_SIZE);
	if ((ret = read(fd, buf, BUF_SIZE)) > 545 || ((ret + 1) % 21) != 0)
		ft_error(fd, buf);
	*(buf + ret) = '\0';
	if (ft_check_tetr(buf, -1, 0) || ft_check_bond(buf, 0, 0))
		ft_error(fd, buf);
	if (!(list = ft_create_list(buf, -1, -1, 0)))
		ft_error(fd, buf);
	close(fd);
	ft_map(list);
	ft_memdel((void **)&buf);
}
