/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erenyasar <erenyasar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:32:32 by erenyasar         #+#    #+#             */
/*   Updated: 2024/11/30 23:01:19 by erenyasar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
    size_t  c;
    
    c = 0;
    if (!str)
    {
        return (0);
    }
    while (str[c] != '\0')
    {
        c++;
    }
    return (c);
}

char    *ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    if (!s)
    {
        return (NULL);
    }
    //pointing to end of the string
    if (c == '\0')
    {
        return ((char *)&s[ft_strlen(s)]);
    }
    while (s[i] != '\0')
    {
        if (s[i] == (char) c)
        {
            return ((char *)&s[i]);
        }
        i++;
    }
    return (NULL);
}

char    *ft_strjoin(char *s1, char *s2)
{
    size_t  i;
    size_t  c;
    char    *str;

    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
    {
        return (NULL);
    }
    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
    {
		return (NULL);
    }
    i = 0;
    c = 0;
    if (s1)
    {
        while (s1[i] != '\0')
        {
            str[i] = s1[i];
            i++;
        }
    }
    while (s2[c] != '\0')
    {
        str[i] = s2[c];
        i++;
        c++;
    }
    str[i] = '\0';
    free(s1);
    return (str);
}