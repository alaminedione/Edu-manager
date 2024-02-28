#include "main.h"
#include "gestion_admin.h"
#include "gestion_etudiant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_ID_ETUDIANT_INVALIDE "ID etudiant invalide\n\a"
#define MSG_ID_MATIERE_INVALIDE "Index de matiere invalide\n\a"
#define MSG_MAX_ETUDIANTS "Le nombre d'etudiants est maximal\n\a"
#define MSG_AUCUN_ETUDIANT_TROUVE "Aucun etudiant enregistre\n\a"

#define QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students)              \
  if (nbr_students == 0) {                                                     \
    printf(MSG_AUCUN_ETUDIANT_TROUVE);                                         \
    break;                                                                     \
  }

#define QUITTE_CASE_SWITCH_SI_INDEX_MATIERE_INVALIDE(index_matiere)            \
  if (index_matiere < 0 || index_matiere >= nbr_matieres) {                    \
    printf(MSG_ID_MATIERE_INVALIDE);                                           \
    break;                                                                     \
  }

#define QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students)    \
  if (si_id_etudiant_valide(id_etudiant, nbr_students) == 0) {                 \
    printf(MSG_ID_ETUDIANT_INVALIDE);                                          \
    break;                                                                     \
  }

int main(int argc, char const *argv[]) {

  printf("\033[1;32m");
  printf("   ______    _         __  __                              \n");
  printf("  |  ____|  | |       |  \\/  |                             \n");
  printf("  | |__   __| |_   _  | \\  / | __ _ _ __   __ _  __ _  ___ \n");
  printf("  |  __| / _` | | | | | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\\n");
  printf("  | |___| (_| | |_| | | |  | | (_| | | | | (_| | (_| |  __/\n");
  printf("  |______\\__,_|\\__,_| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|\n");
  printf("                                                 __/ |    \n");
  printf("                                                |___/     \n");
  printf("\033[0m");

  Etudiant students[MAX_ETUDIANTS];
  int nbr_students = 0;
  int nbr_matieres = 0;

  int choix;
  do {
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
    printf("[20] sauvegarder les informations\n");
    printf("[99] Afficher le menu\n");
    printf("0. Quitter\n");
    printf("\033[0m");

  le_choix:
    // while (getchar() != '\n');
    printf("Choix : \n");
    scanf("%d", &choix);
    if (choix == 0)
      goto Fin;

    switch (choix) {
    case 1: {
      if (nbr_students > MAX_ETUDIANTS) {
        printf(MSG_MAX_ETUDIANTS);
        break;
      }
      ajoute_etudiant(students, &nbr_students);
      break;
    }
    case 2: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      affiche_students(students, nbr_students);
      int id_etudiant;
      printf("ID de l'etudiant a mettre a jour : ");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);
      mettre_a_jour_informations_etudiant(students, nbr_students, id_etudiant);
      break;
    }
    case 3: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      affiche_students(students, nbr_students);
      int id_etudiant;
      printf("ID de l'etudiant a supprimer : ");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);
      supprimer_etudiant(students, &nbr_students, id_etudiant);
      break;
    }
    case 4: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      affiche_students(students, nbr_students);
      int id_etudiant;
      printf("ID de l'etudiant a afficher ses informations : ");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);
      affiche_details_etudiant(students, id_etudiant);
      break;
    }
    case 5: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      affiche_students(students, nbr_students);
      break;
    }
    case 6: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      int matricule;
      printf("Matricule de l'etudiant a rechercher : ");
      scanf("%d", &matricule);
      Etudiant *etudiant =
          recherche_etudiant_matricule(students, nbr_students, matricule);
      if (etudiant != NULL) {
        printf("voici l'etudiant que vous rechercher \n");
        affiche_details_etudiant(students, etudiant->id);
      } else {
        printf("Aucun etudiant trouve avec le matricule %d\n", matricule);
      }
      break;
    }
    case 7: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      if (nbr_students == 0) {
        printf("Aucun etudiant enregistre.\n");
        break;
      }
      int id_etudiant;
      printf("ID de l'etudiant à rechercher : \n");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);
      Etudiant *etudiant =
          recherche_etudiant_id(students, nbr_students, id_etudiant);
      if (etudiant != NULL) {
        affiche_details_etudiant(students, id_etudiant);
      } else {
        printf("Aucun etudiant trouve avec l'ID %d\n", id_etudiant);
      }
    } break;
    case 8: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      char nom[50];
      printf("Nom de l'etudiant a rechercher : ");
      while (getchar() != '\n')
        ;
      fgets(nom, sizeof(nom), stdin);
      nom[strcspn(nom, "\n")] = '\0';
      Etudiant *etudiant = recherche_etudiant_nom(students, nbr_students, nom);
      if (etudiant != NULL) {
        printf("voici l'etudiant que vous rechercher\n");
        affiche_details_etudiant(etudiant, 1);
        break;
      } else {
        printf("aucun etudiant trouve avec ce nom \n");
        printf("recherche de nom similaire....\n\a");
        Resultat_recherche etudiants_nom_similaire =
            recherche_nom_similaire(students, nbr_students, nom);
        if (etudiants_nom_similaire.nombres_trouve != 0) {
          printf("Voici un liste de suggestion : ");
          affiche_students(etudiants_nom_similaire.tableau_trouve,
                           etudiants_nom_similaire.nombres_trouve);
        } else {
          printf("Aucun etudiant de nom similaire trouve");
        }
      }
      break;
    }
    case 9: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      affiche_students(students, nbr_students);
      int id_etudiant;
      printf("ID de l'etudiant pour calculer l'age : \t");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);
      int age = calcule_age_etudiant(students, id_etudiant);
      if (age > 0) {
        printf("L'age de l'etudiant est : %d\n", age);
      } else {
        printf("Erreur inconnu, verifier si vous avez fourni l'annee actuelle "
               "corectement \n");
      }
      break;
    }
    case 10: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      if (nbr_matieres >= MAX_MATIERES) {
        printf("Le nombre de matieres est maximal\n");
        break;
      }
      char nom_matiere[30];
      int coef;
      while (getchar() != '\n')
        ;
      printf("Nom de la matiere a ajouter : ");
      fgets(nom_matiere, sizeof(nom_matiere), stdin);
      nom_matiere[strcspn(nom_matiere, "\n")] = '\0';
      while (getchar() != '\n')
        ;
      /*
      printf("Nom de la matiere a ajouter : ");
      scanf("%.29s", &nom_matiere); // ca cree des comportements indefini et
      bizarre en cas depassement
      */
      printf("Coefficient de la matiere : ");
      scanf("%d", &coef);
      ajoute_matiere(students, nbr_students, &nbr_matieres, nom_matiere, coef);
      afficher_les_matieres(students, nbr_matieres);
      break;
    }
    case 11: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      afficher_les_matieres(students, nbr_matieres);
      int id_matiere;
      printf("ID de la matiere a supprimer : ");
      scanf("%d", &id_matiere);
      int index_matiere = id_matiere - 1;
      QUITTE_CASE_SWITCH_SI_INDEX_MATIERE_INVALIDE(index_matiere);
      supprimer_matiere(students, nbr_students, id_matiere, &nbr_matieres);
      afficher_les_matieres(students, nbr_matieres);
      break;
    }
    case 12: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      affiche_students(students, nbr_students);
      int id_etudiant;
      printf("ID de l'etudiant a remplir ses notes : ");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);
      int id_matiere;
      afficher_les_matieres(students, nbr_matieres);
      printf("ID de la matiere a inserer les notes : ");
      scanf("%d", &id_matiere);
      int index_matiere = id_matiere - 1;
      QUITTE_CASE_SWITCH_SI_INDEX_MATIERE_INVALIDE(index_matiere);
      int note_devoir1, note_devoir2, note_examen;
      printf("Note du devoir 1 : ");
      scanf("%d", &note_devoir1);
      printf("Note du devoir 2 : ");
      scanf("%d", &note_devoir2);
      printf("Note de l'examen : ");
      scanf("%d", &note_examen);
      inserer_note(students, id_etudiant, id_matiere, note_devoir1,
                   note_devoir2, note_examen);
      break;
    }
    case 13: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      affiche_students(students, nbr_students);
      int id_etudiant;
      printf("ID de l'etudiant a afficher ses notes : ");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);
      afficher_les_matieres(students, nbr_matieres);
      int id_matiere;
      printf("ID de la matiere a afficher les notes: ");
      scanf("%d", &id_matiere);
      int index_matiere = id_matiere - 1;
      QUITTE_CASE_SWITCH_SI_INDEX_MATIERE_INVALIDE(index_matiere);
      affiche_note_matier_etudiant(students, id_etudiant, id_matiere);
      break;
    }
    case 14: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      affiche_students(students, nbr_students);
      int id_etudiant;
      printf("ID de l'etudiant a calculer la moyenne d'une matiere : ");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);
      int id_matiere;
      afficher_les_matieres(students, nbr_matieres);
      printf("ID de la matiere a calculer la moyenne : ");
      scanf("%d", &id_matiere);
      int index_matiere = id_matiere - 1;
      QUITTE_CASE_SWITCH_SI_INDEX_MATIERE_INVALIDE(index_matiere);
      float moyenne_matiere =
          calculer_moyenne_matiere(students, id_etudiant, id_matiere);
      printf(
          "La moyenne de la matière: %s pour l'étudiant: %s est : %.2f\n",
          moyenne_matiere,
          students[id_etudiant - 1].matieres[id_matiere - 1].nom_matiere,
          students[id_etudiant - 1].nom,
          students[id_etudiant - 1].matieres[id_matiere - 1].moyenne_matiere);
      break;
    }
    case 15: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      affiche_students(students, nbr_students);
      int id_etudiant;
      printf("ID de l'etudiant a calculer la moyenne generale: ");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);
      calculer_moyenne_generale(students, id_etudiant, nbr_matieres);
      printf("La moyenne general de l'etudiant est : %.2f\n",
             students[id_etudiant - 1].moyenne_generale);
      break;
    }
    case 16: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);

      Resultat_recherche resultat_rang_etudiants =
          lister_etudiants_par_rang(students, nbr_students);

      printf("Liste des etudiants par rang selon leur moyenne generale :\n");
      for (int i = resultat_rang_etudiants.nombres_trouve - 1, rang = 1; i >= 0;
           i--, rang++) {
        printf("Rang %d : %s %s  %.2f\n", rang,
               resultat_rang_etudiants.tableau_trouve[i].nom,
               resultat_rang_etudiants.tableau_trouve[i].prenom,
               resultat_rang_etudiants.tableau_trouve[i].moyenne_generale);
      }

      free(resultat_rang_etudiants.tableau_trouve);

      break;
    }
    case 17: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      if (nbr_students <= 1) {
        printf("y a un seul etudiant\n");
        break;
      }
      affiche_students(students, nbr_students);
      int id_etudiant_A, id_etudiant_B;
      printf("donner l'id de l'etudiant A et B  \n");
      scanf("%d %d", &id_etudiant_A, &id_etudiant_B);
      if (si_id_etudiant_valide(id_etudiant_A, nbr_students) == 0 ||
          si_id_etudiant_valide(id_etudiant_B, nbr_students) == 0) {
        printf("veuiller fournir les ID correctement\n");
        break;
      } else {
        afficher_moyenne_generale(students, id_etudiant_A, nbr_matieres);
        afficher_moyenne_generale(students, id_etudiant_B, nbr_matieres);
        comparer_etudiants(students, id_etudiant_A, id_etudiant_B);
        break;
      }
    }

    case 18: // afficher la moyenne d'un etudiant
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      int id_etudiant;
      affiche_students(students, nbr_students);
      printf(
          "donner l'id de l'etudiant a afficher la moyenne d'une matiere \n");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);
      int id_matiere;
      printf("l'ID matiere a afficher la moyenne\n");
      afficher_les_matieres(students, nbr_matieres);
      scanf("%d", &id_matiere);
      int index_matiere = id_matiere - 1;
      QUITTE_CASE_SWITCH_SI_INDEX_MATIERE_INVALIDE(index_matiere);
      printf(" %s  a une moyenne de %.2f en %s \n",
             students[id_etudiant - 1].nom,
             students[id_etudiant - 1].matieres[id_matiere - 1].moyenne_matiere,
             students[id_etudiant - 1].matieres[id_matiere - 1].nom_matiere);
      break;

    case 19: {

      int id_etudiant;
      affiche_students(students, nbr_students);
      printf("donner l'id de l'etudiant a afficher la moyenne generale\n");
      scanf("%d", &id_etudiant);
      QUITTE_CASE_SWITCH_SI_ID_FOURNI_INVALIDE(id_etudiant, nbr_students);

      afficher_moyenne_generale(students, id_etudiant, nbr_matieres);

      break;
    }
    case 20: {
      QUITTE_CASE_SWITCH_SI_AUCUN_ETUDIANT_TROUVE(nbr_students);
      sauvegarder_informations_html(students, nbr_students);
      generer_fichier_css();
      printf("les modifications apportee ont ete sauvegarde avec succes ");
      break;
    }

    case 99: {
      affiche_menu();
      break;
    }
    default: {
      printf("Choix invalide. Veuillez reessayer.\n");
      break;
    }
    }
    printf("\n");

    goto le_choix;
  Fin:
  } while (choix != 0);

  return 0;
}
