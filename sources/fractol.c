/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:56:56 by meacar            #+#    #+#             */
/*   Updated: 2023/01/14 16:56:58 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	get_formula(char *name, t_fractol *fractol)
{
	if (ft_strequ(name, "Julia"))
	{
		fractol->check = 'j';
		return (1);
	}
	else if (ft_strequ(name, "Mandelbrot"))
	{
		fractol->check = 'm';
		return (1);
	}
	else if (ft_strequ(name, "Burningship"))
	{
		fractol->check = 'b';
		return (1);
	}
	else
		print_help();
	return (0);
}

t_fractol	*init_fractol(char *name, void *mlx)
{
	t_fractol	*fractol;

	fractol = ft_memalloc(sizeof(t_fractol));
	if (!(fractol))
		terminate(ERR_FRACTOL_INIT);
	fractol->mlx = mlx;
	fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, name);
	if (!(fractol->window))
		terminate(ERR_WINDOW_INIT);
	fractol->image = init_image(mlx);
	set_defaults(fractol);
	if (!(get_formula(name, fractol)))
		terminate(ERR_FRACTAL_NAME);
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, ft_close, fractol);
	mlx_hook(fractol->window, 4, 0, zoom, fractol);
	return (fractol);
}

void	start(char *names)
{
	t_fractol	*fractols;
	void		*mlx;

	mlx = mlx_init();
	fractols = init_fractol(names, mlx);
	draw_fractal(fractols);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		start(argv[1]);
	print_help();
	return (0);
}
