/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 13:27:53 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:47:38 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Permet de convertir des couleurs RGB (red, green, blue) en int pour que la
** couleur puisse etre interprete par la mlx.
*/

unsigned int	color_rgbtoi(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int result;

	result = r;
	result = (result << 8) | g;
	result = (result << 8) | b;
	return (result);
}

unsigned int	color_performer(char *str, unsigned int color)
{
	unsigned int result;

	result = 0;
	if (ft_strcmp(str, "red") == 0)
		result = color_rgbtoi(color, 0, 0);
	else if (ft_strcmp(str, "green") == 0)
		result = color_rgbtoi(0, color, 0);
	else if (ft_strcmp(str, "blue") == 0)
		result = color_rgbtoi(0, 0, color);
	else if (ft_strcmp(str, "cyan") == 0)
		result = color_rgbtoi(0, color, color);
	else if (ft_strcmp(str, "pink") == 0)
		result = color_rgbtoi(color, 0, color);
	else if (ft_strcmp(str, "yellow") == 0)
		result = color_rgbtoi(color, color, 0);
	else if (ft_strcmp(str, "white") == 0)
		result = color_rgbtoi(color, color, color);
	return (result);
}

t_mlx			*color_change(t_mlx *ptr, char *dir)
{
	if (ft_strcmp(dir, "next") == 0)
		ptr = color_change_next(ptr);
	else if (ft_strcmp(dir, "prev") == 0)
		ptr = color_change_prev(ptr);
	return (ptr);
}

t_mlx			*color_change_next(t_mlx *ptr)
{
	if (ft_strcmp(ptr->set->color, "red") == 0)
		ptr->set->color = "green";
	else if (ft_strcmp(ptr->set->color, "green") == 0)
		ptr->set->color = "blue";
	else if (ft_strcmp(ptr->set->color, "blue") == 0)
		ptr->set->color = "cyan";
	else if (ft_strcmp(ptr->set->color, "cyan") == 0)
		ptr->set->color = "pink";
	else if (ft_strcmp(ptr->set->color, "pink") == 0)
		ptr->set->color = "yellow";
	else if (ft_strcmp(ptr->set->color, "yellow") == 0)
		ptr->set->color = "white";
	else if (ft_strcmp(ptr->set->color, "white") == 0)
		ptr->set->color = "red";
	return (ptr);
}

t_mlx			*color_change_prev(t_mlx *ptr)
{
	if (ft_strcmp(ptr->set->color, "red") == 0)
		ptr->set->color = "white";
	else if (ft_strcmp(ptr->set->color, "white") == 0)
		ptr->set->color = "yellow";
	else if (ft_strcmp(ptr->set->color, "yellow") == 0)
		ptr->set->color = "pink";
	else if (ft_strcmp(ptr->set->color, "pink") == 0)
		ptr->set->color = "cyan";
	else if (ft_strcmp(ptr->set->color, "cyan") == 0)
		ptr->set->color = "blue";
	else if (ft_strcmp(ptr->set->color, "blue") == 0)
		ptr->set->color = "green";
	else if (ft_strcmp(ptr->set->color, "green") == 0)
		ptr->set->color = "red";
	return (ptr);
}
