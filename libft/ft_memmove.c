/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:15:13 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 19:19:11 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *buffer_dest;
	unsigned char *buffer_src;

	buffer_dest = dest;
	buffer_src = (void *)src;
	if (buffer_dest == buffer_src)
		return (NULL);
	else if (buffer_dest < buffer_src)
		ft_memcpy(buffer_dest, buffer_src, n);
	else
	{
		buffer_dest += n - 1;
		buffer_src += n - 1;
		while (n--)
			*buffer_dest-- = *buffer_src--;
	}
	return (dest);
}
