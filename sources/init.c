/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:57:03 by meacar            #+#    #+#             */
/*   Updated: 2023/01/14 19:12:09 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = ft_memalloc(sizeof(t_image));
	if (!(image))
		terminate(ERR_IMAGE_INIT);
	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!(image->image))
		terminate(ERR_IMAGE_INIT);
	image->data_addr = mlx_get_data_addr(image->image, &(image->bits_per_pixel),
			&(image->size_line), &(image->endian));
	return (image);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = ITER;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = 2 * HEIGHT / WIDTH;
	fractol->k = init_complex(JULIAR, JULIAI);
	fractol->color_shift = 0;
}
