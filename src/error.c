/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:53:48 by uclement          #+#    #+#             */
/*   Updated: 2023/09/18 11:31:41 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	err(char *str)
{
	write(2, "bash: syntax error near unexpected token `", 43);
	write(2, str, ft_strlen(str));
	write(2, "'", 1);
	write(2, "\n", 1);
	return (1);
}
