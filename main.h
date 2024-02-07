#ifndef MAIN_H
#define MAIN_H
#endif


#define MAX_ETUDIANTS 100
#define MAX_MATIERES 20
#define MAX_ADMIN 10


typedef struct{
  int jour;
  int mois;
  int annee;
}Date;

typedef struct{
  int id_matiere;
  char nom_matiere[30];
  int coef;
  float note_devoir1;
  float note_devoir2;
  float note_examen;
  float moyenne_matiere;
} Matiere;

  typedef struct{
  int  id;
  char nom[40];
  char prenom[50];
  Date date_naissance;
  char filiere[50];
  char niveau[50];
  int  matricule ;
  Matiere matieres[MAX_MATIERES];
  float moyenne_generale;
} Etudiant;





typedef struct{
    int id;
    char nom[30];
    char prenom[30];
    char username[50];
    char password[50];
} Admin;



/*--------------------------------------------*/
  // Structure pour stocker les résultats de la recherche
  typedef struct {
    int nombres_trouve;
    Etudiant* tableau_trouve;
  } Resultat_recherche;
/*--------------------------------------------*/
