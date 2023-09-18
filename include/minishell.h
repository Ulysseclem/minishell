/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:33:36 by uclement          #+#    #+#             */
/*   Updated: 2023/09/18 12:39:37 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <inttypes.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <signal.h>
# include "libft.h"

typedef struct syntax
{
	int		count;
	int		pos;
	int		arg1;
	int		arg2;
	int		option;
}	t_syntax;

extern volatile int var;
void	signal_maker(void);
void	sigint_handler(int signal);
int	read_lexer(char *input);
int	err(char *str);
int	check_pipe(char *input);
int    ft_isspace(int c);
void	sigint_handler(int signal);
void	new_process(char *av, char **ev);
void	free_lst(char **str);
char	**ft_split_pipex(char const *s, char c);
char	*pathfinder(char **ev);
char	*cmd_maker(char **ev, char **args);
void	msg_error(char *err1, char *err, int nb);

int	syntaxer(char *input);

int		append_in(char *input);
int		check_append_in(t_syntax *ap, char *c);
void	init_append(t_syntax *append);


#endif