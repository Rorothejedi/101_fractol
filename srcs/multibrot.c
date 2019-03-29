/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multibrot.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 18:06:15 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:38:11 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Initialise multibrot.
*/

t_mlx	*multi_init(t_mlx *ptr)
{
	ptr->fr->name = "Multibrot";
	ptr->fr->lock = 0;
	ptr->fr->n = 6;
	ptr->fr->x1 = -1.8;
	ptr->fr->x2 = 0.6;
	ptr->fr->y1 = -1.7;
	ptr->fr->y2 = 1.2;
	ptr->fr->z_r = 0.0;
	ptr->fr->z_i = 0.0;
	ptr->fr->tmp = 0.0;
	ptr->fr->zoom = 260.0;
	ptr->fr->max = 20;
	return (ptr);
}

/*
** Permet la creation de la fractale Multibrot.
*/

void	multi_create(t_mlx *ptr, t_thr *thr, int x, int y)
{
	int i;

	thr->c_r = x / ptr->fr->zoom + ptr->fr->x1;
	thr->c_i = y / ptr->fr->zoom + ptr->fr->y1;
	ptr->fr->z_r = 0;
	ptr->fr->z_i = 0;
	i = -1;
	while (++i < ptr->fr->max && (ptr->fr->z_r * ptr->fr->z_r + ptr->fr->z_i *
				ptr->fr->z_i) < 4)
	{
		ptr->fr->tmp = ptr->fr->z_r;
		ptr->fr->z_r = pow((double)(ptr->fr->z_r * ptr->fr->z_r + ptr->fr->z_i *
			ptr->fr->z_i), ptr->fr->n / 2) * cos(ptr->fr->n *
				atan2((double)ptr->fr->z_i, (double)ptr->fr->z_r)) + thr->c_i;
		ptr->fr->z_i = pow((double)(ptr->fr->tmp * ptr->fr->tmp + ptr->fr->z_i *
			ptr->fr->z_i), ptr->fr->n / 2) * sin(ptr->fr->n *
				atan2((double)ptr->fr->z_i, (double)ptr->fr->tmp)) + thr->c_r;
	}
	if (i == ptr->fr->max)
		graphic_pixel(ptr, x, y, ptr->set->white);
	else
		graphic_pixel(ptr, x, y, color_performer(ptr->set->color,
			i * 255 / ptr->fr->max));
}

/*
** Gere les evenements specifiques a Multibrot.
*/

t_mlx	*multi_events_key(int keycode, t_mlx *ptr)
{
	if (keycode == K_ENTER || keycode == K_NP_ENTER || keycode == K_R)
		ptr = multi_init(ptr);
	else if (keycode == K_MAJ_LT || keycode == K_MAJ_RT || keycode == K_F)
		ptr = mandel_init(ptr);
	else if (keycode == K_N && ptr->fr->n > 4.1)
		ptr->fr->n -= ptr->set->sens * 0.1;
	else if (keycode == K_M && ptr->fr->n < 100)
		ptr->fr->n += ptr->set->sens * 0.1;
	return (ptr);
}
