/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:21:38 by uclement          #+#    #+#             */
/*   Updated: 2023/09/18 16:12:00 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

volatile int var;

#include "minishell.h"


// void	p_process(void)
// {
// }

// void	c_process(char *av, char **ev)
// {
// 	char	*cmd;
// 	char	**path;
// 	sig_t	old_signal;

// 	path = ft_split_pipex(av, ' ');
// 	old_signal = signal(SIGINT, sigint_handler);
// 	if (pathfinder(ev) == NULL)
// 	{
// 		if (execve(path[0], path, ev) == -1)
// 			msg_error(av, "command not found", 127);
// 	}
// 	else
// 	{
// 		cmd = cmd_maker(ev, path);
// 		if (cmd != NULL)
// 			execve(cmd, path, ev);
// 		else
// 		{
// 			msg_error(av, "command not found", 127);
// 			free(cmd);
// 			free_lst(path);
// 		}
// 	}
// }


// void	new_process(char *av, char **ev)
// {
// 	var = fork();
// 	if (var)
// 		p_process();
// 	else
// 		c_process(av, ev);
// 	waitpid(var, NULL, 0);
// }

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		// kill(var, SIGINT);
	}
}


void	signal_maker(void)
{
	// struct sigaction	act;

	// ft_bzero(&act, sizeof(act));
	// sigemptyset(&act.sa_mask);
	// act.sa_handler = &sigint_handler;
	// act.sa_flags = SA_RESTART;
	// sigaction(SIGINT, &act, NULL);
	signal(SIGINT, sigint_handler);

}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	(void)envp;

	signal_maker();
	while (1)
	{
		input = readline ("minishell>");
		if (input)
			add_history (input);
		if (input == NULL || !strcmp(input, "exit"))
			return (0);
		if (syntaxer(input) == 0)
		{
			pipex(argci, input, envp)
		}
	}
	return (0);
}
