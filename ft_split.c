/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrouxel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:13:10 by vrouxel           #+#    #+#             */
/*   Updated: 2026/07/19 17:13:13 by vrouxel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int		count;
	size_t	i;
	size_t	x;

	count = 0;
	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (s[i] == c)
			x = 0;
		i++;
	}
	return (count);
}

static void	*free_all(char **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	*get_token(const char *s, int head, int tail)
{
	char	*tok;
	int		i;

	i = 0;
	tok = malloc((tail - head + 1) * sizeof(char));
	if (!tok)
		return (NULL);
	while (head < tail)
	{
		tok[i] = s[head];
		i++;
		head++;
	}
	tok[i] = 0;
	return (tok);
}

static char	**tokenize(char **tab, const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		tok;

	i = 0;
	j = 0;
	tok = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && tok < 0)
			tok = i;
		else if ((s[i] == c || i == ft_strlen(s)) && tok >= 0)
		{
			tab[j] = get_token(s, tok, i);
			if (!(tab[j]))
				return (free_all(tab, j));
			tok = -1;
			j++;
		}
		i++;
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char			**tab;

	tab = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	return (tokenize(tab, s, c));
}
