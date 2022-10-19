/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:32:35 by enolbas           #+#    #+#             */
/*   Updated: 2022/01/14 17:43:54 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s || s[count] == '\0')
		return (0);
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	count;
	size_t	copy;
	size_t	len;
	char	*all;

	count = 0;
	copy = 0;
	len = ft_strlen(s1);
	if (!s1 && !s2)
		return (NULL);
	all = (char *) malloc(sizeof(char) * (len + ft_strlen(s2)) + 1);
	if (!all)
		return (NULL);
	all[0] = '\0';
	while (count < len)
		all[copy++] = s1[count++];
	count = 0;
	while (count < ft_strlen(s2))
		all[copy++] = s2[count++];
	all[copy] = '\0';
	if (len > 0)
		free(s1);
	return (all);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	tmp;
	size_t	size;
	char	*str;

	count = 0;
	tmp = start;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (tmp > size)
		return (ft_strjoin("", ""));
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (count < len && tmp < size)
	{
		str[count++] = s[tmp++];
	}
	str[count] = '\0';
	return (str);
}
