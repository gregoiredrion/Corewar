/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:33:10 by lode-spi          #+#    #+#             */
/*   Updated: 2018/06/25 12:53:26 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	e_n;

	e_n = n;
	if (e_n < 0)
	{
		e_n = -e_n;
		ft_putchar_fd('-', fd);
	}
	if (e_n > 9)
	{
		ft_putnbr_fd(e_n / 10, fd);
		ft_putnbr_fd(e_n % 10, fd);
	}
	else
		ft_putchar_fd(e_n + 48, fd);
}
