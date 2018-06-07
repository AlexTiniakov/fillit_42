/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:15:22 by otiniako          #+#    #+#             */
/*   Updated: 2018/04/12 17:33:05 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_make_m_m(int *m, t_point point)
{
	if (m[0] > point.x)
		m[0] = point.x;
	if (m[1] > point.y)
		m[1] = point.y;
	if (m[2] < point.x)
		m[2] = point.x;
	if (m[3] < point.y)
		m[3] = point.y;
}

void	ft_min_max(int *m, int *j, int *k)
{
	*k += 1;
	*j = -1;
	*m = 3;
	*(m + 1) = 3;
	*(m + 2) = 0;
	*(m + 3) = 0;
}

void	ft_list_m_m(t_list *list, int *min_max, int k, int j)
{
	list->tet[k].point[j].x -= min_max[0];
	list->tet[k].point[j].y -= min_max[1];
	list->tet[k].x_max = min_max[2] - min_max[0];
	list->tet[k].y_max = min_max[3] - min_max[1];
}

t_list	*ft_make_list(int nb_of, char c, int i)
{
	t_list	*list;
	int		j;

	if (!(list = (t_list *)malloc(sizeof(list))))
		ft_error(-1, NULL);
	list->nb_of_tets = nb_of;
	while (++i < nb_of)
	{
		list->tet[i].symbol = c++;
		j = -1;
		while (++j < 4)
		{
			list->tet[i].point[j].x = 0;
			list->tet[i].point[j].y = 0;
			list->tet[i].x_max = 3;
			list->tet[i].y_max = 3;
		}
	}
	return (list);
}

t_list	*ft_create_list(char *buf, int i, int k, int j)
{
	t_list	*list;
	int		a[4];
	int		min_max[4];

	if (!(list = ft_make_list((ft_strlen(buf) + 1) / 21, 'A', -1)))
		return (NULL);
	while (*buf && (i = -1))
	{
		j = -1;
		while (++i < 20)
			if (buf[i] == '#')
				a[++j] = i;
		ft_min_max((int *)&min_max, &j, &k);
		while (++j < 4)
		{
			list->tet[k].point[j].x = (a[j] + 1) % 5 - 1;
			list->tet[k].point[j].y = (a[j] + 1) / 5;
			ft_make_m_m((int *)&min_max, list->tet[k].point[j]);
		}
		j = -1;
		while (++j < 4)
			ft_list_m_m(list, (int *)&min_max, k, j);
		buf += 21;
	}
	return (list);
}
