/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 11:08:51 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 14:15:30 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_init(t_mlx *ptr)
{
	int i;
	int x;
	int y;

	//ptr->man->img_x = (ptr->man->x2 - ptr->man->x1) * ptr->man->zoom;
	//ptr->man->img_y = (ptr->man->y2 - ptr->man->y1) * ptr->man->zoom;

	//printf("%f\n", ptr->man->img_x);

	x = -1;
	while (++x < W_WIDTH)
	{
		y = -1;
		ptr->man->c_r = x / ptr->man->zoom + ptr->man->x1;
		while (++y < W_HEIGHT)
		{
			ptr->man->c_i = y / ptr->man->zoom + ptr->man->y1;
			ptr->man->z_r = 0;
			ptr->man->z_i = 0;
			i = -1;
			while (++i < ptr->man->max && (ptr->man->z_r * ptr->man->z_r + ptr->man->z_i * ptr->man->z_i) < 4)
			{
				ptr->man->tmp = ptr->man->z_r;
				ptr->man->z_r = ptr->man->z_r * ptr->man->z_r - ptr->man->z_i *	ptr->man->z_i + ptr->man->c_r;
				ptr->man->z_i = 2 * ptr->man->z_i * ptr->man->tmp +	ptr->man->c_i;
			}
			if (x + ptr->man->x_min > 0
				&& x + ptr->man->x_min < W_WIDTH
				&& y + ptr->man->y_min > 0
				&& y + ptr->man->y_min < W_HEIGHT)
			{
				if (i == ptr->man->max)
					graphic_pixel(ptr, x, y, ptr->set->white);
				else
				{
					graphic_pixel(ptr, x, y, color_rgbtoi(0,
							i * 255 / ptr->man->max,
							i * 255 / ptr->man->max));
				}
			}
		}
	}
}
