/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:23:24 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/18 14:23:26 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (!s || *s == 0)
		return (NULL);
	size = ft_strlen(s);
	if (start > size || !len)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	sub = ft_calloc(len * sizeof(char) + 1, 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
