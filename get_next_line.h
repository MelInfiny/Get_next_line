/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:17:52 by enolbas           #+#    #+#             */
/*   Updated: 2022/01/30 13:19:19 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*trim_buff(char **s_save, char *buff, int status);
char	*read_buff(char **s_save, char *line, int fd);
char	*get_next_line(int fd);

#endif
