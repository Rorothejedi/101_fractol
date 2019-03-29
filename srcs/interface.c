/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   interface.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 17:28:53 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:52:36 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	interface_real_time(t_mlx *ptr)
{
	string_gen(ptr, 75, 2.5, "---------------------------");
	string_gen(ptr, 77, 5, "REAL TIME INFORMATIONS");
	string_gen(ptr, 75, 7.5, "---------------------------");
	string_gen(ptr, 76, 10, "Fractal     : ");
	string_gen(ptr, 76, 12.5, "Render time : ");
	string_gen(ptr, 76, 15, "Iterations  : ");
	string_gen(ptr, 76, 17.5, "Zoom (10^)  : ");
	if (ft_strcmp("Julia", ptr->fr->name) == 0)
	{
		string_gen(ptr, 76, 20, "State       : ");
		string_gen(ptr, 76, 77.5, "SPACE  : change state");
	}
	else if (ft_strcmp("Multibrot", ptr->fr->name) == 0)
	{
		string_gen(ptr, 76, 20, "Power (Z^)  : ");
		string_gen(ptr, 76, 62.5, "N      : power +");
		string_gen(ptr, 76, 65, "M      : power -");
	}
	string_gen(ptr, 76, 25, "Color       : ");
	string_gen(ptr, 76, 27.5, "Sensitivity : ");
}

/*
** Affichage des commandes sur l'interface.
*/

void	interface_commands(t_mlx *ptr)
{
	string_gen(ptr, 75, 32.5, "---------------------------");
	string_gen(ptr, 83, 35, "COMMANDS");
	string_gen(ptr, 75, 37.5, "---------------------------");
	string_gen(ptr, 75, 42.5, "----- On sensitivity ------");
	string_gen(ptr, 76, 45, "+      : sensitivity +");
	string_gen(ptr, 76, 47.5, "-      : sensitivity -");
	string_gen(ptr, 76, 50, "*      : sensitivity reset");
	string_gen(ptr, 76, 55, "Arrows : move");
	string_gen(ptr, 76, 57.5, "P      : iterations +");
	string_gen(ptr, 76, 60, "O      : iterations -");
	string_gen(ptr, 75, 70, "--------- Others ----------");
	string_gen(ptr, 76, 72.5, "ENTER  : reset");
	string_gen(ptr, 76, 75, "MAJ    : change fractal");
	string_gen(ptr, 76, 82.5, "Mouse wheel : zoom");
	string_gen(ptr, 76, 85, "ECHAP       : quit");
}

/*
** Affichage des indication changeantes sur l'interface.
*/

void	interface_active(t_mlx *ptr)
{
	char time[10];

	ft_ftoa(graphic_time(ptr), time, 3);
	ptr->time = clock();
	string_active_gen(ptr, 87.5, 10, ptr->fr->name);
	string_active_gen(ptr, 87.5, 12.5, time);
	string_active_gen(ptr, 87.5, 15, ft_itoa(ptr->fr->max));
	string_active_gen(ptr, 87.5, 17.5, string_count_zoom(ptr->fr->zoom));
	if (ft_strcmp("Julia", ptr->fr->name) == 0 && ptr->fr->lock == 1)
		string_active_gen(ptr, 87.5, 20, "UNLOCK");
	else if (ft_strcmp("Julia", ptr->fr->name) == 0 && ptr->fr->lock == 0)
		string_active_gen(ptr, 87.5, 20, "LOCK");
	else if (ft_strcmp("Multibrot", ptr->fr->name) == 0)
		string_active_gen(ptr, 87.5, 20, ft_itoa(ptr->fr->n));
	string_active_gen(ptr, 87.5, 25, ptr->set->color);
	string_active_gen(ptr, 87.5, 27.5, ft_itoa(ptr->set->sens));
}
