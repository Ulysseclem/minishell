/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:33:15 by uclement          #+#    #+#             */
/*   Updated: 2023/09/18 14:31:35 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
CAS A GERER

Input : > |
Output: |

Input  : >|  \  >>|
Output : \n

Input  : >>>|
Output : >|

Input  : > <>
Output : <>

Input  :
Output :
	*/
int	syntaxer(char *input)
{
	if (check_pipe(input) == 1)
		return (1);
	if (append_in(input) == 1)
		return (1);

	else if (ft_strncmp(input, "&&", 2) == 0 || ft_strncmp(input, ";;", 2) == 0)
		return (err(ft_substr(&input[0], 0 , 2)));
	return (0);
}
	// pipe entre append (|) / rien entre entre deux pipe (|)

int	ft_isspace(int c)
{
	if (c > 9 && c < 13)
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	doublon(char *input)
{
	if (input[0] == input[1])
		return (2);
	else
		return (1);
}

int	check_pipe(char *input)
{
	int	i;

	i = 0;
	while (ft_isspace(input[i]) != 0)
		i++;
	if (input[i] == '|')
		return (err(ft_substr(&input[0], i , doublon(&input[i]))));
	while (input[i])
	{
		if (input[i] == '|')
		{
			if (ft_isspace(input[i + 1]) != 0)
			{
				i++;
				while (ft_isspace(input[i]) != 0)
					i++;
				if (input[i] == '|')
					return (err(ft_substr(&input[0], i , doublon(&input[i]))));
			}
		}
		i++;
	}
	return (0);
}
