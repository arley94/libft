/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:42:52 by acoto-gu          #+#    #+#             */
/*   Updated: 2023/09/19 19:07:32 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*ptr;
	int		n_bytes;

	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i + 1])
		i++;
	j = ft_strlen(s1) - 1;
	while (j >= 0 && ft_strchr(set, s1[j]))
		j--;
	n_bytes = j - i + 1;
	ptr = ft_substr(s1, i, n_bytes);
	if (!ptr)
		return (NULL);
	return (ptr);
}*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;

	if (!s1 || !set)
		return (NULL);
	front = 0;
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	back = ft_strlen(s1 + front);
	while (back && ft_strchr(set, (s1 + front)[back]))
		back--;
	return (ft_substr(s1 + front, 0, back + 1));
}
