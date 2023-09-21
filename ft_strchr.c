/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:13:22 by acoto-gu          #+#    #+#             */
/*   Updated: 2023/09/18 12:48:49 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	my_c;

	my_c = (char) c;
	while (*s != '\0')
	{
		if (*s == my_c)
			return ((char *) s);
		s++;
	}
	if (my_c == '\0')
		return ((char *) s);
	return (NULL);
}
