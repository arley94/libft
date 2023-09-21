/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:49:43 by acoto-gu          #+#    #+#             */
/*   Updated: 2023/09/17 19:27:43 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"

#define START_CHARACTER -255
#define END_CHARACTER 255

int	test_ft_isfunction(int c, int (*ft_function)(int c),
	int (*std_function)(int c))
{
	int	ft_result;
	int	std_result;

	ft_result = (*ft_function)(c);
	std_result = (*std_function)(c);
	if ((ft_result == std_result) || (ft_result != 0 && std_result != 0))
		return (1);
	return (0);
}

void	test_ft_chars(const char *f_name, int (*ft_function)(int c),
	int (*std_function)(int c))
{
	int	error_count;
	int	start_c;

	error_count = 0;
	start_c = START_CHARACTER;
	while (start_c <= END_CHARACTER)
	{
		if (!test_ft_isfunction(start_c, ft_function, std_function))
		{
			error_count++;
			printf("\nERROR with character [%d]:\n", start_c);
			printf("%15s: %10d\n", f_name, ft_function(start_c));
			printf("%15s: %10d\n\n", "std", std_function(start_c));
		}
		start_c++;
	}
	if (error_count == 0)
		printf("%15s: OK!\n", f_name);
}

int	main(void)
{
	test_ft_chars("ft_isalpha", ft_isalpha, isalpha);
	test_ft_chars("ft_isdigit", ft_isdigit, isdigit);
	test_ft_chars("ft_isalnum", ft_isalnum, isalnum);
	test_ft_chars("ft_isascii", ft_isascii, isascii);
	test_ft_chars("ft_isprint", ft_isprint, isprint);
}
