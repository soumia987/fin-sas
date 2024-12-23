#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100

typedef struct {
    char titre[50];
    char description[100];
    char dateEcheance[11]; // format annee-mois-jour
    char priorite[10]; // "High" ou "Low"
} Tache;

Tache taches[MAX_TACHES];
int nombreTaches = 0;

void ajouterTache() {
    if (nombreTaches >= MAX_TACHES) {
        printf("La liste des tâches est pleine.\n");
        return;
    }
    
    printf("Titre : ");
    scanf(" %[^\n]", taches[nombreTaches].titre);
    printf("Description : ");
    scanf(" %[^\n]", taches[nombreTaches].description);
    printf("Date d'échéance (YYYY-MM-DD) : ");
    scanf(" %[^\n]", taches[nombreTaches].dateEcheance);
    printf("Priorité (High/Low) : ");
    scanf(" %[^\n]", taches[nombreTaches].priorite);
        if(taches[nombreTaches].priorite!=0||taches[nombreTaches].priorite!=1)
        {
            printf("veuillez entrer seulement 0 ou 1");
            return;
        }

    nombreTaches++;
    printf("Tâche ajoutée avec succès.\n");
}

void afficherTaches() {
    if (nombreTaches == 0) {
        printf("Aucune tâche à afficher.\n");
        return;
    }
    
    for (int i = 0; i < nombreTaches; i++) {
        printf("Tâche %d :\n", i + 1);
        printf("  Titre : %s\n", taches[i].titre);
        printf("  Description : %s\n", taches[i].description);
        printf("  Date d'échéance : %s\n", taches[i].dateEcheance);
        printf("  Priorité : %s\n", taches[i].priorite);
        printf("----------------------------------------\n");
    }
}

void modifierTache() {
    int index;
    printf("Entrez le numéro de la tâche à modifier : ");
    scanf("%d", &index);
    index--; // Ajuste pour l'indexation à partir de 0

    if (index < 0 || index >= nombreTaches) {
        printf("Tâche non trouvée.\n");
        return;
    }

    printf("Nouveau titre (laisser vide pour conserver) : ");
    char nouveauTitre[50];
    scanf(" %[^\n]", nouveauTitre);
    if (strlen(nouveauTitre) > 0) {
        strcpy(taches[index].titre, nouveauTitre);
    }
    
    printf("Nouvelle description (laisser vide pour conserver) : ");
    char nouvelleDescription[100];
    scanf(" %[^\n]", nouvelleDescription);
    if (strlen(nouvelleDescription) > 0) {
        strcpy(taches[index].description, nouvelleDescription);
    }

    printf("Nouvelle date d'échéance (laisser vide pour conserver) : ");
    char nouvelleDate[11];
    scanf(" %[^\n]", nouvelleDate);
    if (strlen(nouvelleDate) > 0) {
        strcpy(taches[index].dateEcheance, nouvelleDate);
    }

    printf("Nouvelle priorité (laisser vide pour conserver) : ");
    char nouvellePriorite[10];
    scanf(" %[^\n]", nouvellePriorite);
    if (strlen(nouvellePriorite) > 0) {
        strcpy(taches[index].priorite, nouvellePriorite);
    }

    printf("Tâche modifiée avec succès.\n");
}

void supprimerTache() {
    int index;
    printf("Entrez le numéro de la tâche à supprimer : ");
    scanf("%d", &index);
    index--; // Ajuste pour l'indexation à partir de 0

    if (index < 0 || index >= nombreTaches) {
        printf("Tâche non trouvée.\n");
        return;
    }

    for (int i = index; i < nombreTaches - 1; i++) {
        taches[i] = taches[i + 1]; // Déplace les tâches vers la gauche
    }

    nombreTaches--;
    printf("Tâche supprimée avec succès.\n");
}

void filtrerTaches() {
    char priorite[10];
    printf("Entrez la priorité à filtrer (High/Low) : ");
    scanf(" %[^\n]", priorite);
    
    printf("Tâches avec priorité %s :\n", priorite);
    int trouve = 0;
    for (int i = 0; i < nombreTaches; i++) {
        if (strcmp(taches[i].priorite, priorite) == 0) {
            printf("Tâche %d : %s\n", i + 1, taches[i].titre);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune tâche trouvée avec cette priorité.\n");
    }
}

void afficherMenu() {
    printf("=== Menu ===\n");
    printf("1. Ajouter une tâche\n");
    printf("2. Afficher la liste des tâches\n");
    printf("3. Modifier une tâche\n");
    printf("4. Supprimer une tâche\n");
    printf("5. Filtrer les tâches\n");
    printf("6. Quitter\n");
    printf("Choisissez une option : ");
}

int main() {
    int choix;

    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterTache(); break;
            case 2: afficherTaches(); break;
            case 3: modifierTache(); break;
            case 4: supprimerTache(); break;
            case 5: filtrerTaches(); break;
            case 6: printf("Au revoir !\n"); break;
            default: printf("Choix invalide. Veuillez réessayer.\n");
        }

    } while (choix != 6);

    return 0;
}
