/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:49:48 by aoudin            #+#    #+#             */
/*   Updated: 2016/05/25 18:02:36 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_words_count(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static char	*ft_word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!(word = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		word[i] = s[i];
	word[i] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		w_count;
	int		i;

	if (!s)
		return (NULL);
	w_count = ft_words_count(s, c);
	if (!s || !(tab = (char**)malloc(sizeof(char*) * w_count + 1)))
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			tab[++i] = ft_word(s, c);
		while (*s && *s != c)
			s++;
	}
	tab[++i] = NULL;
	return (tab);
}
