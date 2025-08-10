/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:01:40 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 10:44:30 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	get_entry_index(char *file, t_index *index)
{
	int	i;

	i = index->current;
	if (!(ft_is_num_entry(file, index, i) || ft_is_sign_entry(file, index, i)))
		index->current = ft_findnewl(file, i) + 1;
	else
		index->current = index->ref_end + 2;
}

void	initialize_index(t_index *index)
{
	index->key_start = 0;
	index->key_end = 0;
	index->ref_start = 0;
	index->ref_end = 0;
	index->current = 0;
}

int	add_to_list(t_entry **dict, char *file, t_index *index)
{
	t_entry	*node;
	t_entry	*search;
	
	node = malloc(sizeof(*node));
	if (!node)
		return (0);	
	node->key = ft_substr(file, index->key_start, index->key_end - index->key_start + 1);
	if (!node->key)
		return (free(node), 0);
	node->ref = ft_substr(file, index->ref_start, index->ref_end - index->ref_start + 1);
	if (!node->ref)
		return (free(node->key), free(node), 0);
	node->ref_len = ft_strlen(node->ref);
	search = *dict;
	if (search)
	{
		while(search->next)
			search = search->next;
		search->next = node;
	}
	else
		*dict = node;
	return (1);
}

int	construct_dictionary(int fd, t_entry **dict)
{
	char	file[FILE_BUFFER + 1];
	int		bytes_read;
	t_index	index;

	bytes_read = read(fd, file, FILE_BUFFER);
	if (bytes_read <= 0)
		return (0);
	file[bytes_read] = 0;
	// printf("[load_dict.c : construct_dictionary]\n------\n%s\n---------\n", file);
	initialize_index(&index);
	while (index.current < bytes_read && index.current >= 0)
	{
		get_entry_index(file, &index);
		if (!add_to_list(dict, file, &index))
		{
			ft_lstclear(*dict);
			return (0);
		}
	}
	return (1);
}

int	load_dictionary(int ac, char **av, t_entry **dict)
{
	int	fd;

	if (ac == 3)
		fd = open(av[2], O_RDWR);
	else
		fd = open(DEFAULT_DICT, O_RDWR);
	if (fd < 0)
	{
		write(1, DICT_ERR, 11);
		return (0);
	}
	if (!construct_dictionary(fd, dict))
		return (close(fd), -1);
	return (fd);
}
