/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:04:20 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/24 09:23:46 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < size)
	{
		*dest++ = *src++;
		i++;
	}
	if (size > 0)
		*dest = 0;
	while (*src++)
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buff, t_list *node)
{
	char	*ret;
	int		len1;
	int		len2;

	len1 = get_len(str);
	len2 = get_len(buff);
	ret = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ret)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(ret, str, len1 + 1);
	ft_strlcpy(ret + len1, buff, len2 + 1);
	free(str);
	ft_strlcpy(node->save, buff + len2, BUFFER_SIZE + 1 - len2);
	return (ret);
}

t_list	*find_fd_node(t_list **list, int fd)
{
	t_list	*new;
	t_list	*node;
	t_list	*node2;

	node = *list;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node2 = node;
		node = node->next;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->save[0] = 0;
	new->next = NULL;
	if (!*list)
		*list = new;
	else
		node2->next = new;
	return (new);
}

char	*ft_free(t_list **list, t_list *node, char *str)
{
	t_list	*cur;
	t_list	*prev;

	cur = *list;
	if (cur->fd == node->fd)
		*list = cur->next;
	else
	{
		while (cur->fd != node->fd)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
	}
	free(cur);
	if (str)
		free(str);
	return (NULL);
}
