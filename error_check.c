/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:34:38 by sihlee            #+#    #+#             */
/*   Updated: 2023/11/07 14:43:39 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	error_exit(char *msg)
{
	write_check(2, msg, ft_strlen(msg));
	exit(1);
}

ssize_t	write_check(int __fd, const void *__buf, size_t __nbyte)
{
	ssize_t	result;

	result = write(__fd, __buf, __nbyte);
	if (result == -1)
		error_exit("write failed\n");
	return (result);
}
