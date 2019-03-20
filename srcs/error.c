/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 18:09:23 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 18:25:54 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** Permet de quitter le programme en cas d'erreur et d'afficher un message a
** l'utilisateur.
*/

void	error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

/*
** Permet de quitter proprement le programme en cas d'erreur et d'afficher un
** message a l'utilisateur.
*/

void	error_free(t_mlx *ptr, char *str)
{
	ft_putendl(str);
	free(ptr);
	ptr = NULL;
	exit(EXIT_FAILURE);
}
