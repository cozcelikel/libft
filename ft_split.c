/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cozcelik <cozcelik@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:11:58 by cozcelik          #+#    #+#             */
/*   Updated: 2025/06/28 12:13:31 by cozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_parts(const char *s, char c)
{
	size_t	count;
	int		in_part;

	count = 0;
	in_part = 0;
	while (*s)
	{
		if (*s != c && in_part == 0)
		{
			in_part = 1;
			count++;
		}
		else if (*s == c)
			in_part = 0;
		s++;
	}
	return (count);
}

static void	free_split(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	split_parts(char **result, const char *s, char c)
{
	int	i ;
	int	j ;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			result[j] = ft_substr(s, start, i - start);
			if (!result[j])
				return (j);
			j++;
		}
	}
	result[j] = NULL;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		ret;

	if (!s)
		return (NULL);
	count = (int)count_parts(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	ret = split_parts(result, s, c);
	if (ret >= 0)
	{
		free_split(result, (size_t)ret);
		return (NULL);
	}
	return (result);
}
