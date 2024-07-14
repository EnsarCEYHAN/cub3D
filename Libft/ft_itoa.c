/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:55:20 by ebakirog          #+#    #+#             */
/*   Updated: 2023/07/11 12:51:53 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0 || num < 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*p;
	long	nbr;

	nbr = n;
	len = ft_numlen(nbr);
	if (n < 0)
	{
		len++;
		nbr = -nbr;
	}
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	while (nbr > 0)
	{
		p[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n < 0)
		p[0] = '-';
	if (n == 0)
		p[0] = '0';
	return (p);
}
