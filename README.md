# miniRT: Mon premier RayTracer avec MiniLibX

## Introduction

Ce projet, nommé `miniRT`, est une introduction au monde du Ray Tracing. L'objectif est de développer un programme en C capable de rendre des images générées par ordinateur en utilisant le protocole de Ray Tracing. [cite_start]Ce projet vise à vous familiariser avec l'implémentation de formules mathématiques et physiques pour créer des graphiques de haute qualité[cite: 3, 4, 15, 16].

[cite_start]Le Ray Tracing est une méthode de rendu qui produit un degré de réalisme visuel beaucoup plus élevé que la rastérisation, bien qu'il soit plus coûteux en calcul[cite: 11, 12, 13]. [cite_start]Ce projet se concentre sur les fonctionnalités de base du Ray Tracing[cite: 17].

## Fonctionnalités (Partie Obligatoire)

[cite_start]Le programme `miniRT` doit être capable de générer des images représentant une scène vue sous un angle et une position spécifiques, définies par des objets géométriques simples et leur système d'éclairage[cite: 48].

### Objets Géométriques supportés

[cite_start]Le programme doit gérer au minimum les objets géométriques suivants[cite: 56]:
* [cite_start]**Plan** [cite: 56]
* [cite_start]**Sphère** [cite: 56]
* [cite_start]**Cylindre** [cite: 56]

[cite_start]Votre programme doit correctement gérer toutes les intersections possibles et l'intérieur des objets[cite: 57]. [cite_start]Il doit également permettre de redimensionner les propriétés uniques des objets (par exemple, le diamètre d'une sphère, la largeur et la hauteur d'un cylindre)[cite: 58].

### Transformations

Le programme doit être capable d'appliquer des transformations de translation et de rotation aux objets, lumières et caméras. [cite_start]Les sphères et les lumières ne peuvent pas être pivotées[cite: 59].

### Gestion de l'éclairage

* [cite_start]L'éclairage d'ambiance et l'éclairage diffus doivent être implémentés[cite: 61].
* [cite_start]Le programme doit gérer la luminosité des spots et les ombres dures[cite: 60].
* [cite_start]Les objets ne doivent jamais être complètement dans l'obscurité (éclairage ambiant)[cite: 60].

### Gestion de la Fenêtre

* [cite_start]Le programme doit utiliser la bibliothèque `miniLibX`[cite: 50].
* [cite_start]La gestion de la fenêtre doit rester fluide (changement de fenêtre, minimisation, etc.)[cite: 52].
* [cite_start]Appuyer sur la touche `ESC` doit fermer la fenêtre et quitter le programme proprement[cite: 63].
* [cite_start]Cliquer sur la croix rouge du cadre de la fenêtre doit également fermer la fenêtre et quitter le programme proprement[cite: 64].
* [cite_start]L'utilisation des images de la bibliothèque `miniLibX` est fortement recommandée[cite: 65].

### Fichier de Description de Scène (`.rt` extension)

[cite_start]Votre programme doit prendre comme premier argument un fichier de description de scène avec l'extension `.rt`[cite: 66].
[cite_start]Les règles de formatage du fichier sont les suivantes[cite: 67, 68, 69, 70, 71, 74]:
* Chaque type d'élément peut être séparé par un ou plusieurs sauts de ligne.
* Chaque type d'information d'un élément peut être séparé par un ou plusieurs espaces.
* Chaque type d'élément peut être défini dans n'importe quel ordre dans le fichier.
* Les éléments définis par une lettre majuscule ne peuvent être déclarés qu'une seule fois dans la scène.
* La première information pour chaque élément est l'identifiant de type (composé d'un ou deux caractères), suivi de toutes les informations spécifiques à chaque objet dans un ordre strict.

[cite_start]Voici les éléments supportés et leurs formats[cite: 75, 80, 88, 94, 103, 109]:

#### [cite_start]Lumière ambiante (`A`) [cite: 75]
* [cite_start]`A 0.2 255,255,255` [cite: 76]
    * [cite_start]Identifiant: `A` [cite: 77]
    * [cite_start]Ratio d'éclairage ambiant (plage `[0.0,1.0]`): `0.2` [cite: 78]
    * [cite_start]Couleurs R, G, B (plage `[0-255]`): `255,255,255` [cite: 79]

#### [cite_start]Caméra (`C`) [cite: 80]
* [cite_start]`C -50.0,0,20 0,0,1 70` [cite: 81, 82, 83]
    * [cite_start]Identifiant: `C` [cite: 84]
    * [cite_start]Coordonnées x, y, z du point de vue: `-50.0,0,20` [cite: 85]
    * [cite_start]Vecteur d'orientation normalisé 3D (plage `[-1,1]` pour chaque axe x, y, z): `0.0,0.0,1.0` [cite: 86]
    * [cite_start]FOV (champ de vision horizontal en degrés, plage `[0,180]`): `70` [cite: 87]

#### [cite_start]Lumière (`L`) [cite: 88]
* [cite_start]`L -40.0,50.0,0.0 0.6 10,0,255` [cite: 90]
    * [cite_start]Identifiant: `L` [cite: 89]
    * [cite_start]Coordonnées x, y, z du point lumineux: `-40.0,50.0,0.0` [cite: 91]
    * [cite_start]Ratio de luminosité de la lumière (plage `[0.0,1.0]`): `0.6` [cite: 92]
    * [cite_start]Couleurs R, G, B (plage `[0-255]` - inutilisé dans la partie obligatoire): `10,0,255` [cite: 93]

#### [cite_start]Sphère (`sp`) [cite: 94]
* [cite_start]`sp 0.0,0.0,20.6 12.6 10,0,255` [cite: 96]
    * [cite_start]Identifiant: `sp` [cite: 95]
    * [cite_start]Coordonnées x, y, z du centre de la sphère: `0.0,0.0,20.6` [cite: 97]
    * [cite_start]Diamètre de la sphère: `12.6` [cite: 98]
    * [cite_start]Couleurs R, G, B (plage `[0-255]`): `10,0,255` [cite: 99]

#### [cite_start]Plan (`pl`) [cite: 103]
* [cite_start]`pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225` [cite: 104]
    * [cite_start]Identifiant: `pl` [cite: 105]
    * [cite_start]Coordonnées x, y, z d'un point sur le plan: `0.0,0.0,-10.0` [cite: 106]
    * [cite_start]Vecteur normal normalisé 3D (plage `[-1,1]` pour chaque axe x, y, z): `0.0,1.0,0.0` [cite: 107]
    * [cite_start]Couleurs R, G, B (plage `[0-255]`): `0,0,225` [cite: 108]

#### [cite_start]Cylindre (`cy`) [cite: 109]
* [cite_start]`cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255` [cite: 111]
    * [cite_start]Identifiant: `cy` [cite: 110]
    * [cite_start]Coordonnées x, y, z du centre du cylindre: `50.0,0.0,20.6` [cite: 112]
    * [cite_start]Vecteur normalisé 3D de l'axe du cylindre (plage `[-1,1]` pour chaque axe x, y, z): `0.0,0.0,1.0` [cite: 113, 114]
    * [cite_start]Diamètre du cylindre: `14.2` [cite: 115]
    * [cite_start]Hauteur du cylindre: `21.42` [cite: 116]
    * [cite_start]Couleurs R, G, B (plage `[0-255]`): `10,0,255` [cite: 117]

### Gestion des Erreurs

[cite_start]Si une mauvaise configuration est rencontrée dans le fichier de scène, le programme doit quitter proprement et afficher "Error\n" suivi d'un message d'erreur explicite de votre choix[cite: 123].

## Partie Bonus (Optionnelle)

[cite_start]Les bonus ne seront évalués que si la partie obligatoire est parfaite, c'est-à-dire complète et sans aucune erreur, même en cas d'utilisation incorrecte[cite: 130, 131].

[cite_start]Voici une liste de quelques bonus simples à implémenter[cite: 127, 132]:
* Ajouter la réflexion spéculaire pour obtenir un modèle de réflexion de Phong complet.
* Perturbation de couleur: motif en damier.
* Lumières colorées et multi-spots.
* Un autre objet du second degré: cône, hyperboloïde, paraboloïde.
* Gérer les textures de carte de relief (bump map).

Vous êtes autorisé à utiliser d'autres fonctions et à ajouter des fonctionnalités à votre description de scène pour la partie bonus, tant que leur utilisation est justifiée lors de votre évaluation. [cite_start]Vous êtes également autorisé à modifier le format de fichier de scène attendu pour répondre à vos besoins[cite: 134, 135].

## Instructions Communes

* [cite_start]Le projet doit être écrit en C[cite: 22].
* [cite_start]Le projet doit être conforme à la Norme[cite: 23]. [cite_start]Les fichiers/fonctions bonus sont également soumis à la norme[cite: 24].
* [cite_start]Vos fonctions ne doivent pas se terminer de manière inattendue (segmentation fault, bus error, double free, etc.)[cite: 25].
* [cite_start]Toute la mémoire allouée sur le tas doit être correctement libérée[cite: 27].
* [cite_start]Un `Makefile` doit être soumis, compilant les fichiers source avec les drapeaux `-Wall`, `-Wextra`, et `-Werror`, en utilisant `cc`[cite: 28].
* [cite_start]Votre `Makefile` doit contenir au moins les règles `$(NAME)`, `all`, `clean`, `fclean` et `re`[cite: 30].
* [cite_start]Pour les bonus, une règle `bonus` doit être incluse dans votre `Makefile`, ajoutant les en-têtes, bibliothèques ou fonctions non autorisées dans la partie principale[cite: 31]. [cite_start]Les bonus doivent être placés dans des fichiers `_bonus.{c/h}`[cite: 32].
* Si le projet autorise l'utilisation de votre `libft`, ses sources et son `Makefile` doivent être copiés dans un dossier `libft`. [cite_start]Le `Makefile` du projet doit compiler la bibliothèque en utilisant son `Makefile`, puis compiler le projet[cite: 34, 35].
* [cite_start]Il est encouragé de créer des programmes de test pour votre projet, qui ne seront pas soumis ni notés, mais seront utiles pour tester votre travail et celui de vos pairs[cite: 36, 37, 38, 39].
* Soumettez votre travail au dépôt Git assigné. [cite_start]Seul le travail dans le dépôt Git sera noté[cite: 40, 149, 150].

## Exemples

[cite_start]Le document fournit des exemples d'images rendues avec la technique du Ray Tracing[cite: 14].

* [cite_start]Une sphère avec un spot lumineux[cite: 137].
* [cite_start]Un cylindre avec un spot lumineux[cite: 139].
* [cite_start]Un cône (facultatif) et un plan avec un spot lumineux[cite: 140].
* [cite_start]Des scènes plus complexes incluant plusieurs objets, plans, et lumières[cite: 142, 143, 145, 146, 148].
* [cite_start]Une sphère texturée en damier (facultatif) avec plusieurs spots[cite: 148].

![image](https://github.com/user-attachments/assets/09f98876-79e5-4cbb-bada-d28358bba4fe)
