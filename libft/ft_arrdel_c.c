/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arrdel_c.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 14:38:08 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 14:38:15 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrdel_c(char **array, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_strdel(&(array[i]));
	ft_memdel((void **)&(array));
}
