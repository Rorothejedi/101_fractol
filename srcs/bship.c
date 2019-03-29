/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bship.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/26 13:29:02 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:56:00 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Initialise Burning_Ship.
*/

t_mlx	*bship_init(t_mlx *ptr)
{
	ptr->fr->name = "Burning_Ship";
	ptr->fr->lock = 0;
	ptr->fr->x1 = -2.2;
	ptr->fr->x2 = 0.6;
	ptr->fr->y1 = -2.2;
	ptr->fr->y2 = 1.2;
	ptr->fr->z_r = 0.0;
	ptr->fr->z_i = 0.0;
	ptr->fr->tmp = 0.0;
	ptr->fr->zoom = 260.0;
	ptr->fr->max = 70;
	return (ptr);
}

/*
** Permet la creation de la fractale Burning_Ship.
*/

void	bship_create(t_mlx *ptr, t_thr *thr, int x, int y)
{
	int i;

	thr->c_r = x / ptr->fr->zoom + ptr->fr->x1;
	thr->c_i = y / ptr->fr->zoom + ptr->fr->y1;
	ptr->fr->z_r = 0;
	ptr->fr->z_i = 0;
	i = -1;
	while (++i < ptr->fr->max && (ptr->fr->z_r * ptr->fr->z_r + ptr->fr->z_i
				* ptr->fr->z_i) < 4)
	{
		ptr->fr->tmp = ptr->fr->z_r;
		ptr->fr->z_r = fabsl(ptr->fr->z_r * ptr->fr->z_r - ptr->fr->z_i
				* ptr->fr->z_i + thr->c_r);
		ptr->fr->z_i = fabsl(2 * ptr->fr->z_i * ptr->fr->tmp + thr->c_i);
	}
	if (i == ptr->fr->max)
		graphic_pixel(ptr, x, y, ptr->set->white);
	else
		graphic_pixel(ptr, x, y, color_performer(ptr->set->color,
		i * 255 / ptr->fr->max));
}

/*
** Gere les evenements specifiques a Burning Ship.
*/

t_mlx	*bship_events_key(int keycode, t_mlx *ptr)
{
	if (keycode == K_ENTER || keycode == K_NP_ENTER || keycode == K_R)
		ptr = bship_init(ptr);
	else if (keycode == K_MAJ_LT || keycode == K_MAJ_RT || keycode == K_F)
		ptr = multi_init(ptr);
	return (ptr);
}
