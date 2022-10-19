/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:10:44 by enolbas           #+#    #+#             */
/*   Updated: 2022/02/01 18:05:16 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s_save;
	char		*line;

	if (fd < 0)
		return (NULL);
	line = NULL;
	if (s_save)
	{
		if (s_save[0])
		{
			line = trim_buff(&s_save, s_save, 1);
			if (line)
				return (line);
			line = ft_strjoin(line, s_save);
		}
		free(s_save);
		s_save = NULL;
	}
	return (read_buff(&s_save, line, fd));
}

char	*trim_buff(char **s_save, char *buff, int status)
{
	size_t	count;
	size_t	size;
	char	*tmp;

	if (!s_save || !buff)
		return (NULL);
	count = 0;
	size = ft_strlen(buff);
	while (buff[count])
	{
		if (buff[count] == '\n')
		{
			*s_save = ft_substr(buff, count + 1, size);
			tmp = ft_substr(buff, 0, count + 1);
			if (status)
				free(buff);
			return (tmp);
		}
		count ++;
	}
	return (NULL);
}

char	*read_buff(char **save, char *line, int fd)
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	long int	ft_read;

	buff[0] = '\0';
	ft_read = read(fd, buff, BUFFER_SIZE - ft_strlen(line));
	while (ft_read > 0)
	{
		buff[ft_read] = '\0';
		tmp = trim_buff(save, buff, 0);
		if (tmp != NULL)
		{
			line = ft_strjoin(line, tmp);
			free(tmp);
			return (line);
		}
		line = ft_strjoin(line, buff);
		ft_read = read(fd, buff, BUFFER_SIZE);
	}
	if (ft_read == 0 && line)
		return (line);
	else if (line)
		free(line);
	return (NULL);
}
