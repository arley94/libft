/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 08:46:32 by acoto-gu          #+#    #+#             */
/*   Updated: 2023/09/19 09:42:53 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	this function checks if the character is \t \n \v \f \c 
*/
static int	ft_iscontrol(char c)
{
	if (9 <= c && c <= 13)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int	number;
	int			sign;
	int			i;

	number = 0;
	sign = 1;
	i = 0;
	while ((ft_iscontrol(nptr[i]) || nptr[i] == ' ') && nptr[i])
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(number * sign));
}
