# miniRT: Mon premier RayTracer avec MiniLibX 🎨

## Introduction

Bienvenue dans l'univers du Ray Tracing avec `miniRT`! 🚀 Ce projet en C est votre passeport pour créer des images de synthèse époustouflantes. Vous allez plonger dans l'implémentation de formules mathématiques et physiques pour donner vie à des scènes en 3D. Le Ray Tracing, c'est la promesse d'un réalisme visuel supérieur, même si ça demande un peu plus de calculs. Préparez-vous à illuminer l'écran ! ✨

## Fonctionnalités Essentielles

`miniRT` vous permettra de rendre des scènes complètes, définies par des objets géométriques simples et un éclairage dynamique.

### Objets Géométriques supportés 🏗️
* **Plan**
* **Sphère**
* **Cylindre**

Votre programme gérera les intersections et l'intérieur des objets avec précision. La taille de chaque objet sera personnalisable (diamètre pour la sphère, largeur et hauteur pour le cylindre).

### Transformations 🔄
Appliquez des translations et des rotations à vos objets, lumières et caméras. Attention, les sphères et les lumières préfèrent rester stables et ne peuvent pas pivoter !

### Gestion de l'éclairage 💡
* Illuminez vos scènes avec l'éclairage ambiant et diffus.
* Gérez la luminosité des spots et créez des ombres dures réalistes.
* Pas de noir total : l'éclairage ambiant garantit que vos objets ne sont jamais complètement dans l'obscurité.

### Interface Utilisateur (MiniLibX) 🖥️
* Votre projet utilisera la bibliothèque `miniLibX` pour l'affichage.
* Une fenêtre fluide, capable de gérer les minimisations et les changements d'application.
* **ESC** ou le **bouton rouge de fermeture** doivent quitter le programme proprement.
* L'utilisation des images MiniLibX est vivement recommandée pour une expérience optimale.

### Fichier de Description de Scène (`.rt`) 📝

Le programme prendra en argument un fichier `.rt` décrivant votre scène. La flexibilité est de mise : les éléments peuvent être séparés par des sauts de ligne ou des espaces, et l'ordre des éléments n'a pas d'importance. Les éléments majuscules (comme la caméra ou l'éclairage ambiant) ne peuvent apparaître qu'une seule fois.

Voici un aperçu des éléments et de leur format strict :

#### Lumière ambiante (`A`)
* `A 0.2 255,255,255`
    * Identifiant: `A`
    * Ratio d'éclairage ambiant (entre 0.0 et 1.0)
    * Couleurs R, G, B (entre 0 et 255)

#### Caméra (`C`)
* `C -50.0,0,20 0,0,1 70`
    * Identifiant: `C`
    * Coordonnées x, y, z du point de vue
    * Vecteur d'orientation 3D normalisé (chaque axe entre -1 et 1)
    * FOV (champ de vision horizontal en degrés, entre 0 et 180)

#### Lumière (`L`)
* `L -40.0,50.0,0.0 0.6 10,0,255`
    * Identifiant: `L`
    * Coordonnées x, y, z du point lumineux
    * Ratio de luminosité (entre 0.0 et 1.0)
    * Couleurs R, G, B (entre 0 et 255, optionnel pour la partie obligatoire)

#### Sphère (`sp`)
* `sp 0.0,0.0,20.6 12.6 10,0,255`
    * Identifiant: `sp`
    * Coordonnées x, y, z du centre
    * Diamètre
    * Couleurs R, G, B (entre 0 et 255)

#### Plan (`pl`)
* `pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225`
    * Identifiant: `pl`
    * Coordonnées x, y, z d'un point sur le plan
    * Vecteur normal 3D normalisé (chaque axe entre -1 et 1)
    * Couleurs R, G, B (entre 0 et 255)

#### Cylindre (`cy`)
* `cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255`
    * Identifiant: `cy`
    * Coordonnées x, y, z du centre
    * Vecteur 3D normalisé de l'axe (chaque axe entre -1 et 1)
    * Diamètre
    * Hauteur
    * Couleurs R, G, B (entre 0 et 255)

### Gestion des Erreurs 🚫
Toute mauvaise configuration dans le fichier de scène entraînera une sortie propre du programme avec le message "Error\n" suivi d'un message d'erreur clair de votre choix.

## Partie Bonus (Optionnelle) 🌟

Les bonus sont réservés aux projets dont la partie obligatoire est impeccable. Si vous êtes à ce niveau, voici quelques pistes pour aller plus loin :

* Ajoutez la réflexion spéculaire pour un modèle de Phong complet ✨.
* Créez des motifs en damier pour des textures originales ♟️.
* Gérez des lumières colorées et multiples 🌈.
* Implémentez un autre objet du second degré (cône, hyperboloïde, paraboloïde) 🧊.
* Gérez les textures de carte de relief (bump map) pour des surfaces détaillées ⛰️.

Vous pouvez utiliser d'autres fonctions et modifier le format du fichier de scène pour les bonus, à condition de justifier vos choix. Soyez créatifs ! 🧠

## Instructions Générales 📋

* Projet en C, conforme à la Norme (y compris les bonus).
* Pas de crash inattendu (segfault, double free, etc.).
* Libération correcte de toute la mémoire allouée.
* Un `Makefile` avec les règles `$(NAME)`, `all`, `clean`, `fclean`, `re`, et `bonus`. Compilation avec `-Wall`, `-Wextra`, `-Werror` et `cc`.
* Si vous utilisez votre `libft`, elle doit être dans un dossier `libft` et compilée par le `Makefile` principal.
* Créez des programmes de test pour faciliter l'évaluation (non soumis, non notés).
* Soumettez votre travail sur le dépôt Git assigné.

## Exemples Visuels 🖼️

Le sujet contient des exemples d'images rendues pour vous donner une idée du résultat attendu :
* Une sphère simple avec son spot.
* Un cylindre éclairé.
* Un cône et un plan.
* Des scènes plus complexes avec plusieurs objets, des ombres et des lumières multiples.
* Une sphère en damier pour un effet texturé.

![image](https://github.com/user-attachments/assets/09f98876-79e5-4cbb-bada-d28358bba4fe)
