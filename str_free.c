/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:46:29 by sihlee            #+#    #+#             */
/*   Updated: 2023/11/07 16:49:34 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsihlee.h"

int	str_free(int cnt, ...)
{
	va_list		args;
	int			count;
	char		*ptr;

	count = 0;
	va_start(args, cnt);
	while (count < cnt)
	{
		ptr = va_arg(args, char *);
		free(ptr);
		ptr = NULL;
		count++;
	}
	va_end(args);
	return (count);
}
