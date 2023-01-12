/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:09:29 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/12 05:21:48 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path_env(char **envp)
{
	int	i;

	i = 0;
	while (ft_strstr(envp[i], "PATH") == 0)
		i++;
	if (envp[i])
		return (ft_split(envp[i] + 5, ':'));
	return (0);
}

char	*search_paths(char *cmd, char **all_paths)
{
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	while (all_paths[i])
	{
		tmp = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (0);
}

char	*find_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*path;

	all_paths = get_path_env(envp);
	path = search_paths(cmd, all_paths);
	if (!path)
		write(2, "error: command not found\n", 26);
	return (path);
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
