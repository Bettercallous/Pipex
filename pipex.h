/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:09:55 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/10 08:26:31 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

int		exit_(void);
void	arg_err(void);
int		ft_strlen(const char *str);
char	**get_path_env(char **envp);
void	exec_cmd(char *av, char **env);
int		check_path(char *av, char **envp);
char	**ft_split(char const *s, char c);
char	*find_path(char *cmd, char **envp);
char	*search_paths(char *cmd, char **paths);
int		ft_strnstr(char *haystack, char *needle);
char	*search_paths(char *cmd, char **all_paths);
char	*ft_strjoin(char const *s1, char const *s2);
void	check_slash(char *av, char **cmd, char **env);

#endif
