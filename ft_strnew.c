/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:39:12 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/30 12:33:46 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew(size_t size)
{
	char *v;
	char c;

	c = 0;
	v = (char *)malloc(size + 1);
	if (!v)
		return (NULL);
	ft_memset(v, 0, size + 1);
	return (v);
}
