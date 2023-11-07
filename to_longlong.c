/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_longlong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:37:45 by sihlee            #+#    #+#             */
/*   Updated: 2023/11/07 15:47:12 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

long long	to_longlong(const char *str)
{
	int			i;
	long long	flag;
	long long	r;

	flag = 1;
	r = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -flag;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	r = r * flag;
	if (str[i] != 0 || r > LLONG_MAX || r < LLONG_MIN)
		exit(1);
	return (r);
}
