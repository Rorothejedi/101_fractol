/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:05:47 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 12:06:47 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int length;
	int *array;

	if (min >= max)
		return (0);
	i = 0;
	length = max - min;
	if (!(array = (int*)malloc(sizeof(*array) * length)))
		return (NULL);
	while (i < length)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
