/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:42:22 by myeow             #+#    #+#             */
/*   Updated: 2024/01/28 23:49:43 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src, int start, int end)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (str == 0)
		return (0);
	i = -1;
	while (++i <= end - start)
		str[i] = src[start + i];
	str[i] = 0;
	return (str);
}

int	is_separator(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (c == charset[i])
			return (1);
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = -1;
	while (str[++i])
	{
		if ((i == 0 || is_separator(str[i - 1], charset)) && \
				!is_separator(str[i], charset))
			++word_count;
	}
	return (word_count);
}

void	append_array(char **array, char *str, int *s, char *charset)
{
	int	i;
	int	start_word_index;

	i = 0;
	while (is_separator(str[i], charset))
		++i;
	start_word_index = -1;
	while (str[i])
	{
		if ((i == 0 || is_separator(str[i - 1], charset)) && \
				!is_separator(str[i], charset))
			start_word_index = i;
		if (is_separator(str[i], charset) && start_word_index != -1)
		{
			array[++(*s)] = ft_strdup(str, start_word_index, i - 1);
			start_word_index = -1;
		}
		++i;
	}
	if (start_word_index != -1)
		array[++(*s)] = ft_strdup(str, start_word_index, i - 1);
}

char	**ft_split(char *str, char *charset)
{
	char	**string_array;
	int		word_count;
	int		s;

	word_count = count_words(str, charset);
	string_array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (string_array == 0)
		return (0);
	s = -1;
	append_array(string_array, str, &s, charset);
	string_array[++s] = 0;
	return (string_array);
}
