/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:57:18 by meacar            #+#    #+#             */
/*   Updated: 2023/01/14 16:57:21 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;
	int	j;
	int	k;

	j = ft_strlen(s1);
	i = 0;
	k = 0;
	if (s1 && s2)
	{
		while (s1[i])
		{
			if (s1[i] == s2[i])
				k++;
			i++;
		}
		if (j == k)
			return (1);
		return (0);
	}
	return (0);
}

void	ft_putendl(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void	ft_putendl_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
