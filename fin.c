#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100

typedef struct {
    char titre[50];
    char description[100];
    char dateEcheance[11]; // format YYYY-MM-DD
    char priorite[10]; // "High" ou "Low"
} Tache;

Tache taches[MAX_TACHES];
int nombreTaches = 0; 
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