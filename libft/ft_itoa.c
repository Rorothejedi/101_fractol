/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 11:08:03 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 12:42:38 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*buff;
	int		len;
	int		i;

	i = 0;
	if (n < 0)
		i = 1;
	len = ft_nb_len(n);
	if (!(buff = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	buff[len--] = '\0';
	while (len >= 0)
	{
		buff[len--] = '0' + ((n < 0) ? -(n % 10) : (n % 10));
		n = (n < 0) ? -(n / 10) : (n / 10);
	}
	if (i == 1)
		buff[0] = '-';
	return (buff);
}
