/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:00:37 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 15:40:15 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	write_key(char *num, int len, int fd)
{
	write(fd, "\n", 1);
	write(fd, num, len);
	write(fd, ": ", 2);
}

void	write_entry(t_num *num, t_entry *dictionary, int fd)
{
	if (!ft_isop(*(num->str)))
	{
		write_hundreds(num->str, dictionary, num->len, fd);
		write(fd, " ", 1);
	}
	write_ref(num->exponent, dictionary, fd);
	if (!ft_isop(*(num->str)))
	{
		if (num->next && num->next->next)
			write(fd, ",", 1);
		else if (num->next)
			write(fd, " and", 4);
	}
	if (num->next)
	{
		write(fd, " ", 1);
		write_entry(num->next, dictionary, fd);
	}
}

void	write_to_fd(t_num *num_token, t_entry *dictionary, char *num, int fd)
{
	int	len;

	len = ft_strlen(num);
	if (fd != 1)
		write_key(num, len, fd);
	write_entry(num_token, dictionary, fd);
	if (fd == 1)
		write(1, "\n", 1);
}
