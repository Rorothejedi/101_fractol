/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 17:49:50 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:44:39 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Gere les evenements a la souris communs a toutes les fractales.
*/

int		mouse_events(int button, int x, int y, t_mlx *ptr)
{
	long double mx;
	long double my;

	mx = (long double)x / ((long double)W_WIDTH /
		(ptr->fr->x2 - ptr->fr->x1)) + ptr->fr->x1;
	my = (long double)y / ((long double)W_HEIGHT /
		(ptr->fr->y2 - ptr->fr->y1)) + ptr->fr->y1;
	if (button == M_WHEEL_DN && x <= W_WIDTH)
		mouse_zoom(ptr, mx, my, "zoom_in");
	else if (button == M_WHEEL_UP && x <= W_WIDTH)
		mouse_zoom(ptr, mx, my, "zoom_out");
	else if (button == M_CLIC_LT)
		ptr = color_change(ptr, "next");
	else if (button == M_CLIC_RT)
		ptr = color_change(ptr, "prev");
	graphic_trace(ptr);
	return (0);
}

/*
** Gere le zoom et le dezoom.
*/

t_mlx	*mouse_zoom(t_mlx *ptr, long double mx, long double my, char *eff)
{
	long double zoom_factor;

	zoom_factor = 1.0 / 1.5;
	if (ft_strcmp(eff, "zoom_in") == 0)
	{
		ptr->fr->zoom *= 1.5;
		ptr->fr->max += 4;
	}
	else if (ft_strcmp(eff, "zoom_out") == 0)
	{
		zoom_factor = 1.0 * 1.5;
		ptr->fr->zoom /= 1.5;
		if (ptr->fr->max >= 4)
			ptr->fr->max -= 4;
	}
	ptr->fr->x1 = mx + ((ptr->fr->x1 - mx) * zoom_factor);
	ptr->fr->y1 = my + ((ptr->fr->y1 - my) * zoom_factor);
	ptr->fr->x2 = mx + ((ptr->fr->x2 - mx) * zoom_factor);
	ptr->fr->y2 = my + ((ptr->fr->y2 - my) * zoom_factor);
	return (ptr);
}
