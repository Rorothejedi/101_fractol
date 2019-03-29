# Fract'ol

Réalisation de fractales (Mandelbrot, Julia, BurningShip, Multibrot) avec la librairie graphique minilibX.

## Sujet

[PDF fract'ol](https://github.com/Rorothejedi/101_fractol/blob/master/fract_ol.fr.pdf)

## Fonctionnalités

- Utilisation du multithreading (8 threads).
- Utilisation des images de la minilibX.
- Zoom et dezoom qui pointe sur la position actuelle de la souris.
- Déplacement avec les flèches du clavier.
- Possibilité de faire varier avec la souris (sans clic) le paramètre de l’ensemble de Julia.
- Possibilité de faire varier la puissance du Multibrot.
- Possibilité de changer la fractale affichée a la volée.

* Interface dynamique affichant en temps reel :
	* la fractale actuelle
	* le temps de rendu (en secondes)
	* le nombre d'iterations
	* la puissance du zoom
	* la couleur (parmi les 7 disponibles)
	* la sensibilite (des mouvements, des itérations et de la puissance du multibrot)
	* (puissance de Multibrot)
	* (verrouillage de Julia)

* Interface statique séparant les commandes disponibles en deux sections :
	* les commandes etant affectées par la sensibilité
	* les commandes qui ne sont pas affectées par la sensibilité

## Utilisation

### Compilation du programme :

```
$> make
```

### Lancement de la fenetre graphique :

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

> Realisé et testé sur MacOs Sierra V.10.12.6

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
