#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "gestion_etudiant.h"

#define MSG_ID_ETUDIANT_INVALIDE "ID etudiant invalide\n\a"
#define MSG_ID_MATIERE_INVALIDE "Index de matiere invalide\n\a"
#define MSG_MAX_ETUDIANTS "Le nombre d'etudiants est maximal\n\a"

/*--------------------------------------------*/
// Ajout d'Etudiant
/*--------------------------------------------*/

int ajoute_etudiant(Etudiant *students, int *nbr_students)
{
  printf("veuillez fournir les informations de l'etudiants a ajoute\n");
  Etudiant nouvel_etudiant;
  nouvel_etudiant.id = *nbr_students + 1;
  nouvel_etudiant.matricule = nouvel_etudiant.id * 997;

  while (getchar() != '\n')
    ;
  printf("Nom :\n");
  fgets(nouvel_etudiant.nom, sizeof(nouvel_etudiant.nom), stdin);
  nouvel_etudiant.nom[strcspn(nouvel_etudiant.nom, "\n")] = '\0';

  while (getchar() != '\n')
    ;
  printf("Prenom :\n");
  fgets(nouvel_etudiant.prenom, sizeof(nouvel_etudiant.prenom), stdin);
  nouvel_etudiant.prenom[strcspn(nouvel_etudiant.prenom, "\n")] = '\0';

  while (getchar() != '\n')
    ;
  printf("Date de naissance (jour mois annee) en chiffre : \n");
  char donnees_date[20];
  fgets(donnees_date, sizeof(donnees_date), stdin);
  sscanf(donnees_date, "%d %d %d", &nouvel_etudiant.date_naissance.jour,
         &nouvel_etudiant.date_naissance.mois,
         &nouvel_etudiant.date_naissance.annee);
  while (getchar() != '\n')
    ;
  printf("Filiere :\n");
  fgets(nouvel_etudiant.filiere, sizeof(nouvel_etudiant.filiere), stdin);
  nouvel_etudiant.filiere[strcspn(nouvel_etudiant.filiere, "\n")] = '\0';
  while (getchar() != '\n')
    ;
  printf("Niveau :\n");
  fgets(nouvel_etudiant.niveau, sizeof(nouvel_etudiant.niveau), stdin);
  nouvel_etudiant.niveau[strcspn(nouvel_etudiant.niveau, "\n")] = '\0';
  while (getchar() != '\n')
    ;

  if (si_champ_structure_etudiant_correct(nouvel_etudiant) == 0)
  {
    printf("Echec : Les informations de l'etudiant ne sont pas completes.\n");
    return 0;
  }
  else
  {
    students[*nbr_students] = nouvel_etudiant;
    (*nbr_students)++;

    printf("L'etudiant a ete ajoute avec succes");
    return 1;
  }
}

/*---------------------------------------------*/
// Mise à jour des informations d'un étudiant
/*---------------------------------------------*/

void mettre_a_jour_informations_etudiant(Etudiant *students, const int nbr_students, const int id_etudiant)
{

  Etudiant *etudiant = &students[id_etudiant - 1];
  while (getchar() != '\n')
    ;

  printf("Nouveau nom :\n");
  fgets(etudiant->nom, sizeof(etudiant->nom), stdin);
  etudiant->nom[strcspn(etudiant->nom, "\n")] = '\0';
  while (getchar() != '\n')
    ;

  printf("Nouveau prenom :\n");
  fgets(etudiant->prenom, sizeof(etudiant->prenom), stdin);
  etudiant->prenom[strcspn(etudiant->prenom, "\n")] = '\0';
  while (getchar() != '\n')
    ;

  printf("Date de naissance (jour mois annee) en chiffre : \n");
  char donnees_date[10];
  fgets(donnees_date, sizeof(donnees_date), stdin);
  sscanf(donnees_date, "%d %d %d", &etudiant->date_naissance.jour,
         &etudiant->date_naissance.mois,
         &etudiant->date_naissance.annee);
  while (getchar() != '\n')
    ;

  printf("Nouvelle filiere :\n");
  fgets(etudiant->filiere, sizeof(etudiant->filiere), stdin);
  etudiant->filiere[strcspn(etudiant->filiere, "\n")] = '\0';
  while (getchar() != '\n')
    ;

  printf("Nouveau niveau :\n");
  fgets(etudiant->niveau, sizeof(etudiant->niveau), stdin);
  etudiant->niveau[strcspn(etudiant->niveau, "\n")] = '\0';

  printf("Informations mises a jour avec succes.\n");
}

/*--------------------------------------------*/
// Suppression d'un étudiant par ID
/*--------------------------------------------*/

void supprimer_etudiant(Etudiant *students, int *nbr_students, int id_etudiant)
{
  for (int i = id_etudiant - 1; i < *nbr_students - 1; i++)
  {
    students[i] = students[i + 1];
  }
  (*nbr_students)--;
  printf("L'etudiant avec l'id %d a ete supprime avec succes.\n", id_etudiant);
}

/*------------------------------------------------------------*/
// Affichage des details d'un etudiant selectionne par l'id
/*------------------------------------------------------------*/

void affiche_details_etudiant(const Etudiant *students, const int id_etudiant)
{

  const Etudiant *etudiant = &students[id_etudiant - 1];

  printf("\n ---Informatitions de l'etudiant %d : ---\n", id_etudiant);
  printf("ID : %d\n", etudiant->id);
  printf("Nom : %s\n", etudiant->nom);
  printf("Prenom : %s\n", etudiant->prenom);
  printf("Date de naissance : %d/%d/%d\n", etudiant->date_naissance.jour,
         etudiant->date_naissance.mois,
         etudiant->date_naissance.annee);
  printf("Filiere : %s\n", etudiant->filiere);
  printf("Niveau : %s\n", etudiant->niveau);
  printf("Matricule : %d\n", etudiant->matricule);
}

/*--------------------------------------------*/
// Afficher la liste des  Etudiants
/*--------------------------------------------*/

void affiche_students(const Etudiant *students, int nbr_students)
{

  printf("\n LISTES DES ETUDIANTS\n");
  for (int i = 0; i < nbr_students; i++)
  {
    printf("\n--------Etudiant id: %d-------\n", students[i].id);
    printf("Nom : %s %s \n", students[i].nom, students[i].prenom);
  }

  printf("\nFIN DE LISTE\n");
}

/*--------------------------------------------*/
/*--------------------------------------------*/
/*  Recherche etudiant selon le criter        */
/*--------------------------------------------*/
/*--------------------------------------------*/

/*--------------------------------------------------------------------*/
// recherche par matricule
/*--------------------------------------------------------------------*/

Etudiant *recherche_etudiant_matricule(Etudiant *students, const int nbr_students, const int criter_matricule)
{

  int premier_matricule = students[0].matricule;
  int dernier_matricule = students[nbr_students - 1].matricule;

  if (criter_matricule < premier_matricule || criter_matricule > dernier_matricule)
  {
    printf("Matricule invalide\n");
    return NULL;
  }

  int trouve = 0, i = 0;

  for (i = 0; i < nbr_students; i++)
  {
    if (students[i].matricule == criter_matricule)
    {
      trouve = 1;
      break;
    }
  }
  if (trouve == 1)
  {
    printf("l'etudiant que vous rechercher est %s %s \n", students[i].nom, students[i].prenom);
    return &students[i];
  }
  else
  {
    return NULL;
  }
}

/*-------------------------------------*/
// recherche par id
/*-------------------------------------*/

Etudiant *recherche_etudiant_id(Etudiant *student, int nbr_students, int criter_id)
{

  int i = criter_id - 1;
  printf("l'etudiant que vous chercher est %s \n", student[i].nom);
  return &student[i];
}

/*------------------------------------*/
// recherche par nom
/*-------------------------------------*/

Etudiant *recherche_etudiant_nom(Etudiant *students, const int nbr_students, const char *nom)
{
  int i, trouve = 0;

  for (i = 0; i < nbr_students; i++)
  {
    if (strcasecmp(students[i].nom, nom) == 0)
    {
      trouve = 1;
      break;
    }
  }

  if (trouve == 1)
  {
    return &students[i];
  }
  else
  {
    printf("Aucun étudiant trouvé avec le nom : %s\n", nom);
    return NULL;
  }
}

Resultat_recherche recherche_nom_similaire(Etudiant *students, int nbr_students, const char *nom)
{
  Resultat_recherche resultat;
  resultat.nombres_trouve = 0;
  resultat.tableau_trouve = NULL;

  Etudiant *tableau_trouve = NULL;
  int taille_trouve = 0;

  for (int i = 0; i < nbr_students; i++)
  {
    char nom_complet[100];
    strcpy(nom_complet, students[i].nom);
    strcat(nom_complet, " ");
    strcat(nom_complet, students[i].prenom);

    if (strcasestr(nom_complet, nom) != NULL)
    {
      taille_trouve++;
      tableau_trouve = realloc(tableau_trouve, taille_trouve * sizeof(Etudiant));
      tableau_trouve[taille_trouve - 1] = students[i];
    }
  }

  if (taille_trouve > 0)
  {
    resultat.nombres_trouve = taille_trouve;
    resultat.tableau_trouve = tableau_trouve;
  }

  return resultat;
}

/*--------------------------------------------*/
/*--------------------------------------------*/

/*-------------------------------------*/
// calcule l'age de l'etudiant
/*-------------------------------------*/

int calcule_age_etudiant(const Etudiant *students, int id_etudiant)
{
  int annee_actuelle;
  printf("donner l'annee actuelle\n");
  scanf("%d", &annee_actuelle);
  int age = annee_actuelle - students[id_etudiant - 1].date_naissance.annee;
  return age;
}

/*------------------------------------------*/
// gestion des matieres
/*------------------------------------------*/

/*------------------------------------------*/
// ajouter un matiere
/*------------------------------------------*/

void ajoute_matiere(Etudiant *students, const int nbr_students, int *nbr_matieres, char *nom_matiere, int coef)
{

  Matiere nouvelle_matiere;
  strcpy(nouvelle_matiere.nom_matiere, nom_matiere);
  nouvelle_matiere.coef = coef;
  nouvelle_matiere.id_matiere = *nbr_matieres + 1;
  nouvelle_matiere.note_devoir1 = nouvelle_matiere.note_devoir2 = nouvelle_matiere.note_examen = 0.0f;

  for (int i = 0; i < nbr_students; i++)
  {
    students[i].matieres[*nbr_matieres] = nouvelle_matiere;
  }

  (*nbr_matieres)++;

  printf("matiere ajoutee avec succes\n");
}

/*----------------------------*/
// supprimer un matiere
/*--------------------------*/

void supprimer_matiere(Etudiant *students, int nbr_students, int id_matiere, int *nbr_matieres)
{

  int index_matiere = id_matiere - 1;
  for (int i = 0; i < nbr_students; i++)
  {
    for (int i = index_matiere; i < *nbr_matieres - 1; i++)
    {
      memcpy(&students[i].matieres[i], &students[i].matieres[i + 1], sizeof(Matiere));
    }
  }
  (*nbr_matieres)--;
  printf("La matiere a ete supprimee avec succes\n");
}

/*----------------------------------------*/
// Gestion des notes
/*----------------------------------------*/

/*----------------------------------------*/
// inserer la note d'un etudiant
/*----------------------------------------*/

int inserer_note(Etudiant *students, int id_etudiant, int id_matiere, float note_devoir1, float note_devoir2, float note_examen)
{
  int index_matiere = id_matiere - 1;

  students[id_etudiant - 1].matieres[index_matiere].note_devoir1 = note_devoir1;
  students[id_etudiant - 1].matieres[index_matiere].note_devoir2 = note_devoir2;
  students[id_etudiant - 1].matieres[index_matiere].note_examen = note_examen;

  printf("La note a ete ajoute avec succes");
  return 1;
}

/*----------------------------------------*/
// afficher la note d'un etudiant
/*----------------------------------------*/

void affiche_note_matier_etudiant(const Etudiant *students, int id_etudiant, int id_matiere)
{

  int index_matiere = id_matiere - 1;
  const Matiere *matiere = &(students[id_etudiant - 1].matieres[index_matiere]);

  printf("Notes de  %s pour l'etudiant %s %s :\n", matiere->nom_matiere, students[id_etudiant - 1].nom, students[id_etudiant - 1].prenom);
  printf("Note devoir 1 : %f\n", matiere->note_devoir1);
  printf("Note devoir 2 : %f\n", matiere->note_devoir2);
  printf("Note examen :  %f\n", matiere->note_examen);
}

/*----------------------------------------*/
// calculer la moyenne d'une matiere
/*----------------------------------------*/

float calculer_moyenne_matiere(Etudiant *students, int id_etudiant, int id_matiere)
{

  int index_matiere = id_matiere - 1;
  const Matiere *matiere = &(students[id_etudiant - 1].matieres[index_matiere]);

  float moyenne_matiere = (matiere->note_devoir1 + matiere->note_devoir2 + matiere->note_examen) / 3.0f;
  students[id_etudiant - 1].matieres[index_matiere].moyenne_matiere = moyenne_matiere;
  return moyenne_matiere;
}

/*----------------------------------------*/
// calculer la moyenne generale
/*----------------------------------------*/

void calculer_moyenne_generale(Etudiant *students, int id_etudiant, int nbr_matieres)
{

  int somme_coefs = 0;
  float somme_notes_ponderees;
  float somme_notes_ponderees_max;

  float moyenne_matiere;
  float coef;

  for (int i = 0; i < nbr_matieres; i++)
  {
    moyenne_matiere = students[id_etudiant - 1].matieres[i].moyenne_matiere;
    coef = students[id_etudiant - 1].matieres[i].coef;

    somme_coefs += coef;
    somme_notes_ponderees += coef * moyenne_matiere;
    somme_notes_ponderees_max += coef * 20;
  }

  if (somme_coefs == 0)
  {
    printf("Aucune matiere enregistree pour l'etudiant\n");
    return;
  }

  float moyenne_generale = (somme_notes_ponderees / somme_notes_ponderees_max) * 20.0f;
  students[id_etudiant - 1].moyenne_generale = moyenne_generale;
}

/*--------------------------------*/
// afficher la moyenne generale
/*--------------------------------*/

void afficher_moyenne_generale(Etudiant *students, int id_etudiant, int nbr_matieres)
{
  printf("Moyenne generale de l'etudiant %s : %.2f\n", students[id_etudiant - 1].nom,
         students[id_etudiant - 1].moyenne_generale);
}

/*-----------------------*/
// Rang des Etudiants
/*-----------------------*/

Resultat_recherche lister_etudiants_par_rang(const Etudiant *students, int nbr_students)
{

  Etudiant *tries_par_rang = malloc(nbr_students * sizeof(Etudiant));

  if (tries_par_rang == NULL)
  {
    Resultat_recherche resultat_vide;
    resultat_vide.tableau_trouve = NULL;
    resultat_vide.nombres_trouve = 0;
    return resultat_vide;
  }

  memcpy(tries_par_rang, students, nbr_students * sizeof(Etudiant));
  Etudiant tmp;

  for (int i = 0; i < nbr_students - 1; i++)
  {
    for (int j = i + 1; j < nbr_students; j++)
    {
      if (tries_par_rang[i].moyenne_generale > tries_par_rang[j].moyenne_generale)
      {
        tmp = tries_par_rang[i];
        tries_par_rang[i] = tries_par_rang[j];
        tries_par_rang[j] = tmp;
      }
    }
  }

  Resultat_recherche resultat;
  resultat.tableau_trouve = tries_par_rang;
  resultat.nombres_trouve = nbr_students;
  return resultat;
}

/*-------------------------*/
// comparer deux etudiants
/*-------------------------*/

void comparer_etudiants(Etudiant *students, const int id_etudiant_A, const int id_etudiant_B)
{

  float moyenne_etudiant_A = students[id_etudiant_A - 1].moyenne_generale;
  float moyenne_etudiant_B = students[id_etudiant_B - 1].moyenne_generale;

  if (moyenne_etudiant_A < moyenne_etudiant_B)
    printf("etudiant A %s a une moyenne inferieure a l'etudiant B %s\n", students[id_etudiant_A - 1].nom, students[id_etudiant_B - 1].nom);
  else if (moyenne_etudiant_A > moyenne_etudiant_B)
    printf("etudiant A %s a une moyenne superieuere a l'etudiant B %s\n", students[id_etudiant_A - 1].nom, students[id_etudiant_B - 1].nom);
  else
    printf("les deux etudiants %s et %s ont la meme moyenne\n", students[id_etudiant_A - 1].nom, students[id_etudiant_B - 1].nom);
}

/*----------------------------------------*/
// afficher un tableau
/*----------------------------------------*/

void affichage_tableau(int *t, int taille)
{
  for (int i = 0; i < taille; i++)
    printf("%d\n", t[i]);
}

/*----------------------------------------------------*/
// sauvegarder avant de quitter dans un fichier html
/*----------------------------------------------------*/

void sauvegarder_informations_html(Etudiant *students, int nbr_students)
{
  FILE *fichier_html = fopen("liste_etudiants.html", "w");
  if (fichier_html == NULL)
  {
    printf("Erreur lors de l'ouverture du fichier HTML.\n");
    return;
  }
  fprintf(fichier_html,
          "<!DOCTYPE html>\n"
          "<html>\n"
          "<head>\n"
          "<meta charset=\"UTF-8\">\n"
          "<title>Liste des étudiants</title>\n"
          "<link rel=\"stylesheet\" href=\"styles.css\">\n"
          "</head>\n"
          "<body>\n"
          "<div class=\"Liste_Etudiants\">\n"
          "<h1 id=\"TitrePrincipale\">Liste des étudiants</h1>\n"
          "<table class=\"etudiants-table\">\n"
          "<thead>\n"
          "<tr>\n"
          "<th>ID</th>\n"
          "<th>Matricule</th>\n"
          "<th>Nom</th>\n"
          "<th>Prénom</th>\n"
          "</tr>\n"
          "</thead>\n"

          "<tbody>\n");
  for (int i = 0; i < nbr_students; i++)
  {
    fprintf(fichier_html, "<tr>\n");
    fprintf(fichier_html, "<td>%d</td>\n", students[i].id);
    fprintf(fichier_html, "<td>%d</td>\n", students[i].matricule);
    fprintf(fichier_html, "<td>%s</td>\n", students[i].nom);
    fprintf(fichier_html, "<td>%s</td>\n", students[i].prenom);
    fprintf(fichier_html, "</tr>\n");
  }
  fprintf(fichier_html, "</tbody>\n");

  fprintf(fichier_html, "</table>\n");
  fprintf(fichier_html, "</div>\n");
  fprintf(fichier_html, "</body>\n");
  fprintf(fichier_html, "</html>\n");

  fclose(fichier_html);
  printf("Le fichier HTML a ete genere avec succes.\n");
}

/*-----------------------------------------------------------*/
// verifier si on a atteint le nombre maximal d'etudiant
/*------------------------------------------------------------*/

int si_max_students(const int nbr_students)
{
  if (nbr_students >= MAX_ETUDIANTS)
  {
    return 1;
  }
  return 0;
}

/*-------------------------------------------------------------------------------*/
// verifier si les champs de saisie pour l'ajout d'un etudiant est correcte
/*-------------------------------------------------------------------------------*/

int si_champ_structure_etudiant_correct(const Etudiant etudiant)
{

  if (strlen(etudiant.nom) == 0 ||
      strlen(etudiant.prenom) == 0 ||
      etudiant.date_naissance.jour == 0 ||
      etudiant.date_naissance.mois == 0 ||
      etudiant.date_naissance.annee == 0 ||
      strlen(etudiant.filiere) == 0 ||
      strlen(etudiant.niveau) == 0)
  {
    return 0;
  }
  return 1;
}

/*-----------------------------------------------*/
// verfifier si l'id etudiant est valide
/*-----------------------------------------------*/

int si_id_etudiant_valide(const int id_etudiant, const int nbr_students)
{
  if (id_etudiant < 0 || id_etudiant > nbr_students)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

/*-------------------------------*/
// afficher le menu
/*-------------------------------*/

void affiche_menu(void)
{
  printf("\033[1;31m");
  printf("\n---- Qu'est ce que vous vouler faire ----- \n");
  printf("[01] Ajouter un etudiant\n");
  printf("[02] Mettre a jour les informations d'un etudiant\n");
  printf("[03] Supprimer un etudiant\n");
  printf("[04] Afficher les details d'un etudiant\n");
  printf("[05] Afficher tous les etudiants\n");
  printf("[06] Rechercher un etudiant par matricule\n");
  printf("[07] Rechercher un etudiant par ID\n");
  printf("[08] Rechercher des etudiants par nom\n");
  printf("[09] Calculer l'age d'un etudiant\n");
  printf("[10] Ajouter une matiere\n");
  printf("[11] Supprimer une matiere d'un etudiant\n");
  printf("[12] Inserer une note pour un etudiant\n");
  printf("[13] Afficher la note d'une matiere pour un etudiant\n");
  printf("[14] Calculer la moyenne d'une matiere pour un etudiant\n");
  printf("[15] Calculer la moyenne generale d'un etudiant\n");
  printf("[16] Lister les etudiants par rang selon leur moyenne generale\n");
  printf("[17] Comparer la moyenne generale de deux etudiants\n");
  printf("[18] afficher la moyenne d'un etudiant\n");
  printf("[19] afficher la moyenne generale d'un etudiant\n");

  printf("[20] calculer les moyennes des matieres pour tous les etudiants\n");
  printf("[21] afficher les moyennes des matieres pour tous les etudiants\n");
  printf("[22] calculer les moyennes generales pour tous les etudiants\n");
  printf("[23] afficher les moyennes generales pour tous les etudiants\n");

  printf("[99] Afficher le menu\n");
  printf("[100] sauvegarder les informations\n");
  printf("0. Quitter\n");
  printf("\033[0m");
}

/*--------------------------------*/
// afficher les matieres
/*-------------------------------*/

void afficher_les_matieres(Etudiant *students, int nbr_matieres)
{
  printf("Listes des matiers\n");
  for (int i = 0; i < nbr_matieres; i++)
  {
    printf("-ID Matiere  %d: %s \t  coef: %d \n", students[0].matieres[i].id_matiere,
           students[0].matieres[i].nom_matiere,
           students[0].matieres[i].coef);
  }
  printf("\nFIN DE LISTE\n");
}

/*-------------------------------*/
// generer un fichier css
/*-------------------------------*/

void generer_fichier_css()
{
  FILE *fichier_css = fopen("styles.css", "w");
  if (fichier_css == NULL)
  {
    printf("Erreur lors de l'ouverture du fichier CSS.\n");
    return;
  }

  fprintf(fichier_css,
          "body {\n"
          "    font-family: Arial, sans-serif;\n"
          "    background-color: ivory;\n"
          "}\n"
          "\n"
          ".Liste_Etudiants {\n"
          "    max-width: 800px;\n"
          "    margin: 0 auto;\n"
          "    padding: 20px;\n"
          "    background-color: white;\n"
          "}\n"
          "\n"
          "h1 {\n"
          "    text-align: center;\n"
          "}\n"
          "\n"
          ".etudiants-table {\n"
          "    width: 100%;\n"
          "    border-collapse: collapse;\n"
          "    margin-top: 20px;\n"
          "}\n"
          "\n"
          ".etudiants-table th,\n"
          ".etudiants-table td {\n"
          "    padding: 10px;\n"
          "    text-align: left;\n"
          "    border-bottom: 1px solid gainsboro;\n"
          "}\n"
          "\n"
          ".etudiants-table th {\n"
          "    background-color: lightgray;\n"
          "}\n"
          "#TitrePrincipale {\n"
          "font-family: \"Arial\", sans-serif;\n"
          "font-size: 32px;\n"
          "color: #333;\n"
          "text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.5);\n"
          "letter-spacing: 2px;\n"
          "text-transform: uppercase;\n"
          "}\n"
          "\n");

  fclose(fichier_css);

  printf("Le fichier CSS a ete genere avec succes.\n");
}

void affiche_moyenne_matiere(Etudiant *students, int id_etudiant, int id_matiere)
{

  int index_matiere = id_matiere - 1;
  const Matiere *matiere = &(students[id_etudiant - 1].matieres[index_matiere]);

  printf("Matiere %d - %s : %.2f\n", matiere->id_matiere, matiere->nom_matiere, matiere->moyenne_matiere);
}

void calculer_moyennes_matieres_etudiants(Etudiant *students, int nbr_students, int nbr_matieres)
{
  for (int i = 1; i < nbr_students + 1; i++)
  {
    for (int j = 1; j < nbr_matieres + 1; j++)
    {
      calculer_moyenne_matiere(students, i, j);
    }
  }
}

void affiche_moyennes_matieres_etudiants(Etudiant *students, int nbr_students, int nbr_matieres)
{
  for (int i = 1; i < nbr_students + 1; i++)
  {
    printf("\n--- Moyennes pour l'etudiant %d : ---\n", students[i - 1].id);
    for (int j = 1; j < nbr_matieres + 1; j++)
    {
      affiche_moyenne_matiere(students, i, j);
    }
  }
}

void calculer_moyennes_generales(Etudiant *students, int nbr_students, int nbr_matieres)
{
  for (int i = 1; i < nbr_students + 1; i++)
  {
    calculer_moyenne_generale(students, i, nbr_matieres);
  }
}

void affiche_moyennes_generales(Etudiant *students, int nbr_students)
{
  printf("\n--- Moyennes generales pour tous les etudiants : ---\n");
  for (int i = 0; i < nbr_students; i++)
  {
    printf("Etudiant %d - %s %s : %.2f\n", students[i].id, students[i].nom, students[i].prenom, students[i].moyenne_generale);
  }
}


//
char *strcasestr(const char *haystack, const char *needle)
{
  if (*needle == '\0')
  {
    return (char *)haystack;
  }

  while (*haystack != '\0')
  {
    if (strncasecmp(haystack, needle, strlen(needle)) == 0)
    {
      return (char *)haystack;
    }
    haystack++;
  }

  return NULL;
}
