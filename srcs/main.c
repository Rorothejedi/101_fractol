/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:17:22 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 18:48:57 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	char	*usage;

	usage = "usage: ./fractol [fractal]\n\nfractals:\n-> Mandelbrot     (1)\
	\n-> Julia          (2) \n-> Burning_Ship   (3) \n-> Multibrot      (4)";
	if (argc == 2)
	{
		if (ft_strcmp("Mandelbrot", argv[1]) == 0
				|| ft_strcmp("1", argv[1]) == 0)
			main_next("Mandelbrot");
		else if (ft_strcmp("Julia", argv[1]) == 0
				|| ft_strcmp("2", argv[1]) == 0)
			main_next("Julia");
		else if (ft_strcmp("Burning_Ship", argv[1]) == 0
				|| ft_strcmp("3", argv[1]) == 0)
			main_next("Burning_Ship");
		else if (ft_strcmp("Multibrot", argv[1]) == 0
				|| ft_strcmp("4", argv[1]) == 0)
			main_next("Multibrot");
		else
			ft_putendl(usage);
	}
	else
		ft_putendl(usage);
	return (EXIT_SUCCESS);
}

void	main_next(char *fr_name)
{
	t_mlx *ptr;

	ptr = struct_init(fr_name);
	ptr = graphic_init(ptr);
	struct_free(ptr);
}
