 #include <stdio.h>
 #include <string.h> // Necessária para usar strcpn()

 int main(){
    print("Desafio WAR\n\n");

    // 1 Definição da struct (estrutura de dados)
    struct Territorio{
        char nome[30];   // Nome do território
        char cor[10];    // Cor do exército
        int tropas;      // Quantidade de tropas
    };

    // 2 Criação de um vetor para armazenar 5 territórios
    struct Territorio territorios[5];

    // 3 Cadastro dos territórios
    for (int i = 0; i < 5; i++) {
        printf("Cadastro do território %d:\n", i + 1);

        printf("Nome do território: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // Remove o '\n'
        
        printf("Cor do exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcpn(territorios[i].cor, "\n")] = '\0';

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // Limpa o buffer do teclado após ler o número

        printf ("\n");

    }
    // 4 Exibição dos dados cadastrados 
    printf("\n=== Territorios Cadastrados ===\n");
    for (int i = 0; i < 5; i++){
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].cor);
        printf("Tropas: %d\n"), territorios[i].tropas);

    }
    printf("\nCadastro concluído com sucesso!\n"");
        
        return 0;
}