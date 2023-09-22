/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:57:59 by meacar            #+#    #+#             */
/*   Updated: 2023/01/14 16:58:02 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);

size_t				ft_strlen(const char *s);

void				*ft_memalloc(size_t size);

int					ft_strequ(char const *s1, char const *s2);

void				ft_putendl(char const *s);

void				ft_putendl_fd(char const *s, int fd);

#endif
