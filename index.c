#include <stdio.h>
#include <string.h>

#define MAX_COUNTRIES 5
#define MAX_STR_LENGTH 50

struct Country {
    char name[MAX_STR_LENGTH];
    char army[MAX_STR_LENGTH];
    int troops;
};

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Country countries[MAX_COUNTRIES];
    int totalCountries = 0;

    
    do {
        printf("---------------------------------\n");
        printf("             WAR GAME            \n");
        printf("---------------------------------\n");
        printf("Vamos começar a montar o jogo!\n");
        printf("Cadastre 5 territórios\n");

        for (int i = 0; i < 5; i++) {
            printf("---- Cadastrando território %d: ----\n", i + 1);
            printf("Nome do território: \n");
            fgets(countries[i].name, MAX_STR_LENGTH, stdin);
            countries[i].name[strcspn(countries[i].name, "\n")] = '\0';
            printf("Exército do território (ex. Verde, Azul, etc.): \n");
            fgets(countries[i].army, MAX_STR_LENGTH, stdin);
            countries[i].army[strcspn(countries[i].army, "\n")] = '\0';
            printf("Quantidade de tropas do território: \n");
            scanf("%d", &countries[i].troops);
            clearInputBuffer();
            totalCountries++;
        }

        printf("-----------------------\n");
        printf("Territórios cadastrados:\n");
        printf("-----------------------\n");

        for (int i = 0; i < totalCountries; i++) {
            printf("Território %d:\n", i + 1);
            printf("- Nome: %s\n", countries[i].name);
            printf("- Exército: %s\n", countries[i].army);
            printf("- Tropas: %d\n", countries[i].troops);
            printf("-----------------------\n");
        }

        printf("Aperte 'Enter' para sair\n");
        getchar();
        clearInputBuffer();

    } while (totalCountries < 5);
}