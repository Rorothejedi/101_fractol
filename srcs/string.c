/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 15:03:35 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 13:19:43 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Affichage des indication fixes sur l'interface.
*/

void	string_init(t_mlx *ptr)
{
	char time[10];

	ft_ftoa(graphic_time(ptr), time, 3);
	ptr->time = clock();
	//string_gen(ptr, 7.5, 90, "Render time : ");
	string_active_gen(ptr, 14, 90, time);
	//string_gen(ptr, 7.5, 92, "Sensitivity : ");
	string_active_gen(ptr, 14, 92, ft_itoa(ptr->set->sens));
}

void	string_gen(t_mlx *ptr, double w, double h, char *str)
{
	mlx_string_put(ptr->mlx, ptr->win, W_WIDTH * w / 100
		, W_HEIGHT * h / 100, ptr->set->white, str);
}

void	string_active_gen(t_mlx *ptr, double w, double h, char *str)
{
	mlx_string_put(ptr->mlx, ptr->win, W_WIDTH * w / 100
		, W_HEIGHT * h / 100, ptr->set->green, str);
}
