/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 11:01:02 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 16:24:07 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Gere les evenements.
*/

int		events_init(t_mlx *ptr)
{
	mlx_hook(ptr->win, 2, (1L << 0), events_key, (void*)ptr);
	mlx_mouse_hook(ptr->win, events_mouse, ptr);
	return (0);
}

/*
** Permet de gerer les differents evenements au clavier (deplacements, quitter)
*/

int		events_key(int keycode, t_mlx *ptr)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_image(ptr->mlx, ptr->img.i);
		mlx_destroy_window(ptr->mlx, ptr->win);
		struct_free(ptr);
		exit(EXIT_SUCCESS);
	}
	if (ft_strcmp("Mandelbrot", ptr->fr->name) == 0)
		ptr = events_key_mandel(keycode, ptr);
	/*else if (ft_strcmp("Julia", ptr->fr->name) == 0)
		ptr = events_key_julia(keycode, ptr);*/
	ptr = events_key_other(keycode, ptr);
	graphic_trace(ptr);
	return (0);
}

t_mlx	*events_key_mandel(int keycode, t_mlx *ptr)
{
	if (keycode == K_ARR_UP)
		ptr->man->y1 += ptr->set->sens / ptr->man->zoom;
	else if (keycode == K_ARR_DN)
		ptr->man->y1 -= ptr->set->sens / ptr->man->zoom;
	else if (keycode == K_ARR_LT)
		ptr->man->x1 += ptr->set->sens / ptr->man->zoom;
	else if (keycode == K_ARR_RT)
		ptr->man->x1 -= ptr->set->sens / ptr->man->zoom;
	else if (keycode == K_P)
		ptr->man->max += ptr->set->sens;
	else if (keycode == K_O && ptr->man->max * ptr->set->sens > 0)
		ptr->man->max -= ptr->set->sens;

	else if (keycode == K_N) // test dezoom
	{
		ptr->man->zoom -= ptr->man->zoom * ptr->set->sens / 100;
	}
	else if (keycode == K_M) // test zoom
	{
		ptr->man->zoom += ptr->man->zoom * ptr->set->sens / 100;
	}
	else if  (keycode == K_R) // Reinitialisation
		ptr->man = struct_mandel();
	return (ptr);
}


t_mlx	*events_key_other(int keycode, t_mlx *ptr)
{
	//printf("key: %i\n", keycode);
	if (keycode == K_NP_PLUS && ptr->set->sens < 50)
		ptr->set->sens++;
	else if (keycode == K_NP_MINUS && ptr->set->sens > 1)
		ptr->set->sens--;
	else if (keycode == K_NP_ENTER)
		ptr->set->sens = 1;
	return (ptr);
}

int		events_mouse(int button, int x, int y, t_mlx *ptr)
{
	double h;

	h = 1.2;
	printf("x : %i / y : %i\n", x, y);
	if (button == M_WHEEL_DN) // test zoom
	{
		ptr->man->zoom += ptr->man->zoom * ptr->set->sens / (10 * ptr->set->sens);
		ptr->man->y_min -= ptr->set->sens;
		ptr->man->x_min -= ptr->set->sens;
		printf("y_min : %d\nx_min : %d\n", ptr->man->y_min, ptr->man->x_min);
	}
	else if (button == M_WHEEL_UP) // test dezoom
	{
		ptr->man->zoom -= ptr->man->zoom * ptr->set->sens / (10 * ptr->set->sens);
		ptr->man->y_min += ptr->set->sens - ptr->set->sens;
		ptr->man->x_min += ptr->set->sens - ptr->set->sens;


	}
	graphic_trace(ptr);
	return (0);
}

/*t_mlx	*events_key_julia(int keycode, t_mlx *ptr)
{
	return (ptr);
}*/
