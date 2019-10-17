/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sberic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:26:46 by sberic            #+#    #+#             */
/*   Updated: 2019/09/27 17:27:28 by sberic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main(void)
{
	int i;
    int d;
    char *line;

    d = open("ViM.txt", O_RDONLY);
    while ((i = get_next_line(d, &line)) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
	return (0);
}
