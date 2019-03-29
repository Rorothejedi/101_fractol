/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:14:40 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:32:48 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** -------------------------------------------
** DEFINES PROGRAM SETTINGS
** -------------------------------------------
*/

# define NAME			"Fract'ol 101"
# define THREADS		8
# define W_WIDTH		900
# define W_HEIGHT		900
# define FULL_WIDTH		(W_WIDTH + 350)

/*
** -------------------------------------------
** INCLUDES
** -------------------------------------------
*/

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "./keys.h"
# include "/opt/X11/include/X11/X.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <pthread.h>
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
	int					lock;
	float				n;
	long double			x1;
	long double			x2;
	long double			y1;
	long double			y2;
	long double			z_r;
	long double			z_i;
	long double			tmp;
	long double			zoom;
	int					max;
}						t_fractal;

typedef struct			s_param
{
	int					sens;
	char				*color;
	int					white;
	int					green;
}						t_param;

typedef struct			s_thread
{
	int					id_thread;
	long double			c_r;
	long double			c_i;
	void				*ptr_add;
}						t_thr;

/*
** Main struct
*/

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	clock_t				time;
	int					first;
	t_img				img;
	struct s_fractal	*fr;
	struct s_param		*set;
	struct s_thread		**thr;
}						t_mlx;

/*
** -------------------------------------------
** PROTOTYPES
** -------------------------------------------
**
** main.c
*/

void					main_next(char *fr_name);

/*
** error.c
*/

void					error(char *str);
void					error_free(t_mlx *ptr, char *str);

/*
** struct.c
*/

t_mlx					*struct_init(char *fr_name);
t_fractal				*struct_fractal(char *fr_name);
t_param					*struct_param(void);
t_thr					**struct_thread(t_mlx *ptr);
void					struct_free(t_mlx *ptr);

/*
** graphic.c
*/

t_mlx					*graphic_init(t_mlx *ptr);
int						graphic_trace(t_mlx *ptr);
void					graphic_pixel(t_mlx *ptr, int x, int y,
		unsigned int color);
float					graphic_time(t_mlx *ptr);

/*
** string.c
*/

void					string_init(t_mlx *ptr);
void					string_gen(t_mlx *ptr, double w, double h, char *str);
void					string_active_gen(t_mlx *ptr, double w, double h,
		char *str);
char					*string_count_zoom(long double zoom);

/*
** interface.c
*/
void					interface_real_time(t_mlx *ptr);
void					interface_commands(t_mlx *ptr);
void					interface_active(t_mlx *ptr);

/*
** key.c
*/
int						key_events(int keycode, t_mlx *ptr);
t_mlx					*key_events_other(int keycode, t_mlx *ptr);

/*
** mouse.c
*/
int						mouse_events(int button, int x, int y, t_mlx *ptr);
t_mlx					*mouse_zoom (t_mlx *ptr, long double mx, long double my,
		char *eff);

/*
** color.c
*/
unsigned int			color_rgbtoi(unsigned int r, unsigned int g,
		unsigned int b);
unsigned int			color_performer(char *str, unsigned int color);
t_mlx					*color_change(t_mlx *ptr, char *dir);
t_mlx					*color_change_next(t_mlx *ptr);
t_mlx					*color_change_prev(t_mlx *ptr);

/*
** mandelbrot.c
*/
t_mlx					*mandel_init(t_mlx *ptr);
void					mandel_create(t_mlx *ptr, t_thr *thr, int x, int y);
t_mlx					*mandel_events_key(int keycode, t_mlx *ptr);

/*
** julia.c
*/
t_mlx					*julia_init(t_mlx *ptr);
void					julia_create(t_mlx *ptr, t_thr *thr, int x, int y);
t_mlx					*julia_events_key(int keycode, t_mlx *ptr);
int						julia_events_mouse(int x, int y, t_mlx *ptr);

/*
** bship.c
*/
t_mlx					*bship_init(t_mlx *ptr);
void					bship_create(t_mlx *ptr, t_thr *thr, int x, int y);
t_mlx					*bship_events_key(int keycode, t_mlx *ptr);

/*
** multibrot.c
*/
t_mlx					*multi_init(t_mlx *ptr);
void					multi_create(t_mlx *ptr, t_thr *thr, int x, int y);
t_mlx					*multi_events_key(int keycode, t_mlx *ptr);

/*
** thread.c
*/
int						thread_init(t_mlx *ptr);
void					*thread_compute(void *param);

#endif
