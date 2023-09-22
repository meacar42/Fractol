/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_man_jul_burn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:56:48 by meacar            #+#    #+#             */
/*   Updated: 2023/01/15 05:00:01 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	iterate_mandelbrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < ITER)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + \
			fractol->c.re, 2.0 * z.re * z.im + fractol->c.im);
		iteration++;
	}
	return (iteration);
}

int	iterate_julia(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < ITER)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + \
			fractol->k.re, 2.0 * z.re * z.im + fractol->k.im);
		iteration++;
	}
	return (iteration);
}

int	iterate_burningship(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < ITER)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + \
		fractol->c.re, (-2 * fabs(z.re * z.im)) + fractol->c.im);
		iteration++;
	}
	return (iteration);
}
