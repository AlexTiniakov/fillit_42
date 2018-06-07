/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_rez.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:37:58 by anhloba           #+#    #+#             */
/*   Updated: 2018/04/13 11:40:44 by anhloba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_rez(t_rez *rez, int i)
{
	int j;

	while (++i < rez->size)
	{
		j = -1;
		while (++j < rez->size)
			write(1, &rez->map[j][i], 1);
		write(1, "\n", 1);
	}
}
