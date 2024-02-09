#ifndef GESTION_ETUDIANT_H
#define GESTION_ETUDIANT_H

int ajoute_etudiant(Etudiant* students, int* nbr_students);

void mettre_a_jour_informations_etudiant(Etudiant* students,const int nbr_students, const int id_etudiant);

void supprimer_etudiant(Etudiant* students, int* nbr_students, int id_etudiant);

void affiche_details_etudiant(const Etudiant* students, const int id_etudiant);

void affiche_students(const Etudiant* students, int nbr_students);

Etudiant* recherche_etudiant_matricule(Etudiant* students, const int nbr_students, const int criter_matricule);

Etudiant* recherche_etudiant_id(Etudiant* student, int nbr_students, int criter_id);

Etudiant* recherche_etudiant_nom(Etudiant* students, const int nbr_students, const char* nom);

Resultat_recherche recherche_nom_similaire(Etudiant* students, int nbr_students, const char* nom);

int calcule_age_etudiant(const Etudiant* students, int id);


void ajoute_matiere(Etudiant* students, const int nbr_students, int* nbr_matieres, char* nom_matiere, int coef);

void supprimer_matiere(Etudiant *students, int nbr_students, int id_matiere, int *nbr_matieres);

int inserer_note(Etudiant* students, int id_etudiant, int id_matiere, float note_devoir1, float note_devoir2, float note_examen);

void affiche_note_matier_etudiant(const Etudiant* students, int id_etudiant, int id_matiere);

float calculer_moyenne_matiere(Etudiant* students, int id_etudiant, int id_matiere);

void calculer_moyenne_generale(Etudiant* students, int id_etudiant, int nbr_matieres);

void afficher_moyenne_generale(Etudiant* students, int id_etudiant, int nbr_matieres);

void afficher_les_matieres(Etudiant* students, int nbr_matieres);

Resultat_recherche lister_etudiants_par_rang(const Etudiant* students, int nbr_students);


int si_max_students(const int nbr_students);

int si_champ_structure_etudiant_correct(const Etudiant etudiant);

int si_id_etudiant_valide(const int id_etudiant, const int nbr_students);

void affichage_tableau(int *t, int taille);

void comparer_etudiants(Etudiant* students, const int id_etudiant_A, const int id_etudiant_B);



void sauvegarder_informations_html(Etudiant* students, int nbr_students);

void generer_fichier_css();


void affiche_menu(void);



void calculer_moyennes_matieres_etudiants(Etudiant* students, int nbr_students, int nbr_matieres);

void affiche_moyennes_matieres_etudiants(Etudiant* students, int nbr_students, int nbr_matieres);

void calculer_moyennes_generales(Etudiant* students, int nbr_students, int nbr_matieres);

void affiche_moyennes_generales(Etudiant* students, int nbr_students);




char *strcasestr(const char *haystack, const char *needle);


#endif
