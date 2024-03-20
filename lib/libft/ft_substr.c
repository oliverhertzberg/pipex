/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:47:02 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/05 15:59:17 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
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
	while ((s[t.i + start]) && t.i < len)
	{
		t.sub[t.i] = s[t.i + start];
		t.i++;
	}
	t.sub[t.i] = '\0';
	return (t.sub);
}
