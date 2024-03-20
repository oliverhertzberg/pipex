/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:53:00 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/05 15:17:37 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
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
	int	j;
	int	i;
	int	start;
	int	end;

	j = 0;
	i = 0;
	while (j < word_count)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		strings[j++] = ft_substr(s, start, (end - start));
		if (strings[j - 1] == NULL)
		{
			free_all(strings, j - 1);
			return ;
		}
		i++;
	}
	strings[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	strings = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!strings)
		return (NULL);
	assemble(strings, s, c, word_count);
	return (strings);
}
