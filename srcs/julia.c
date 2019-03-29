/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 11:19:50 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:50:48 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Initialise julia.
*/

t_mlx	*julia_init(t_mlx *ptr)
{
	int i;

	i = -1;
	while (++i < THREADS)
	{
		ptr->thr[i]->c_r = 0.285;
		ptr->thr[i]->c_i = 0.01;
	}
	ptr->fr->name = "Julia";
	ptr->fr->lock = 0;
	ptr->fr->x1 = -1.8;
	ptr->fr->x2 = 0.6;
	ptr->fr->y1 = -1.7;
	ptr->fr->y2 = 1.2;
	ptr->fr->z_r = 0;
	ptr->fr->z_i = 0;
	ptr->fr->tmp = 0;
	ptr->fr->zoom = 260;
	ptr->fr->max = 100;
	return (ptr);
}

/*
** Permet la creation de la fractale Julia.
*/

void	julia_create(t_mlx *ptr, t_thr *thr, int x, int y)
{
	int i;

	ptr->fr->z_r = x / ptr->fr->zoom + ptr->fr->x1;
	ptr->fr->z_i = y / ptr->fr->zoom + ptr->fr->y1;
	i = -1;
	while (++i < ptr->fr->max && (ptr->fr->z_r * ptr->fr->z_r + ptr->fr->z_i
				* ptr->fr->z_i) < 4)
	{
		ptr->fr->tmp = ptr->fr->z_r;
		ptr->fr->z_r = ptr->fr->z_r * ptr->fr->z_r - ptr->fr->z_i *
			ptr->fr->z_i + thr->c_r;
		ptr->fr->z_i = 2 * ptr->fr->z_i * ptr->fr->tmp + thr->c_i;
	}
	if (i == ptr->fr->max)
		graphic_pixel(ptr, x, y, ptr->set->white);
	else
		graphic_pixel(ptr, x, y, color_performer(ptr->set->color,
		i * 255 / ptr->fr->max));
}

/*
** Gere les evenements specifiques a Julia.
*/

t_mlx	*julia_events_key(int keycode, t_mlx *ptr)
{
	if (keycode == K_ENTER || keycode == K_NP_ENTER || keycode == K_R)
		ptr = julia_init(ptr);
	else if (keycode == K_MAJ_LT || keycode == K_MAJ_RT || keycode == K_F)
		ptr = bship_init(ptr);
	else if (keycode == K_SPACE && ptr->fr->lock == 0)
		ptr->fr->lock = 1;
	else if (keycode == K_SPACE && ptr->fr->lock == 1)
		ptr->fr->lock = 0;
	return (ptr);
}

/*
** Gere les evenements a la souris specifiques a Julia.
*/

int		julia_events_mouse(int x, int y, t_mlx *ptr)
{
	int i;

	if (ptr->fr->lock == 1)
	{
		i = -1;
		while (++i < THREADS)
		{
			ptr->thr[i]->c_r = x * 0.001 - 0.5;
			ptr->thr[i]->c_i = y * 0.001 - 0.5;
		}
		graphic_trace(ptr);
	}
	return (0);
}
