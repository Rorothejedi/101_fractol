/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcabotia <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 17:17:22 by rcabotia     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 13:14:45 by rcabotia    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	char	*usage;
	clock_t	time_init;;

	time_init = clock();
	usage = "usage: ./fractol [fractal]\n\nfractals:\n-> Mandelbrot\n-> Julia";
	if (argc == 2)
	{
		if (ft_strcmp("Mandelbrot", argv[1]) == 0)
			main_next("Mandelbrot", time_init);
		else if (ft_strcmp("Julia", argv[1]) == 0)
			main_next("Julia", time_init);
		else
			ft_putendl(usage);
	}
	else
		ft_putendl(usage);
	return (EXIT_SUCCESS);
}

void	main_next(char *fr_name, clock_t time_init)
{
	t_mlx *ptr;

	ptr = struct_init(fr_name, time_init);
	ptr = graphic_init(ptr);
	struct_free(ptr);
}

/*
** TODO

 - Faire en sorte que le programme soit plus rapide
 - Ajouter le zoom ciblé
 - Mettre en place le multi thread
 - Ajouter Julia
 - Ajouter troisieme fractale
 - Ajouter tableau de couleur

 - Ajouter fractale bonus

*/
