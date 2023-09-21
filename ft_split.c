/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:35:09 by acoto-gu          #+#    #+#             */
/*   Updated: 2023/09/20 17:38:56 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word_count++;
		i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		s_index;
	int		i;
	int		i_ptr;

	ptr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ptr || !s)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	i_ptr = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			s_index = i;
		else if (s[i] == c && s[i - 1] != c)
			ptr[i_ptr++] = ft_substr(s, s_index, i - s_index);
		if (s[i] != c && s[i + 1] == '\0')
			ptr[i_ptr++] = ft_substr(s, s_index, i - s_index + 1);
		i++;
	}
	ptr[i_ptr] = 0;
	return (ptr);
}
