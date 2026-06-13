/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:46:01 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/13 20:46:02 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(t_stash *head)
{
	int	i;

	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	i = 0;
	while (i < head->number_of_used_bytes)
	{
		if (head->data[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_line_size(t_stash *head)
{
	int	len;
	int	i;

	len = 0;
	while (head)
	{
		i = 0;
		while (i < head->number_of_used_bytes)
		{
			len++;
			if (head->data[i] == '\n')
				return (len);
			i++;
		}
		head = head->next;
	}
	return (len);
}

void	copy_to_line(t_stash *head, char *line)
{
	int	i;
	int	j;

	j = 0;
	while (head)
	{
		i = 0;
		while (i < head->number_of_used_bytes)
		{
			line[j++] = head->data[i];
			if (head->data[i] == '\n')
			{
				line[j] = '\0';
				return ;
			}
			i++;
		}
		head = head->next;
	}
	line[j] = '\0';
}

void	append_node(t_stash **head, t_stash *new_node)
{
	t_stash	*temporary;

	if (!*head)
	{
		*head = new_node;
		return ;
	}
	temporary = *head;
	while (temporary->next)
	{
		temporary = temporary->next;
	}
	temporary->next = new_node;
}

t_stash	*read_chunk(int fd, int *bytes_read)
{
	t_stash	*new_node;

	*bytes_read = -1;
	new_node = malloc(sizeof(t_stash));
	if (!new_node)
		return (NULL);
	new_node->data = malloc(BUFFER_SIZE);
	if (!new_node->data)
	{
		free(new_node);
		return (NULL);
	}
	*bytes_read = read(fd, new_node->data, BUFFER_SIZE);
	if (*bytes_read <= 0)
	{
		free(new_node->data);
		free(new_node);
		return (NULL);
	}
	new_node->number_of_used_bytes = *bytes_read;
	new_node->next = NULL;
	return (new_node);
}
