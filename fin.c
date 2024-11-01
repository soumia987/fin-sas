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