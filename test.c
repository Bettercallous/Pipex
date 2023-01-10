#include "pipex.h"

char	**get_path_env(char **envp)
{
	int i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH") == 0)
		i++;
	if (envp[i])
		return (ft_split(envp[i] + 5, ':'));
	return (0);
}

char	*find_path_in_all_paths(char *cmd, char **all_paths)
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
		write(2, "command not found\n", 19);
	return (path);
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