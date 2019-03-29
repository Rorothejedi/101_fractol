/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   graphic.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 18:15:58 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:53:12 by rcabotia    ###    #+. /#+    ###.fr     */
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
	if ((ptr->win = mlx_new_window(ptr->mlx, FULL_WIDTH, W_HEIGHT, NAME))
			== NULL)
		error_free(ptr, "Error : mlx_new_window function failure");
	ptr->img.i = mlx_new_image(ptr->mlx, W_WIDTH, W_HEIGHT);
	ptr->img.data = (unsigned int *)mlx_get_data_addr(ptr->img.i,
			&ptr->img.bpp, &ptr->img.size_l, &ptr->img.endian);
	graphic_trace(ptr);
	mlx_hook(ptr->win, 2, (1L << 0), key_events, (void*)ptr);
	mlx_mouse_hook(ptr->win, mouse_events, ptr);
	mlx_loop(ptr->mlx);
	return (ptr);
}

/*
** Gere l'affichage du contenu de la fenetre.
*/

int		graphic_trace(t_mlx *ptr)
{
	string_init(ptr);
	thread_init(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.i, 0, 0);
	interface_active(ptr);
	return (0);
}

/*
** Gere la couleur ddes pixels de l'image.
*/

void	graphic_pixel(t_mlx *ptr, int x, int y, unsigned int color)
{
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
	return (duration / (THREADS / 2));
}
