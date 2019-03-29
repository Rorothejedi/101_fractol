/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 15:03:35 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:46:15 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Affichage des indications sur l'interface.
*/

void	string_init(t_mlx *ptr)
{
	int i;

	mlx_clear_window(ptr->mlx, ptr->win);
	i = -2;
	while (++i < 99)
		string_gen(ptr, 71.7, i, "|");
	interface_real_time(ptr);
	interface_commands(ptr);
}

/*
** Fonction generique pour l'affichage d'un texte fixe.
*/

void	string_gen(t_mlx *ptr, double w, double h, char *str)
{
	mlx_string_put(ptr->mlx, ptr->win, FULL_WIDTH * w / 100
		, W_HEIGHT * h / 100, ptr->set->white, str);
}

/*
** Fonction generique pour l'affichage d'un texte mouvant.
*/

void	string_active_gen(t_mlx *ptr, double w, double h, char *str)
{
	mlx_string_put(ptr->mlx, ptr->win, FULL_WIDTH * w / 100
		, W_HEIGHT * h / 100, ptr->set->green, str);
}

/*
** Permet de determiner la puissance du zoom pour son affichage.
*/

char	*string_count_zoom(long double zoom)
{
	int count;

	count = 0;
	while (zoom > 10)
	{
		zoom /= 10;
		count++;
	}
	return (ft_itoa(count));
}
