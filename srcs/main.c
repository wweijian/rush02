/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 09:54:55 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 07:50:55 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int ac, char **av)
{
	char	*num;
	t_entry	*dictionary;

	if (ac > 3)
		return (0);
	num = get_number(ac, av);
	if (!num)
		return (1);
	printf("[main.c : main] num:%s\n", num);
	dictionary = NULL;
	if (!load_dictionary(ac, av, &dictionary))
		return (1);
	// for(t_entry *search = dictionary; search; search = search->next)
	// 	printf("%s:%s\n", search->key, search->ref);
	translate(num, dictionary);
	write(1, "\n", 1);
	free(num);
	ft_lstclear(dictionary);
}
