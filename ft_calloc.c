/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 20:14:02 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/17 20:14:05 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated;
	size_t	divider;

	allocated = NULL;
	divider = size * nmemb;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else if (divider / nmemb != size)
		return (allocated);
	else
	{
		allocated = malloc(nmemb * size);
		if (!allocated)
			return (NULL);
		ft_bzero(allocated, nmemb * size);
		return (allocated);
	}
}
