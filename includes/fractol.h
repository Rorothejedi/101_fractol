/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:14:40 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 15:41:32 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** -------------------------------------------
** DEFINES
** -------------------------------------------
*/

# define W_WIDTH      900
# define W_HEIGHT     900
// # define W_WIDTH      2560
// # define W_HEIGHT     1400
# define NAME         "Fract'ol 101"

# define K_R					15
# define K_O          31
# define K_P          35
# define K_N          45
# define K_M          46

# define K_ESC        53

# define K_NP_PLUS    69
# define K_NP_MINUS   78
# define K_NP_ENTER   76

# define K_ARR_LT     123
# define K_ARR_RT     124
# define K_ARR_DN     125
# define K_ARR_UP     126

# define M_CLIC_LT    1
# define M_CLIC_RT    2
# define M_WHEEL_DN   4
# define M_WHEEL_UP   5

/*
** -------------------------------------------
** INCLUDES
** -------------------------------------------
*/

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>

// A VIRER
# include <stdio.h>

/*
** -------------------------------------------
** STRUCTURES
** -------------------------------------------
*/

/*
** Secondary structs
*/

typedef struct			s_img
{
	void				*i;
	unsigned int		*data;
	int					bpp;
	int					size_l;
	int					endian;
}						t_img;

typedef struct			s_fractal
{
	char				*name;
}						t_fractal;

typedef struct			s_param
{
	int					sens;
	int					white;
	int					green;
}						t_param;

typedef struct			s_mandel
{
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	float				img_x;
	float				img_y;
	float				c_r;
	float				c_i;
	float				z_r;
	float				z_i;
	float				tmp;
	float				zoom;
	int					max;
	int					x_min;
	int					y_min;
}						t_mandel;

/*
** Main struct
*/

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	clock_t				time;
	t_img				img;
	//int					img_x;
	//int					img_y;
	struct s_fractal	*fr;
	struct s_param		*set;
	struct s_mandel		*man;
}						t_mlx;

/*
** -------------------------------------------
** PROTOTYPES
** -------------------------------------------
**
** main.c
*/

void		main_next(char *fr_name, clock_t time_init);

/*
** error.c
*/

void		error(char *str);
void		error_free(t_mlx *ptr, char *str);

/*
** struct.c
*/

t_mlx		*struct_init(char *fr_name, clock_t time_init);
t_fractal	*struct_fractal(char *fr_name);
t_param		*struct_param(void);
t_mandel	*struct_mandel(void);
void		struct_free(t_mlx *ptr);

/*
** graphic.c
*/

t_mlx		*graphic_init(t_mlx *ptr);
int			graphic_trace(t_mlx *ptr);
void		graphic_pixel(t_mlx *ptr, int x, int y, unsigned int color);
float		graphic_time(t_mlx *ptr);

/*
** string.c
*/

void		string_init(t_mlx *ptr);
void		string_gen(t_mlx *ptr, double w, double h, char *str);
void		string_active_gen(t_mlx *ptr, double w, double h, char *str);

/*
** events.c
*/

int			events_init(t_mlx *ptr);
int			events_key(int keycode, t_mlx *ptr);
t_mlx		*events_key_mandel(int keycode, t_mlx *ptr);
t_mlx		*events_key_julia(int keycode, t_mlx *ptr);
t_mlx		*events_key_other(int keycode, t_mlx *ptr);
int			events_mouse(int button, int x, int y, t_mlx *ptr);

/*
** color.c
*/
int			color_rgbtoi(int r, int g, int b);

/*
** mandelbrot.c
*/

void		mandelbrot_init(t_mlx *ptr);

/*
** julia.c
*/

int			julia_init(t_mlx *ptr);


// ftoa.c
void		ft_ftoa(float n, char *res, int afterpoint);

#endif
