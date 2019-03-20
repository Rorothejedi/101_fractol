/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_sort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 11:50:38 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 11:53:16 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int booleen;

	i = 0;
	booleen = 0;
	while (i < length - 1 && f(tab[i], tab[i + 1]) == 0)
		i++;
	booleen = (i < length - 1 && f(tab[i], tab[i + 1]) > 0) ? 1 : 0;
	while (i < length - 1)
	{
		if (booleen == 1 && f(tab[i], tab[i + 1]) < 0)
			return (0);
		else if (booleen == 0 && f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}
