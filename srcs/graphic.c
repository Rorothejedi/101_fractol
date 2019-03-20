/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   graphic.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 18:15:58 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 15:28:51 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Initialisation du serveur graphique et ouverture de la fenetre.
*/

t_mlx	*graphic_init(t_mlx *ptr)
{
	if ((ptr->mlx = mlx_init()) == NULL)
		error_free(ptr, "Error : mlx_init function failure");
	if ((ptr->win = mlx_new_window(ptr->mlx, W_WIDTH, W_HEIGHT, NAME)) == NULL)
		error_free(ptr, "Error : mlx_new_window function failure");

	ptr->img.i = mlx_new_image(ptr->mlx, W_WIDTH, W_HEIGHT);
	ptr->img.data = (unsigned int *)mlx_get_data_addr(ptr->img.i,
			&ptr->img.bpp, &ptr->img.size_l, &ptr->img.endian);

	graphic_trace(ptr);
	events_init(ptr);
	mlx_loop(ptr->mlx);
	return (ptr);
}

/*
** Appelle la fonction correspondant a la fractale souhaitee.
** Affiche l'interface.
*/

int		graphic_trace(t_mlx *ptr)
{
	// ft_bzero(ptr->img.data, W_WIDTH * W_HEIGHT * 4);
	if (ft_strcmp("Mandelbrot", ptr->fr->name) == 0)
		mandelbrot_init(ptr);
	/*else if (ft_strcmp("Julia", ptr->fr->name) == 0)
		julia_init(ptr);*/

	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.i, 0, 0);
	string_init(ptr);
	return (0);
}

void	graphic_pixel(t_mlx *ptr, int x, int y, unsigned int color)
{
	x = x + ptr->man->x_min;
	y = y + ptr->man->y_min;
	ptr->img.data[y * W_WIDTH + x] = color;
}

/*
** Gere le temps d'execution du rendu de la fenetre.
*/

float	graphic_time(t_mlx *ptr)
{
	clock_t		time_end;
	float		duration;

	time_end = clock();
	duration = (float)(time_end - ptr->time) / CLOCKS_PER_SEC;
	return (duration);
}
