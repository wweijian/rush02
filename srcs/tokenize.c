/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:42:53 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 14:02:15 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include "numbers.h"

char	*get_exponent(int len)
{
	if (len > 36)
		return (UNDECILLION);
	else if (len > 33)
		return (DECILLION);
	else if (len > 30)
		return (NONILLION);
	else if (len > 27)
		return (OCTILLION);
	else if (len > 24)
		return (SEPTILLION);
	else if (len > 21)
		return (SEXTILLION);
	else if (len > 18)
		return (QUINTILLION);
	else if (len > 15)
		return (QUADRILLION);
	else if (len > 12)
		return (TRILLION);
	else if (len > 9)
		return (BILLION);
	else if (len > 7)
		return (MILLION);
	else if (len > 4)
		return (THOUSAND);
	else
		return (NULL);
}

t_num	*tokenize(char *num, int len, t_num **list)
{
	t_num	*node;

	if (len == 0)
		return (NULL);
	node = malloc(sizeof(*node));
	if (!node)
	{
		ft_numclear(*list);
		return(NULL);
	}
	if (ft_isop(*num))
	{
		node->len = 1;
		if (*num == '+')
			node->exponent = PLUS;
		else
			node->exponent = MINUS;
	}
	else
	{
		node->len = len % 3 + (len % 3 == 0) * 3;
		node->exponent = get_exponent(len);
	}
	node->str = num;
	node->next = tokenize(num + node->len, len - node->len, list);
	return (node);
}
