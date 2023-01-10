/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:09:29 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/10 08:15:23 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strnstr(char *haystack, char *needle)
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

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	*path;
	char	**paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH") == 0)
		i++;
	if (envp[i])
	{
		paths = ft_split(envp[i] + 5, ':');
		i = 0;
		while (paths[i])
		{
			tmp = ft_strjoin(paths[i], "/");
			path = ft_strjoin(tmp, cmd);
			free(tmp);
			if (access(path, F_OK) == 0)
				return (path);
			free(path);
			i++;
		}
		i = 0;
		while (paths[i])
			free(paths[i++]);
		free(paths);
		write(2, "command not found\n", 19);
	}
	return (0);
}

void	check_slash(char *av, char **cmd, char **env)
{
	if (!av)
		return ;
	if (av[0] == '/')
	{
		if (access(av, X_OK) == 0)
			execve(av, cmd, env);
		exit_();
	}
}

void	exec_cmd(char *av, char **env)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 0;
	cmd = ft_split(av, ' ');
	check_slash(cmd[0], cmd, env);
	path = find_path(cmd[0], env);
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		exit(1);
	}
	if (execve(path, cmd, env) == -1)
		exit_();
}
