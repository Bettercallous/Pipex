/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:09:55 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/09 22:15:49 by oubelhaj         ###   ########.fr       */
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
void    arg_err(void);
void	check_cmds(char **av);
int		ft_strlen(const char *str);
void	exec_cmd(char *av, char **env);
char	**ft_split(char const *s, char c);
char	*find_path(char *cmd, char **env);
int		ft_strnstr(char *haystack, char *needle);
char	*ft_strjoin(char const *s1, char const *s2);
void	check_slash(char *av, char **cmd, char **env);

#endif
