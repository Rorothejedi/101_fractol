/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arrdel_i.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 14:37:56 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 14:38:04 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrdel_i(int **array, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_memdel((void **)&(array[i]));
	ft_memdel((void **)&(array));
}
