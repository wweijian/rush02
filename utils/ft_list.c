/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:45:51 by weijian           #+#    #+#             */
/*   Updated: 2025/08/09 23:38:24 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

/* 
	ft_lstclear
	ft_lstnew;
	ft_lstaddback;
	ft_iteri
*/

void	ft_lstclear(t_entry *list)
{
	t_entry	*temp;
	
	if (list == NULL)
		return ;
	temp = list->next;
	free(list->key);
	free(list->ref);
	free(list);
	return (ft_lstclear(temp));
}