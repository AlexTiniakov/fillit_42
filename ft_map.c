/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:28:31 by otiniako          #+#    #+#             */
/*   Updated: 2018/04/13 11:40:42 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_paste(t_rez *rez, t_point *point, t_tet *tet, char c)
{
	int	i;

	c = c == '.' ? c : tet->symbol;
	i = -1;
	while (++i < 4)
		rez->map[point->x + tet->point[i].x][point->y + tet->point[i].y] = c;
}

int		ft_check(t_rez *rez, t_point *point, t_tet *tet, int i)
{
	int x;
	int y;
	int rezult;

	while (++i < 4)
	{
		x = tet->point[i].x + point->x;
		y = tet->point[i].y + point->y;
		if (x < rez->size && y < rez->size && rez->map[x][y] == '.')
			rezult = 1;
		else
			rezult = 0;
		if (rezult == 0)
			return (rezult);
	}
	ft_paste(rez, point, tet, '#');
	return (1);
}

int		ft_make_map(t_list *list, t_rez *rez, int nb)
{
	t_point	point;
	int		i;

	if (nb > list->nb_of_tets - 1)
		return (1);
	i = -1;
	point.y = 0;
	while (point.y < rez->size - list->tet[nb].y_max)
	{
		point.x = 0;
		while (point.x < rez->size - list->tet[nb].x_max)
		{
			if (ft_check(rez, &point, &list->tet[nb], -1))
			{
				if (ft_make_map(list, rez, nb + 1))
					return (1);
				else
					ft_paste(rez, &point, &list->tet[nb], '.');
			}
			point.x++;
		}
		point.y++;
	}
	return (0);
}

t_rez	*ft_make_rez(int size, int i, int j)
{
	t_rez	*rez;

	if (!(rez = (t_rez *)malloc(sizeof(*rez))))
		return (NULL);
	rez->size = size;
	while (++i < 20)
		while (++j < 20)
			rez->map[i][j] = '\0';
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			rez->map[i][j] = '.';
	}
	return (rez);
}

void	ft_map(t_list *list)
{
	t_rez	*rez;
	int		qrt;

	qrt = ft_sqrt(2, list->nb_of_tets * 4);
	while (!ft_make_map(list, (rez = ft_make_rez(qrt++, -1, -1)), 0))
		ft_free_rez(rez, -1, -1);
	ft_print_rez(rez, -1);
	ft_free_list(list, -1, -1);
}
