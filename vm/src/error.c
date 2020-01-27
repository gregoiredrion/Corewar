/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 02:34:43 by lode-spi          #+#    #+#             */
/*   Updated: 2020/01/11 19:14:32 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		perror_msg(char *s, int ret)
{
	perror(s);
	return (ret);
}

int		error_msg(char *file, char *error_msg, int ret)
{
	ft_printf("%s: %s\n", file, error_msg);
	return (ret);
}

int		error_msg2(int file, char *error_msg, int ret)
{
	ft_printf("Champion %d: %s\n", file, error_msg);
	return (ret);
}

int		error_msg3(char *error_msg, int ret)
{
	ft_printf("%s\n", error_msg);
	return (ret);
}

int		error_msg4(char *option, char *s, int ret)
{
	if (ret == UNKNOWN)
		ft_printf("%s %s", s, option);
	return (ret);
}
