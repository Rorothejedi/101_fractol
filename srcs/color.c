/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:27:53 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 13:30:06 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Permet de convertir des couleurs RGB (red, green, blue) en int pour que la
** couleur puisse etre interprete par la mlx.
*/

int		color_rgbtoi(int r, int g, int b)
{
	int result;

	result = r;
	result = (result << 8) | g;
	result = (result << 8) | b;
	return (result);
}
