/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:57:10 by meacar            #+#    #+#             */
/*   Updated: 2023/01/14 17:01:59 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

t_color	get_color(t_fractol *fractol)
{
	t_color	color;
	double	iteration;
	double	t;

	if (fractol->check == 'm')
		iteration = iterate_mandelbrot(fractol);
	else if (fractol->check == 'j')
		iteration = iterate_julia(fractol);
	else
		iteration = iterate_burningship(fractol);
	t = iteration / ITER;
	color.channel[0] = 0;
	color.channel[(fractol->color_shift) % 3 + 1] = 5 * pow((t - 1), 2) \
		* t * 255;
	color.channel[(1 + fractol->color_shift) % 3 + 1] = 2 * pow((t - 1), 2) \
		* t * 255;
	color.channel[(2 + fractol->color_shift) % 3 + 1] = 4 * pow((t - 1), 2) \
		* t * 255;
	return (color);
}

void	print_help(void)
{
	ft_putendl("Usage: ./fractol <name>");
	ft_putendl("\n");
	ft_putendl("List of available fractals:");
	ft_putendl(" * Mandelbrot");
	ft_putendl(" * Julia");
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!(ptr))
		ft_bzero(ptr, size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
}
