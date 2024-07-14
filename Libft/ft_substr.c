/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 03:44:56 by ebakirog          #+#    #+#             */
/*   Updated: 2023/07/10 18:00:26 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*last;

	if (s)
	{
		if (start >= ft_strlen(s) || len == 0)
			return (ft_strdup(""));
		i = 0;
		while (i < len && s[start + i])
			i++;
		last = (char *)malloc(sizeof(char) * i + 1);
		if (!last)
			return (NULL);
		j = 0;
		while (j < i)
		{
			last[j] = s[start + j];
			j++;
		}
		last[j] = '\0';
		return (last);
	}
	return (NULL);
}
