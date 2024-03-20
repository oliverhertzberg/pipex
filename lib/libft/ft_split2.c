/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:52:32 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/11 09:54:53 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	count_words2(char const *s, char c)
{
	int		i;
	int		count;
	char	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			flag = s[i++];
			while (s[i] != flag || (s[i - 1] == '\\' && s[i] == flag))
				i++;
			if (s[i - 1] != flag)
				count++;
		}
		if (s[i] != c && (i == 0 || (s[i - 1] == c)))
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **strings, int j)
{
	while (j >= 0)
	{
		free(strings[j]);
		j--;
	}
	free(strings);
	strings = NULL;
}

static void	assemble(char **strings, char const *s, char c, int word_count)
{
	t_split2	x;

	x.j = 0;
	x.i = 0;
	x.f = 0;
	while (x.j < word_count)
	{
		while (s[x.i] == c && s[x.i] != '"' && s[x.i] != '\'')
			x.i++;
		if (s[x.i] == '"' || s[x.i] == '\'')
			x.f = s[x.i++];
		while (x.f && (s[x.i] == '\'' || s[x.i] == '"' || s[x.i] == '\\'))
			x.i++;
		x.start = x.i;
		while (!x.f && s[x.i] != c && s[x.i])
			x.i++;
		while (x.f && (s[x.i] != x.f || (s[x.i] == x.f && s[x.i - 1] == '\\')))
			x.i++;
		x.end = x.i;
		strings[x.j++] = ft_substr2(s, x.start, (x.end - x.start), &x.f);
		if (strings[x.j - 1] == NULL)
			return (free_all(strings, x.j - 1));
		x.i++;
	}
	strings[x.j] = NULL;
}

int static	check_delimiters(char const *s)
{
	int	i;
	int	sgl;
	int	dbl;

	i = 0;
	sgl = 0;
	dbl = 0;
	while (s[i])
	{
		if (s[i] == '"')
			dbl++;
		if (s[i] == '\'')
			sgl++;
		i++;
	}
	if ((sgl % 2) != 0 || (dbl % 2) != 0)
		return (0);
	return (1);
}

char	**ft_split2(char const *s, char c)
{
	char	**strings;
	int		word_count;

	if (!s)
		return (NULL);
	if (!check_delimiters(s))
		return (NULL);
	word_count = count_words2(s, c);
	strings = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!strings)
		return (NULL);
	assemble(strings, s, c, word_count);
	return (strings);
}
