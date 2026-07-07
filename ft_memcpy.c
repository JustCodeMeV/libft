/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:18:31 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/06 15:39:06 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (!dest || !src || n == 0)
		return (dest);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	dest = (void *)tmp_dest;
	return (dest);
}
