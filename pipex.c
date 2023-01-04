/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:10:01 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/04 05:57:45 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc(char **av, char **env, int *fd)
{
	int	id;

	id = open(av[1], O_RDONLY);
	if (id == -1)
		exit_with_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(id, STDIN_FILENO);
	close(fd[0]);
	exec_cmd(av[2], env);
}

void	parent_proc(char **av, char **env, int *fd)
{
	int	id;

	id = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (id == -1)
		exit_with_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(id, STDOUT_FILENO);
	close(fd[1]);
	exec_cmd(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		write(2, "Error: Wrong arguments\n", 24);
		exit(1);
	}
	else
	{
		if (pipe(fd) == -1)
			exit_with_error();
		pid = fork();
		if (pid == -1)
			exit_with_error();
		if (pid == 0)
			child_proc(av, env, fd);
		waitpid(pid, NULL, 0);
		parent_proc(av, env, fd);
	}
	return (0);
}
