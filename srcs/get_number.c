/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:09:41 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 13:11:45 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	remove_prevailing_zeroes(char *str)
{
	int	i;
	int	max;
	
	i = ft_isop(str[0]);
	max = ft_strlen(str) - 1;
	if (!ft_strncmp(str, "0", 2)|| !ft_strncmp(str, "+0", 3) || !ft_strncmp(str, "-0", 3))
	{
		str[0] = '0';
		str[1] = 0;
		return ;
	}
	if (str[0] != '0' || (ft_isop(str[0]) && str[1] != '0'))
		return ;
	while (i < max)
	{
		str[i] = str[i + 1];
		i++;
	}
	return (remove_prevailing_zeroes(str));
}

char	*make_number(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	if (ft_isop(src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	while (src[i] && ft_isdigit(src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	remove_prevailing_zeroes(dest);
	if (dest[0] == 0 || (ft_isop(dest[0]) && dest[1] == 0))
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}

char	*read_number(void)
{
	int		bytes_read;
	char	buf[BUFFER_SIZE + 1];
	char	*str;
	
	bytes_read = read(0, buf, BUFFER_SIZE);
	if (bytes_read < 1)
		return (NULL);
	buf[bytes_read] = 0;
	str = make_number(buf);
	return (str);
}

char	*get_number(int ac, char **av)
{
	char	*str;

	if (ac == 1)
		str = read_number();
	else
		str = make_number(av[1]);
	if (!str)
		write(1, ERROR, 6);
	if (ft_strlen(str) > 39)
	{
		write(1, WORD_ERR, 14);
		free(str);
		str = NULL;
	}
	return (str);
}
