/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:21:26 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 18:14:23 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "numbers.h"

void	write_teens(char *num, t_entry *dictionary, int fd)
{
	if (*num == '9')
		write_ref(NINETEEN, dictionary, fd);
	else if (*num == '8')
		write_ref(EIGHTEEN, dictionary, fd);
	else if (*num == '7')
		write_ref(SEVENTEEN, dictionary, fd);
	else if (*num == '6')
		write_ref(SIXTEEN, dictionary, fd);
	else if (*num == '5')
		write_ref(FIFTEEN, dictionary, fd);
	else if (*num == '4')
		write_ref(FORTEEN, dictionary, fd);
	else if (*num == '3')
		write_ref(THIRTEEN, dictionary, fd);
	else if (*num == '2')
		write_ref(TWELVE, dictionary, fd);
	else if (*num == '1')
		write_ref(ELEVEN, dictionary, fd);
}

void	write_ones(char *num, t_entry *dictionary, int fd)
{
	if (*num == '9')
		write_ref(NINE, dictionary, fd);
	else if (*num == '8')
		write_ref(EIGHT, dictionary, fd);
	else if (*num == '7')
		write_ref(SEVEN, dictionary, fd);
	else if (*num == '6')
		write_ref(SIX, dictionary, fd);
	else if (*num == '5')
		write_ref(FIVE, dictionary, fd);
	else if (*num == '4')
		write_ref(FOUR, dictionary, fd);
	else if (*num == '3')
		write_ref(THREE, dictionary, fd);
	else if (*num == '2')
		write_ref(TWO, dictionary, fd);
	else if (*num == '1')
		write_ref(ONE, dictionary, fd);
}

void	write_tens(char *num, t_entry *dictionary, int fd)
{
	if (*num == '9')
		write_ref(NINETY, dictionary, fd);
	else if (*num == '8')
		write_ref(EIGHTY, dictionary, fd);
	else if (*num == '7')
		write_ref(SEVENTY, dictionary, fd);
	else if (*num == '6')
		write_ref(SIXTY, dictionary, fd);
	else if (*num == '5')
		write_ref(FIFTY, dictionary, fd);
	else if (*num == '4')
		write_ref(FORTY, dictionary, fd);
	else if (*num == '3')
		write_ref(THIRTY, dictionary, fd);
	else if (*num == '2')
		write_ref(TWENTY, dictionary, fd);
	else if (*num == '1' && *(num + 1) == '0')
		write_ref(TEN, dictionary, fd);
	else if (*num == '1')
		return (write_teens(num + 1, dictionary, fd));
	if (*(num + 1) != '0')
	{
		write(fd, " ", 1);
		return (write_ones(num + 1, dictionary, fd));
	}
}

void	write_hundreds(char *num, t_entry *dictionary, int len, int fd)
{
	if (len < 3)
	{
		if (len == 2)
			write_tens(num, dictionary, fd);
		else
			write_ones(num, dictionary, fd);
		return ;
	}
	else if (*num != '0')
	{
		write_ones(num, dictionary, fd);
		write(fd, " ", 1);
		write_ref(HUNDRED, dictionary, fd);
		if (!(*(num + 1) == '0' && *(num + 2) == '0'))
			write(fd, " ", 1);
		else
			return ;
	}
	if (*(num + 1) == '0')
		return(write_ones(num + 2, dictionary, fd));
	else
		return (write_tens(num + 1, dictionary, fd));
}
