/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:57:04 by ebakirog          #+#    #+#             */
/*   Updated: 2023/07/06 16:50:11 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sx1;
	const unsigned char	*sx2;
	size_t				i;

	i = 0;
	sx1 = (const unsigned char *)s1;
	sx2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (sx1[i] != sx2[i])
		{
			return (sx1[i] - sx2[i]);
		}
		i++;
	}
	return (0);
}
