/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:57:51 by meacar            #+#    #+#             */
/*   Updated: 2023/01/14 19:39:52 by meacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define ITER 90
# define JULIAR -0.4
# define JULIAI 0.6

# define WIDTH 980
# define HEIGHT 720

# include "libft.h"
# include <math.h>
# include "../mlxlib/mlx.h"

typedef struct s_color
{
	int			channel[4];
}				t_color;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_image
{
	void		*image;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*window;
	t_image		*image;
	int			max_iteration;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	int			color_shift;
	char		check;
}				t_fractol;

t_image			*init_image(void *mlx);
t_complex		init_complex(double re, double im);
void			set_defaults(t_fractol *fractol);
void			draw_fractal(t_fractol *fractol);
void			draw_help(t_fractol *fractol);
int				iterate_mandelbrot(t_fractol *fractol);
int				iterate_julia(t_fractol *fractol);
t_color			get_color(t_fractol *fractol);
int				ft_close(void *param);
int				key_press(int key, t_fractol *fractol);
int				zoom(int button, int x, int y, t_fractol *fractol);
void			print_help(void);
int				iterate_burningship(t_fractol *fractol);
void			terminate(char *s);

# define ERROR_MESSAGE_H

# define ERR_FRACTOL_INIT "ERROR: Can\'t initialize fractol"
# define ERR_WINDOW_INIT "ERROR: Can\'t initialize window"
# define ERR_IMAGE_INIT "ERROR: Can\'t initialize image"

# define ERR_FRACTAL_NAME "ERROR: No such fractal"

// KEYS

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define MAIN_PAD_ESC 53
# define MAIN_PAD_SPACE 49
# define MAIN_PAD_C 8
# define MAIN_PAD_H 4
# define MAIN_PAD_R 15
# define MAIN_PAD_PLUS 24
# define MAIN_PAD_MINUS 27

// COLORS

# define COLOR_SILVER 0xCCCCCC
# define COLOR_TUNDORA 0x555555

#endif
