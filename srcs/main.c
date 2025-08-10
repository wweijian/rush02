/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 09:54:55 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 16:57:39 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int ac, char **av)
{
	t_entry	*dictionary;
	char	*num;
	int		fd;

	if (ac > 3)
		return (0);
	num = get_number(ac, av);
	printf("[main] num : %s\n", num);
	if (!num)
		return (1);
	dictionary = NULL;
	fd = load_dictionary(ac, av, &dictionary);
	if (fd < 0)
		return (1);
	translate(num, dictionary, fd);
	free(num);
	ft_lstclear(dictionary);
	close(fd);
}
