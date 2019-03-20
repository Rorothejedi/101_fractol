/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_power.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 11:23:58 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 11:25:20 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	if (power >= 0)
	{
		if (power == 0)
			return (1);
		else
			return (nb * ft_power(nb, power - 1));
	}
	else
		return (0);
}
