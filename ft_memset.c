/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassaak <mmassaak@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:28:41 by mmassaak          #+#    #+#             */
/*   Updated: 2021/05/17 20:37:52 by mmassaak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Function MEMSET
 * Params:
 * 	- b:    destination pointer
 * 	- c:    unsigned char to set 'b'
 * 	- len:  length to set in b
 */


#include "libft.h"

void * ft_memset(void *b, int c, size_t len)
{
	size_t i;
	
	if (!b)
		return NULL;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char) c;
		i++;
	}
	return (b);
}
