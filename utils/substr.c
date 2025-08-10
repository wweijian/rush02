/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:47:01 by weijian           #+#    #+#             */
/*   Updated: 2025/08/10 15:40:01 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size > 0)
	{
		while (j < (size - 1) && src[j])
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}

static char	*empty_str(void)
{
	char	*res;

	res = malloc(1);
	res[0] = 0;
	return (res);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*res;
	char	*src;
	int		res_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (empty_str());
	src = (char *)s + start;
	res_len = len + 1;
	if (ft_strlen(src) < len)
		res_len = ft_strlen(src) + 1;
	res = (char *) malloc(sizeof(char) * res_len);
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, res_len);
	return (res);
}
