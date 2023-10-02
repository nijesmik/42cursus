/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:57:29 by sejinkim          #+#    #+#             */
/*   Updated: 2023/03/24 09:31:06 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			save[BUFFER_SIZE + 1];
	int				fd;
	ssize_t			read_size;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		get_len(char *buff);
void	move_to_save(t_list *node, char *buff, int idx);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char *str, char *buff, t_list *node);
t_list	*find_fd_node(t_list **list, int fd);
char	*ft_free(t_list **list, t_list *node, char *buff);

#endif