/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:27:34 by ebakirog          #+#    #+#             */
/*   Updated: 2023/07/06 22:43:32 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*x;

	i = 0;
	len = ft_strlen(s1);
	x = (char *)malloc(sizeof(char) * (len + 1));
	if (!x)
		return (0);
	while (s1[i])
	{
		x[i] = s1[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
