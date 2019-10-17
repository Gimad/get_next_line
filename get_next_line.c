/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:33:25 by sberic            #+#    #+#             */
/*   Updated: 2019/10/09 18:40:14 by sberic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_line(char **result, char **line, int fd)
{
	char	*temp;
	int		len;

	len = 0;
	while (result[fd][len] != '\n' && result[fd][len] != '\0')
		len++;
	if (result[fd][len] == '\n')
	{
		*line = ft_strsub(result[fd], 0, len);
		temp = ft_strdup(result[fd] + len + 1);
		free(result[fd]);
		result[fd] = temp;
		if (result[fd][0] == '\0')
			ft_strdel(&result[fd]);
	}
	else if (result[fd][len] == '\0')
	{
		*line = ft_strdup(result[fd]);
		ft_strdel(&result[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*result[12000];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	if (fd < 0 || line == NULL || fd > 12000)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (result[fd] == NULL)
			result[fd] = ft_strnew(1);
		temp = ft_strjoin(result[fd], buffer);
		free(result[fd]);
		result[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (result[fd] == NULL || result[fd][0] == '\0'))
		return (0);
	return (ft_line(result, line, fd));
}
