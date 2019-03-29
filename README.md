# fractol

## Description

Réalisation de fractales (Mandelbrot, Julia, BurningShip, Multibrot) avec la librairie graphique minilibX.

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

Utilisation du multithreading (8 threads).
Zoom et dezoom qui pointe sur la position actuelle de la souris.
Deplacement avec les fleches du clavier.
Possibilite de faire varier avec la souris (sans clic) le paramètre de l’ensemble de Julia.
possibilite de faire varier la puissance du Multibrot.

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

## Images du projet

![Image Mandelbrot 1](https://github.com/Rorothejedi/fractol/blob/master/img_project/img_mandel.png)
