/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:10:01 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/08 14:48:42 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_proc(char **av, int *end, char **env)
{
	int	fd;

	close(end[1]);
	fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		exit_();
	dup2(end[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	exec_cmd(av[3], env);
}

void	child_proc(char **av, int *end, char **env)
{
	int	fd;

	close(end[0]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_();
	dup2(end[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	exec_cmd(av[2], env);
}

int	main(int ac, char **av, char **env)
{
	int		end[2];
	pid_t	pid;

	if (ac != 5)
	{
		write(2, "Error: Wrong arguments\n", 24);
		exit(1);
	}
	else
	{
		if (pipe(end) == -1)
			exit_();
		pid = fork();
		if (pid == -1)
			exit_();
		if (pid == 0)
			child_proc(av, end, env);
		wait(NULL);
		parent_proc(av, end, env);
	}
	return (0);
}
