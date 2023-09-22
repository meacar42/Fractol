/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:56:38 by meacar            #+#    #+#             */
/*   Updated: 2023/01/14 19:42:35 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

static void	put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->image->bits_per_pixel / 8) + (y
			* fractol->image->size_line);
	fractol->image->data_addr[i] = color.channel[3];
	fractol->image->data_addr[++i] = color.channel[2];
	fractol->image->data_addr[++i] = color.channel[1];
	fractol->image->data_addr[++i] = color.channel[0];
}

static void	draw_fractal_part(t_fractol *fractol)
{
	int		y;
	int		x;
	t_color	color;

	y = -1;
	while (++y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = -1;
		while (++x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(fractol);
			put_pixel(fractol, x, y, color);
		}
	}
}

void	draw_fractal(t_fractol *fractol)
{
	fractol->factor = init_complex((fractol->max.re - fractol->min.re)
			/ (WIDTH), (fractol->max.im - fractol->min.im) / (HEIGHT));
	draw_fractal_part(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window, \
		fractol->image->image, 0, 0);
}
