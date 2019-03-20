/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 15:35:11 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 10:13:04 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_realloc(void *ptr, size_t size)
{
	void	*temp;

	if ((!ptr && !size) || (ft_strlen(ptr) < size))
		return ;
	if (!(temp = malloc(sizeof(temp) * size)))
		return ;
	ft_memcpy(temp, ptr, size);
	ft_memdel(ptr);
	return (*temp);
}
