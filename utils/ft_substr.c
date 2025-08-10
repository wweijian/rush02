/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:51:42 by weijian           #+#    #+#             */
/*   Updated: 2025/08/09 22:20:54 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

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