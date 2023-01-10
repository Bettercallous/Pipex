/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 06:45:42 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/10 06:45:57 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_(void)
{
	perror("error");
	exit(1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	check_cmd(char *av)
{
	if (*av <= 32)
	{
		write(2, "command not found\n", 19);
		return (0);
	}
	return (1);
}

void	arg_err(void)
{
	write(2, "Error: Wrong arguments\n", 24);
	exit(1);
}
