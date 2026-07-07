/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:45:35 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/03 18:13:20 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little || *little == '\0')
		return ((char *)big);
	else if (!big || *big == '\0')
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len && little[j])
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
