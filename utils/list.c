/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:45:51 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 15:39:49 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_lstclear(t_entry *list)
{
	t_entry	*next;

	if (list == NULL)
		return ;
	next = list->next;
	free(list->key);
	free(list->ref);
	free(list);
	return (ft_lstclear(next));
}

void	ft_numclear(t_num *list)
{
	t_num	*next;

	if (list == NULL)
		return ;
	next = list->next;
	free(list);
	return (ft_numclear(next));
}

t_entry	*ft_lstsearch(t_entry *list, char *ref)
{
	t_entry	*search;

	search = list;
	while (search)
	{
		if (!ft_strcmp(ref, search->key))
			break ;
		search = search->next;
	}
	return (search);
}
