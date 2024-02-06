# Edu Manager

Edu Manager est un système de gestion étudiante conçu pour aider les établissements d'enseignement à gérer les informations de leurs étudiants de manière efficace et intuitive. Ce programme est écrit en C et offre une variété de fonctionnalités pour faciliter la gestion des données étudiantes.

## Fonctionnalités

Edu Manager offre les fonctionnalités suivantes :

- **Gestion des étudiants** : Ajoutez, mettez à jour, et supprimez les informations des étudiants.
- **Recherche d'étudiants** : Recherchez des étudiants par matricule, ID, ou nom.
- **Gestion des matières** : Ajoutez des matières et associez-les aux étudiants.
- **Notes et moyennes** : Inscrivez les notes des étudiants, calculez les moyennes par matière et la moyenne générale.
- **Classement** : Listez les étudiants par rang selon leur moyenne générale.
- **Comparaison** : Comparez les moyennes générales de deux étudiants.
- **Rapports** : Affichez des rapports détaillés sur les étudiants et leurs performances académiques.
- **Sauvegarde** : Sauvegardez les informations dans le système pour une récupération future.

## Comment démarrer

### Prérequis

Assurez-vous d'avoir un compilateur C installé sur votre système pour compiler et exécuter le programme.

### Compilation

Pour compiler le programme, naviguez jusqu'au répertoire contenant le code source et exécutez la commande suivante :

```bash
gcc edu_manager.c -o edu_manager
```

Remplacez `edu_manager.c` par le nom de votre fichier source principal.

### Exécution

Après la compilation, exécutez le programme en utilisant la commande :

```bash
./edu_manager
```

## Menu

Le programme offre un menu interactif avec les options suivantes :

```
[01] Ajouter un étudiant
[02] Mettre à jour les informations d'un étudiant
...
[23] Afficher les moyennes générales pour tous les étudiants
[99] Afficher le menu
[100] Sauvegarder les informations
```

Sélectionnez une option en entrant le numéro correspondant pour réaliser l'action souhaitée.

## Contribution

Les contributions à ce projet sont les bienvenues. Pour contribuer, veuillez forker le dépôt, créer une branche pour votre fonctionnalité, et soumettre une pull request.

## Licence

[MIT LICENCE]

---

