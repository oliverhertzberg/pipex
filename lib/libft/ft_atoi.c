/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:07:37 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/05 16:00:59 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_flow(int sign)
{
	if (sign < 0)
		return (0);
	return (-1);
}

static int	whitespace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	num;
	long	prev;
	long	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev = num;
		num = (num * 10) + (str[i++] - '0');
		if (num < 0 || prev > num)
			return (check_flow(sign));
	}
	return (sign * num);
}
