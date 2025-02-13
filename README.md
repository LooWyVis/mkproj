# mkproj - Générateur de projets

## Description
`mkproj` est une commande permettant de créer rapidement un projet en C, Python ou HTML avec une structure de base. Il offre également une option pour initialiser un dépôt Git.

## Installation
### 1. Compiler le programme
```sh
gcc mkproj.c -o mkproj
```

### 2. Déplacer l'exécutable dans `/usr/local/bin`
```sh
sudo mv mkproj /usr/local/bin/
```

### 3. Vérifier l'installation
```sh
which mkproj
```
Si la commande affiche `/usr/local/bin/mkproj`, alors l'installation est réussie.

## Utilisation
```sh
mkproj [type] [nom_du_projet] [--git]
```

### Exemples
#### Créer un projet C
```sh
mkproj c MonProjetC
```
Cela crée un dossier `MonProjetC` avec :
- Un fichier `main.c` avec un programme de base
- Un `Makefile`

#### Créer un projet Python avec Git
```sh
mkproj python MonScript --git
```
Cela crée un dossier `MonScript` avec :
- Un fichier `main.py`
- Un dépôt Git initialisé

#### Créer un projet HTML
```sh
mkproj html SiteWeb
```
Cela crée un dossier `SiteWeb` avec :
- Un fichier `index.html`
- Un dossier `css` avec `style.css`
- Un dossier `js`

## Options
- `--git` : Initialise un dépôt Git dans le projet.

## Types de projets pris en charge
| Type   | Contenu généré |
|--------|---------------|
| `c`    | `main.c`, `Makefile` |
| `python` | `main.py` |
| `html`  | `index.html`, `css/style.css`, `js/` |

## Licence
Ce projet est sous licence MIT.

## Auteur
Développé par Louis.
