/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 23:34:10 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 08:05:14 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_one_then_zeroes(char *num)
{
	if (*num != '1')
		return (0);
	num++;
	while (num)
	{
		if (*num != 0)
			return (0);
		num++;
	}
	return (1);
}

int	find_num(char *num, t_entry *dictionary)
{
	t_entry	*search;
	int		num_len;

	search = dictionary;
	num_len = ft_strlen(num);
	while (search)
	{
		if (!ft_strcmp(num, search->key))
		{
			if (*num == '1')
			{
				if (!ft_strcmp(num, "100"))
					return (write(1, "a hundred", 9));
				if(num_len % 3 == 1 && is_one_then_zeroes(num))
					write(1, "a ", 2);
			}
			write(1, search->ref, ft_strlen(search->ref));
			return (1);
		}
		search = search->next;
	}
	return (0);
}

void	translate(char *num, t_entry *dictionary)
{
	int	len;

	if (find_num(num, dictionary))
		return ;
	len = ft_strlen(num);
	(void)len;
}