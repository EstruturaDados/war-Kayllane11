#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void exibirTerritorio(Territorio *t) {
    printf("\n--- Território ---\n");
    printf("Nome: %s\n", t->nome);
    printf("Cor: %s\n", t->cor);
    printf("Tropas: %d\n", t->tropas);
}

void atacar(Territorio *atacante, Territorio *defensor) {
    printf("\n=== Simulando ataque... ===\n");

    int dadoA = (rand() % 6) + 1;
    int dadoD = (rand() % 6) + 1;

    printf("Dado do atacante (%s): %d\n", atacante->nome, dadoA);
    printf("Dado do defensor  (%s): %d\n", defensor->nome, dadoD);

    if (dadoA > dadoD) {
        printf("\nResultado: O atacante venceu!\n");

        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;

        printf("O território %s agora pertence a %s.\n",
               defensor->nome, defensor->cor);

    } else {
        printf("\nResultado: O defensor resistiu ao ataque!\n");

        if (atacante->tropas > 1) {
            atacante->tropas -= 1;
        } else {
            printf("O atacante ficou sem tropas suficientes!\n");
        }
    }
}

void liberarMemoria(Territorio *mapa) {
    free(mapa);
    printf("\nMemória liberada.\n");
}

int main() {
    srand(time(NULL));

    int n;
    printf("Quantos territórios deseja cadastrar? ");
    scanf("%d", &n);
    getchar();

    Territorio *mapa = (Territorio *)calloc(n, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        printf("Nome: ");
        fgets(mapa[i].nome, 30, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = 0;

        printf("Cor: ");
        fgets(mapa[i].cor, 10, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = 0;

        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar();
    }

    int op;
    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Exibir territórios\n");
        printf("2 - Atacar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        if (op == 1) {
            for (int i = 0; i < n; i++) {
                exibirTerritorio(&mapa[i]);
            }
        }

        else if (op == 2) {
            int a, d;

            printf("\nEscolha o território atacante (0 a %d): ", n - 1);
            scanf("%d", &a);

            printf("Escolha o território defensor (0 a %d): ", n - 1);
            scanf("%d", &d);

            if (a < 0 || a >= n || d < 0 || d >= n) {
                printf("Índices inválidos!\n");
                continue;
            }

            if (strcmp(mapa[a].cor, mapa[d].cor) == 0) {
                printf("Não é possível atacar território da mesma cor!\n");
                continue;
            }

            atacar(&mapa[a], &mapa[d]);
        }

    } while (op != 0);

    liberarMemoria(mapa);

    return 0;
}
