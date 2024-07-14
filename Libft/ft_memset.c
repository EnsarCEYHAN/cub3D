/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:03:40 by ebakirog          #+#    #+#             */
/*   Updated: 2023/07/13 12:48:47 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t c)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)str;
	while (i < c)
	{
		p[i] = value;
		i++;
	}
	return (str);
}
