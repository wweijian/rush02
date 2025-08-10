/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:54:02 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 09:46:53 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	char		*destbuf;
	const char	*srcbuf;

	if (!dest && !src)
		return (0);
	if (n == 0 || (dest == src))
		return (dest);
	destbuf = (char *)dest;
	srcbuf = (const char *)src;
	while (n != 0)
	{
		if (*destbuf != *srcbuf)
			*destbuf = *srcbuf;
		destbuf++;
		srcbuf++;
		n--;
	}
	return (dest);
}
