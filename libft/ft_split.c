/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:56 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 18:04:34 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str_src, char split_char)
{
	int	word_count;
	int	str_index;

	word_count = 0;
	str_index = 0;
	while (str_src[str_index])
	{
		if (str_src[str_index] != split_char)
		{
			word_count++;
			while (str_src[str_index] && str_src[str_index] != split_char)
				str_index++;
		}
		else
			str_index++;
	}
	return (word_count);
}

static int	get_copylen(char const *str_src, int str_idx, char split_char)
{
	int	cpylen;

	cpylen = 0;
	while (str_src[str_idx + cpylen] && str_src[str_idx + cpylen] != split_char)
		cpylen++;
	return (cpylen);
}

static void	*free_strs(char **strs)
{
	int	strs_index;

	strs_index = 0;
	while (strs[strs_index])
		free(strs[strs_index++]);
	free(strs);
	return (NULL);
}

static char	**fill_strs(char **strs, int word_count, char const *str_src,
		char split_char)
{
	int	str_index;
	int	copylen;
	int	i;

	str_index = 0;
	i = 0;
	while (i < word_count)
	{
		while (str_src[str_index] && str_src[str_index] == split_char)
			str_index++;
		copylen = get_copylen(str_src, str_index, split_char);
		strs[i] = ft_substr(str_src, str_index, copylen);
		if (!strs[i])
			return (free_strs(strs));
		str_index += copylen;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char const *str_src, char split_char)
{
	char	**strs;
	int		word_count;

	if (!str_src)
		return (NULL);
	word_count = count_words(str_src, split_char);
	strs = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!strs)
		return (NULL);
	strs = fill_strs(strs, word_count, str_src, split_char);
	if (!strs)
		return (NULL);
	return (strs);
}
