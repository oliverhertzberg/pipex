/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:24:06 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/11 14:12:03 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	null_terminate(char **sub, int i)
{
	while ((*sub)[i - 1] == '\'' || (*sub)[i - 1] == '"')
		i--;
	if ((*sub)[i] == '"' && (*sub)[i + 1] == '\'')
		i++;
	if ((*sub)[i] == '\'' && (*sub)[i + 1] == '"')
		i++;
	(*sub)[i] = '\0';
}

void static	trim_start(char const *s, unsigned int *b)
{
	while (s[*b] == '\'' || s[*b] == '"')
		(*b)++;
	if (*b > 1 && s[*b - 1] == '"' && s[*b - 2] == '\'')
		(*b)--;
	if (*b > 1 && s[*b - 1] == '\'' && s[*b - 2] == '"')
		(*b)--;
}

char	*ft_substr3(char const *s, unsigned int start, size_t len, char *flag)
{
	t_substr	t;

	if (!s)
		return (NULL);
	t.s_len = ft_strlen(s);
	if (start > t.s_len || len == 0 || !s)
		return ((char *)ft_calloc(1, 1));
	t.s_len = ft_strlen(s + start);
	if (t.s_len > len)
		t.s_len = len;
	t.sub = (char *)malloc(sizeof(char) * (t.s_len + 1));
	if (!t.sub)
		return (NULL);
	t.i = 0;
	trim_start(s, &start);
	while ((s[t.i + start]) && t.i < len)
	{
		if (s[t.i + start] == '\\')
			start++;
		else
			t.sub[t.i++] = s[t.i + start];
	}
	null_terminate(&t.sub, t.i);
	*flag = 0;
	return (t.sub);
}
