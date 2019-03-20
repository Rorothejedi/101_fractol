/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 17:43:19 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 18:44:50 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_reverse(char *str, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

static int	ft_int_to_str(int x, char str[], int d)
{
	int i;

	i = 0;
	if (x == 0)
		str[i++] = '0';
	else
	{
		while (x)
		{
			str[i++] = (x % 10) + '0';
			x = x / 10;
		}
	}
	while (i < d)
		str[i++] = '0';
	ft_reverse(str, i);
	str[i] = '\0';
	return (i);
}
void	ft_ftoa(float n, char *res, int afterpoint)
{
	int		i;
	int		int_part;
	float	fl_part;

	int_part = (int)n;
	fl_part = n - (float)int_part;
	i = ft_int_to_str(int_part, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fl_part = fl_part * pow(10, afterpoint) + 0.5;
		ft_int_to_str((int)fl_part, res + i + 1, afterpoint);
	}
}
