/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:03:01 by uclement          #+#    #+#             */
/*   Updated: 2023/09/18 12:48:10 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_append_in(t_syntax *ap, char *c)
{
	if (ap->pos == 1)
		ap->arg1 = ap->count;
	else if (ap->pos == 2)
		ap->arg2 = ap->count;
	ap->pos++;
	if (strncmp(c, ">", 1) == 0)
	{
		if ((ap->arg1 == 1 && ap->arg2 > 1) || ap->arg1 > 3)
			return (err(">>"));
		if ((ap->arg1 == 1 && ap->arg2 == 1) || ap->arg1 == 3)
			return (err(">"));
		if ((ap->arg1 == 1 || ap->arg1 == 2) \
		&& ap->arg2 == 0 && ap->option == 1)
			return (err("newline"));
	}
	else if (strncmp(c, "<", 1) == 0)
	{
		if ((ap->arg1 == 1 && ap->arg2 == 2) || ap->arg1 == 5)
			return (err("<<"));
		if ((ap->arg1 == 1 && ap->arg2 > 2) || ap->arg1 > 5)
			return (err("<<<"));
		if ((ap->arg1 == 1 && ap->arg2 == 1) || ap->arg1 == 4)
			return (err("<"));
		if ((ap->arg1 == 1 || ap->arg1 == 2 || ap->arg1 == 3) \
		&& ap->arg2 == 0 && ap->option == 1)
			return (err("newline"));
	}
	if (ap->arg1 == 2 && ap->arg2 == 1)
		return (err(c));
	return (0);
}

void	init_append(t_syntax *append)
{
	append->arg1 = 0;
	append->arg2 = 0;
	append->count = 0;
	append->pos = 1;
	append->option = 0;
}

int	append_in(char *input)
{
	t_syntax	append;
	int			i;

	init_append(&append);
	i = 0;
	while (input[i])
	{
		if (input[i] == '>' || input[i] == '<')
			append.count++;
		else
		{
			if (append.count != 0)
			{
				if (check_append_in(&append, &input[i]) == 1)
					return (1);
			}
			append.count = 0;
		}
		i++;
		if (ft_isalnum(input[i]) == 1)
			append.pos = 1;
	}
	append.option = 1;
	return (check_append_in(&append, &input[i - 1]));
}


