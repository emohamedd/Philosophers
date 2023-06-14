/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_need.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:02:43 by emohamed          #+#    #+#             */
/*   Updated: 2023/06/14 17:48:07 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}
int	check_char(char  c, char  *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}
char	*ft_substr(char  *s,  int start, int len)
{
	char	*p;
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) < len)
		p = malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		while (s[start] && i < len)
		{
			p[i] = s[start];
			i++;
			start++;
		}
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	begin;
	int	end;

	begin = 0;
	if (!s1 || !set)
		return (NULL);
	begin = 0;
	end = ft_strlen(s1) - 1;
	while (s1[begin] && check_char(s1[begin], set))
		begin++;
	while (end >= begin && check_char(s1[end], set))
		end--;
	return (ft_substr(s1, begin, end - begin + 1));
	free(s1);
}