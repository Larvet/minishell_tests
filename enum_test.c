/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:42:45 by locharve          #+#    #+#             */
/*   Updated: 2024/03/13 12:45:59 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef enum	e_test
{
	ouais,
	gros
}	t_test;

int	main(void)
{
	t_test	test;
	int		n;

	test = gros;
	n = test.0;
	printf("test = %d\nn = %d\n", test, n);
	return (0);
}
