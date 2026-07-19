/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:53:49 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/19 14:53:51 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
Allocates memory (using malloc(3)) and returns a
copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;
	size_t	i;

	if (!set)
		return (ft_strdup(s1));
	if (!s1 || *s1 == 0)
		return (ft_strdup(""));
	i = 0;
	head = 0;
	tail = 0;
	while (ft_strchr(set, s1[i++]))
		head++;
	while (ft_strrchr(set, s1[ft_strlen(s1) - 1 - tail]))
		tail++;
	return (ft_substr(s1, head, ft_strlen(s1) - tail - head));
}
