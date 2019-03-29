/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:54:01 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:34:44 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Initialise la structure principale (fr)
*/

t_mlx		*struct_init(char *fr_name)
{
	t_mlx *ptr;

	if (!(ptr = (t_mlx*)ft_memalloc(sizeof(t_mlx))))
		error("Error : malloc failure (struct_init in struct.c)");
	ptr->first = 0;
	ptr->time = 0;
	ptr->fr = struct_fractal(fr_name);
	ptr->thr = struct_thread(ptr);
	if (ft_strcmp(fr_name, "Mandelbrot") == 0)
		ptr = mandel_init(ptr);
	else if (ft_strcmp(fr_name, "Julia") == 0)
		ptr = julia_init(ptr);
	else if (ft_strcmp(fr_name, "Burning_Ship") == 0)
		ptr = bship_init(ptr);
	else if (ft_strcmp(fr_name, "Multibrot") == 0)
		ptr = multi_init(ptr);
	ptr->set = struct_param();
	return (ptr);
}

/*
** Initialise la structure t_fractal.
*/

t_fractal	*struct_fractal(char *fr_name)
{
	t_fractal *temp;

	temp = NULL;
	if (!(temp = (t_fractal*)ft_memalloc(sizeof(t_fractal))))
		error("Error : malloc failure (struct_fractal in struct.c)");
	temp->name = fr_name;
	temp->lock = 0;
	temp->n = 6;
	temp->x1 = 0.0;
	temp->x2 = 0.0;
	temp->y1 = 0.0;
	temp->y2 = 0.0;
	temp->z_r = 0.0;
	temp->z_i = 0.0;
	temp->tmp = 0.0;
	temp->zoom = 260.0;
	temp->max = 100;
	return (temp);
}

/*
** Initialise la structure t_param.
*/

t_param		*struct_param(void)
{
	t_param *temp;

	temp = NULL;
	if (!(temp = (t_param*)ft_memalloc(sizeof(t_param))))
		error("Error : malloc failure (struct_param in struct.c)");
	temp->sens = 10;
	temp->white = 16777215;
	temp->green = 65280;
	temp->color = "cyan";
	return (temp);
}

/*
** Initialise la structure t_thr.
*/

t_thr		**struct_thread(t_mlx *ptr)
{
	t_thr	**thr;
	int		i;

	if (!(thr = (t_thr**)ft_memalloc(sizeof(t_thr*) * THREADS)))
		error("Error : malloc failure (struct_thread in struct.c)");
	i = -1;
	while (++i < THREADS)
	{
		if (!(thr[i] = (t_thr*)ft_memalloc(sizeof(t_thr))))
			error("Error : malloc failure (struct_thread in struct.c)");
		thr[i]->id_thread = i;
		thr[i]->c_r = 0.0;
		thr[i]->c_i = 0.0;
		thr[i]->ptr_add = ptr;
	}
	return (thr);
}

/*
** Permet de free toutes les structures.
*/

void		struct_free(t_mlx *ptr)
{
	int i;

	i = -1;
	while (++i < THREADS)
		free(ptr->thr[i]);
	free(ptr->fr);
	free(ptr->set);
	free(ptr->thr);
	ptr->fr = NULL;
	ptr->set = NULL;
	ptr->thr = NULL;
	free(ptr);
	ptr = NULL;
}
