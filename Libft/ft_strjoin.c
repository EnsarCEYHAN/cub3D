/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:57:26 by ebakirog          #+#    #+#             */
/*   Updated: 2023/07/13 14:22:59 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_max;
	char	*final;

	if (!s1 || !s2)
		return (0);
	size_max = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = (char *)malloc(sizeof(char) * size_max);
	if (!final)
		return (0);
	ft_strlcpy(final, s1, ft_strlen(s1) + 1);
	ft_strlcpy(final + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (final);
}
