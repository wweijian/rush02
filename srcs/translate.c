/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 23:34:10 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 15:15:56 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	just_zeroes(char *num)
{
	num++;
	while (*num)
	{
		if (*num != '0')
			return (0);
		num++;
	}
	return (1);
}

int	find_num(char *num, t_entry *dictionary)
{
	t_entry	*search;
	int		num_len;

	search = ft_lstsearch(dictionary, num);
	if (!search)
		return (0);
	num_len = ft_strlen(num);
	if (*num == '1')
	{
		if (!ft_strcmp(num, "100"))
			return (write(1, "one hundred\n", 12));
		if (num_len % 3 == 1 && just_zeroes(num))
			write(1, "one ", 4);
	}
	write(1, search->ref, ft_strlen(search->ref));
	write(1, "\n", 1);
	return (1);
}

void	translate(char *num, t_entry *dictionary, int fd)
{
	int		len;
	t_num	*num_token;

	if (find_num(num, dictionary))
		return ;
	len = ft_strlen(num);
	num_token = NULL;
	num_token = tokenize(num, len, &num_token);
	if (!num_token)
		return((void) write(2, ERROR, 6));
	write_to_fd(num_token, dictionary, num, fd);
	write_to_fd(num_token, dictionary, num, 1);
	ft_numclear(num_token);
}
