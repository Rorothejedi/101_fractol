/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 17:50:01 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:51:07 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Permet de gerer les differents evenements au clavier (deplacements, quitter)
*/

int		key_events(int keycode, t_mlx *ptr)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_image(ptr->mlx, ptr->img.i);
		mlx_destroy_window(ptr->mlx, ptr->win);
		struct_free(ptr);
		exit(EXIT_SUCCESS);
	}
	if (ft_strcmp("Mandelbrot", ptr->fr->name) == 0)
		ptr = mandel_events_key(keycode, ptr);
	else if (ft_strcmp("Julia", ptr->fr->name) == 0)
		ptr = julia_events_key(keycode, ptr);
	else if (ft_strcmp("Burning_Ship", ptr->fr->name) == 0)
		ptr = bship_events_key(keycode, ptr);
	else if (ft_strcmp("Multibrot", ptr->fr->name) == 0)
		ptr = multi_events_key(keycode, ptr);
	if (ft_strcmp("Julia", ptr->fr->name) == 0 && ptr->fr->lock == 1)
		mlx_hook(ptr->win, MotionNotify, PointerMotionMask, julia_events_mouse,
				ptr);
	ptr = key_events_other(keycode, ptr);
	graphic_trace(ptr);
	return (0);
}

/*
** Gere les evenements communs a toutes les fractales.
*/

t_mlx	*key_events_other(int keycode, t_mlx *ptr)
{
	if (keycode == K_ARR_UP)
		ptr->fr->y1 += ptr->set->sens / ptr->fr->zoom;
	else if (keycode == K_ARR_DN)
		ptr->fr->y1 -= ptr->set->sens / ptr->fr->zoom;
	else if (keycode == K_ARR_LT)
		ptr->fr->x1 += ptr->set->sens / ptr->fr->zoom;
	else if (keycode == K_ARR_RT)
		ptr->fr->x1 -= ptr->set->sens / ptr->fr->zoom;
	else if (keycode == K_P)
		ptr->fr->max += ptr->set->sens;
	else if (keycode == K_O && ptr->fr->max * ptr->set->sens > 0)
		ptr->fr->max -= ptr->set->sens;
	else if (keycode == K_NP_PLUS && ptr->set->sens < 50)
		ptr->set->sens++;
	else if (keycode == K_NP_MINUS && ptr->set->sens > 1)
		ptr->set->sens--;
	else if (keycode == K_NP_STAR)
		ptr->set->sens = 10;
	return (ptr);
}
