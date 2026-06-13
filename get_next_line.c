/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:46:08 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/13 20:46:09 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clear_stash(t_stash **head, t_stash *stop)
{
	t_stash	*next;

	while (head && *head && *head != stop)
	{
		next = (*head)->next;
		free((*head)->data);
		free(*head);
		*head = next;
	}
}

void	trim_stash(t_stash **head)
{
	t_stash	*current;
	int		i;
	int		j;

	current = *head;
	while (current)
	{
		i = 0;
		while (i < current->number_of_used_bytes && current->data[i] != '\n')
			i++;
		if (i < current->number_of_used_bytes)
		{
			clear_stash(head, current);
			j = 0;
			while (++i < current->number_of_used_bytes)
				current->data[j++] = current->data[i];
			current->number_of_used_bytes = j;
			if (j == 0)
				clear_stash(head, current->next);
			return ;
		}
		current = current->next;
	}
	clear_stash(head, NULL);
}

char	*extract_line(t_stash *head)
{
	char	*line;
	int		len;

	if (!head)
		return (NULL);
	len = get_line_size(head);
	if (len == 0)
		return (NULL);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	copy_to_line(head, line);
	return (line);
}

int	fill_stash(int fd, t_stash **head)
{
	t_stash	*new_node;
	int		byt_rd;

	while (!has_newline(*head))
	{
		new_node = read_chunk(fd, &byt_rd);
		if (!new_node)
		{
			if (byt_rd == 0)
				return (0);
			return (-1);
		}
		append_node(head, new_node);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_stash	*head = NULL;
	int				status;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	status = fill_stash(fd, &head);
	if (status == -1)
	{
		clear_stash(&head, NULL);
		return (NULL);
	}
	line = extract_line(head);
	if (!line)
	{
		clear_stash(&head, NULL);
		return (NULL);
	}
	trim_stash(&head);
	return (line);
}
