/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:12:46 by icaharel          #+#    #+#             */
/*   Updated: 2023/09/18 16:07:19 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "libft.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAILURE 0

typedef struct s_cmd{
	char			*path;
	char			**name;
	pid_t			pid;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_arg {
	int	in;
	int	out;
	int	err;
}	t_arg;

int		pipex(int argc, char **argv, char *env[]);
int		len(t_cmd *head);
int		validator(int argc, char *argv[], char *env[]);
int		*create_pipes(int nbr_pipe, t_cmd *head, char **env);
int		ft_open(char **argv, int argc, t_arg *file);
int		ft_save_command(t_cmd **head, int argc, char **argv, char **path_env);
char	*strfy(char *str);
char	**ft_path_init(char *env[]);
char	*ft_add_path_to_node(char *path);
char	**ft_add_cmd_to_node(char **cmd);
char	**ft_split(char const *s, char c);
void	free_mem(t_cmd *head, char **tab);
void	error_custom(char *var, char *error);
void	ft_pipex(t_cmd *head, t_cmd *cmd, t_arg *file, char *env[]);
void	ft_creat_node(t_cmd **head, char **command_name, char *command_path);

#endif
