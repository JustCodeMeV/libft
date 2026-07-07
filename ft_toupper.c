/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 16:53:49 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/03 17:09:18 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c == EOF)
		return (EOF);
	else if (c > 255)
		return (c);
	else
		return ((unsigned char) c);
}
