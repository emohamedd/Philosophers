/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:59:50 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/15 19:43:14 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	calculate_result(char *str, int start, long long sign)
{
	long long	result;
	int			i;

	result = 0;
	i = start;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10) + (str[i] - '0');
			if ((sign * result) > INT_MAX || (sign * result) < INT_MIN)
				return (0);
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (sign * result);
}

long long	ft_atoi_up(char *str)
{
	long long	sign;
	long long	result;
	int			i;

	result = 0;
	i = 0;
	sign = 1;
	str = ft_strtrim(str, " ");
	if (str[0] == '\0')
		return (0);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	result = calculate_result(str, i, sign);
	free(str);
	return (result);
}
