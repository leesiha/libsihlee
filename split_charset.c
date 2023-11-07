/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihlee <sihlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:25:00 by sihlee            #+#    #+#             */
/*   Updated: 2023/11/07 14:49:36 by sihlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsihlee.h"

int	is_it_charset(char c, char *charset)
{	
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (is_it_charset(*str, charset) && *str)
			str++;
		if (!(is_it_charset(*str, charset)) && *str)
		{
			count++;
			while (!(is_it_charset(*str, charset)) && *str)
				str++;
		}
	}
	return (count);
}

char	*return_word(char *str, char *charset, int *len)
{
	while (is_it_charset(*str, charset) && *str)
		str++;
	while (!(is_it_charset(*(str + *len), charset)) && *(str + *len))
		(*len)++;
	return (str);
}

char	**save_word(char **result, char *str, char *charset, int word)
{
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	while (i < word)
	{
		j = 0;
		str = return_word(str, charset, &len);
		result[i] = malloc(sizeof(char) * (len + 1));
		if (result[i] == NULL)
			return (NULL);
		result[i][len] = 0;
		while (len)
		{
			result[i][j++] = *str;
			str++;
			len--;
		}
		i++;
	}
	return (result);
}

char	**split_charset(char *str, char *charset, int *cnt)
{
	char	**result;
	int		word;

	word = word_count(str, charset);
	*cnt = word;
	result = malloc(sizeof(char *) * (word + 1));
	if (result == NULL)
		return (NULL);
	result[word] = 0;
	return (save_word(result, str, charset, word));
}
