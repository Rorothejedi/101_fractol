# Fractol (fract'ol)

Réalisation de fractales (Mandelbrot, Julia, BurningShip, Multibrot) avec la librairie graphique minilibX.

---------------------------------

## Fonctionnalites

Interface dynamique affichant en temps reel :
 - la fractale actuelle
 - le temps de rendu (en secondes)
 - le nombre d'iterations
 - la puissance du zoom
 - la couleur (parmi les 7 disponibles)
 - la sensibilite (des mouvements, des iterations et de la puissance du multibrot)
 - (puissance de Multibrot)
 - (verrouillage de Julia)

Interface statique affichant les commandes en deux sections :
 - celles etant affectees par la sensibilite
 - Celles qui ne sont pas affectees par la sensibilite

Utilisation du multithreading (8 threads).<br>
Utilisation des images de la minilibX.<br>
Zoom et dezoom qui pointe sur la position actuelle de la souris.<br>
Deplacement avec les fleches du clavier.<br>
Possibilite de faire varier avec la souris (sans clic) le paramètre de l’ensemble de Julia.<br>
possibilite de faire varier la puissance du Multibrot.<br>

## Utilisation

Compilation du programme :

```
$> make
```

Lancement de la fenetre graphique :

```
$> ./fractol Mandelbrot
$> ./fractol Julia
$> ./fractol Burning_Ship
$> ./fractol Multibrot
```

Ou

```
$> ./fractol 1
$> ./fractol 2
$> ./fractol 3
$> ./fractol 4
```

-----------------------------------

## Images du projet

### Mandelbrot
![Image Mandelbrot 1](https://github.com/Rorothejedi/fractol/blob/master/img_project/img_mandel.png)

![Image Mandelbrot 2](https://github.com/Rorothejedi/fractol/blob/master/img_project/img_mandel_2.png)

![Image Mandelbrot 3](https://github.com/Rorothejedi/fractol/blob/master/img_project/img_mandel_3.png)

-----------------------------------

### Julia
![Image Julia 1](https://github.com/Rorothejedi/fractol/blob/master/img_project/img_julia.png)

![Image Julia 2](https://github.com/Rorothejedi/fractol/blob/master/img_project/img_julia_2.png)

-----------------------------------

### Burning Ship
![Image Burning Ship](https://github.com/Rorothejedi/fractol/blob/master/img_project/img_bship.png)

-----------------------------------

### Multibrot
![Image Multibrot](https://github.com/Rorothejedi/fractol/blob/master/img_project/img_multi.png)
