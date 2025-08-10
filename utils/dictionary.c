/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:03:48 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 18:20:30 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_findnewl(char *str, int index)
{
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	if (str[index] == 0)
		return (-1);
	return (index);
}

int	ft_is_num_entry(char *str, t_index *index, int i)
{
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!(ft_isop(str[i]) || ft_isdigit(str[i])))
		return (0);
	index->key_start = i;
	if (ft_isop(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	index->key_end = i - 1;
	while (str[i] && !(str[i] == ':' || str[i] == '\n'))
		i++;
	if (str[i++] != ':')
		return (0);
	while (str[i] && ft_isspace(str[i]))
		i++;
	index->ref_start = i;
	while (str[i] && str[i] != '\n')
		i++;
	index->ref_end = i - 1;
	return (1);
}

int	ft_is_sign_entry(char *str, t_index *index, int i)
{
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!ft_isop(str[i]))
		return (0);
	index->key_start = i;
	index->key_end = i;
	i++;
	if (!ft_isspace(str[i]) && str[i] != ':')
		return (0);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] != ':')
		return (0);
	i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i] || str[i] == '\n')
		return (0);
	index->ref_start = i;
	while (str[i] && str[i] != '\n')
		i++;
	index->ref_end = i - 1;
	return (1);
}
