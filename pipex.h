/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:09:55 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/01/04 05:59:48 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int		exit_with_error(void);
int		ft_strlen(const char *str);
void	exec_cmd(char *av, char **env);
char	**ft_split(char const *s, char c);
char	*find_path(char *cmd, char **env);
int		ft_strnstr(char *haystack, char *needle);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
