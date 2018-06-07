/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:57:42 by otiniako          #+#    #+#             */
/*   Updated: 2018/04/04 12:58:04 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int fd, char *buf)
{
	if (fd != -1)
		close(fd);
	if (buf)
		ft_memdel((void **)&buf);
	write(1, "error\n", 6);
	exit(2);
}

void	ft_free_rez(t_rez *rez, int i, int j)
{
	while (++i < 20)
		while (++j < 20)
			rez->map[i][j] = '\0';
	rez->size = 0;
	free(rez);
	rez = NULL;
}

void	ft_free_list(t_list *list, int i, int j)
{
	list->nb_of_tets = 0;
	while (++i < 26)
	{
		j = -1;
		list->tet[i].symbol = '\0';
		list->tet[i].x_max = 0;
		list->tet[i].y_max = 0;
		while (++j < 4)
		{
			list->tet[i].point[j].x = 0;
			list->tet[i].point[j].y = 0;
		}
	}
	free(list);
	list = NULL;
}
