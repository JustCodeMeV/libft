/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:22:11 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/03 17:11:32 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else if (c == EOF)
		return (EOF);
	else if (c > 255)
		return (c);
	else
		return ((unsigned char) c);
}
