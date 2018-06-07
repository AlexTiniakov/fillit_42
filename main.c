/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:05:38 by otiniako          #+#    #+#             */
/*   Updated: 2018/04/04 12:52:12 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(void)
{
	write(1, "usage: fillit source_file\n", 26);
	exit(1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_usage();
	ft_open_read_tetr(0, 0, av[1]);
	return (0);
}
