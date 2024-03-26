/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fd_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:36 by locharve          #+#    #+#             */
/*   Updated: 2024/03/26 16:51:56 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	handle_fd_redir(char *str, int *count)
{
	long long	check;
	int			i;

	check = ft_atoll(str);
	if (check < 0 || check > 1023)
	{
		print_error("");
		return (-1);	////// error
	i = 0;
	while (is_digit(str[i]))
		i++;
	if (str[i] == '<' || '>')
		i++;
	if (str[i] == '&')
		i++;
	check = ft_atoll(&str[i]);
	if (check < 0 || check > 1023)
		return (-1);
	while (is_digit(str[i]))
		i++;
	return (i);
}

int	handle_fd_redir(char *str, int *count)
