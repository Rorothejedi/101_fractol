/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:54:01 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 18:02:36 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Initialise la structure principale (fr)
*/

t_mlx	*struct_init(char *fr_name, clock_t time_init)
{
	t_mlx *ptr;

	if (!(ptr = (t_mlx*)malloc(sizeof(t_mlx))))
		error("Error : malloc failure (struct_init in struct.c)");
	ptr->time = time_init;
	ptr->fr = struct_fractal(fr_name);
	ptr->set = struct_param();
	ptr->man = struct_mandel();
	return (ptr);
}

/*
** Initialise la structure t_fractal.
*/

t_fractal	*struct_fractal(char *fr_name)
{
	t_fractal *temp;

	temp = NULL;
	if (!(temp = malloc(sizeof(t_fractal))))
		error("Error : malloc failure (struct_fractal in struct.c)");
	temp->name = fr_name;
	return (temp);
}

/*
** Initialise la structure t_param.
*/

t_param		*struct_param(void)
{
	t_param *temp;

	temp = NULL;
	if (!(temp = malloc(sizeof(t_param))))
		error("Error : malloc failure (struct_param in struct.c)");
	temp->sens = 10;
	temp->white = 16777215;
	temp->green = 65280;
	return (temp);
}

/*
** Initialise la structure t_mandel.
*/

t_mandel	*struct_mandel(void)
{
	t_mandel *temp;

	temp = NULL;
	if (!(temp = malloc(sizeof(t_mandel))))
		error("Error : malloc failure (struct_mandel in struct.c)");
	temp->x1 = -2.1;
	temp->x2 = 0.6;
	temp->y1 = -1.2;
	temp->y2 = 1.2;
	temp->img_x = 0;
	temp->img_y = 0;
	temp->c_r = 0;
	temp->c_i = 0;
	temp->z_r = 0;
	temp->z_i = 0;
	temp->tmp = 0;
	temp->zoom = 260;
	temp->max = 50;
	temp->x_min = 0;
	temp->y_min = 0;
	return (temp);
}

/*
** Permet de free toutes les structures.
*/

void	struct_free(t_mlx *ptr)
{
	free(ptr->fr);
	free(ptr->set);
	free(ptr->man);
	ptr->fr = NULL;
	ptr->set = NULL;
	ptr->man = NULL;
	free(ptr);
	ptr = NULL;
}
