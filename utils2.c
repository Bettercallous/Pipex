/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 06:45:42 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/12 05:21:56 by oubelhaj         ###   ########.fr       */
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

int	check_path(char *av, char **envp)
{
	int	i;

	i = 0;
	while (ft_strstr(envp[i], "PATH") == 0)
		i++;
	if (!envp[i])
	{
		write(2, "error: No such file or directory\n", 34);
		return (0);
	}
	else
	{
		if (*av <= 32)
		{
			write(2, "error: command not found\n", 26);
			return (0);
		}
	}
	return (1);
}

void	arg_err(void)
{
	write(2, "error: invalid number of arguments\n", 36);
	exit(1);
}

int	ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (!haystack || !needle)
		return (2);
	while (haystack[i])
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (haystack[i + j] && needle[j]))
			j++;
		if (needle[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}
