#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>

// Declarando as funções e procedimentos de forma global

void layout(char jogo[3][3]);   // procedimento para exibir o layout do jogo da velha
void ler_jogo(int jg1, int jg2, char jogo[3][3]);  // executa o jogo
void continuar(int cond, int *condjo, char jogo[3][3]); // codição para continuar ou não
int vencedor(char jogo[3][3]); // função para definir o vencedor do jogo

int main()
{
    int jg1 = 0, jg2 = 0; // iniciando as variáveis para o jogador 1 e jogador 2
    char jogo[3][3]; // matriz layout

    // Definindo o layout do jogo em branco
    for(int i=0; i < 3; ++i){
        for(int j=0; j < 3; ++j){
            jogo[i][j] = ' ';
        }
    }

    printf("\t\t================== Jogo da Velha ===================\n");

    printf("\n!!! O jogo só será executado se houver dois jogadores !!!");
    printf("\n\nSeleciona o jogador1 (X) e o jogador2 (O)..");
    printf("\n\nOs jogadores selecionados terão sua vez na sequência determinada..");
    while(jg1 == 0 || jg2 == 0){
        printf("\nDigite (1) para o jogador (X) e 2 para o (O) ex.: (2,1) >>. ");
        scanf("%i,%i", &jg1, &jg2);
    }
    clrscr();

    ler_jogo(jg1, jg2, jogo);   // Iniciando o jogo.

    return 0;
}

void layout(char jogo[3][3]){

        printf("\n\t===========================================================");
        printf("\n\t\t\t\tJogo da velha\n");
        printf("\t===========================================================\n");

        printf("\n");
        printf("\t\t     C.    1       2       3    \n\n\t\tL.\n");
        printf("\t\t\t       |       |       \n");
        printf("\t\t1\t   %c   |   %c   |   %c  \n", jogo[0][0], jogo[0][1], jogo[0][2]);
        printf("\t\t\t_______|_______|_______\n");
        printf("\t\t\t       |       |       \n");
        printf("\t\t2\t   %c   |   %c   |   %c  \n", jogo[1][0], jogo[1][1], jogo[1][2]);
        printf("\t\t\t_______|_______|_______\n");
        printf("\t\t\t       |       |       \n");
        printf("\t\t3\t   %c   |   %c   |   %c  \n", jogo[2][0], jogo[2][1], jogo[2][2]);
        printf("\t\t\t       |       |       \n");

        printf("\n\n\tL. - Linha\tC. - Coluna\n");

        printf("\n================================================================================");

}

void ler_jogo(int jg1, int jg2, char jogo[3][3]){

    int l, c;  // iniciando as variáveis que lerão a linha e a coluna do jogador
    int cond;  // variável para a condição ao lup do jogo
    int condjogo = 1; // condição para continuar o jogo

    do{
        while(cond != 1){
            l = 0, c = 0; // zerando as variáveis por causa do lup

            layout(jogo); // exibindo o layout

            printf("\n\nJogador %i informe a linha e a coluna ex.: ( 1 x 2 ) >>. ", jg1);
            scanf("%i x %i", &l, &c);

            // Ciclo de repetição para caso o valor já tenha sido digitado ou ultrapassado
            while(jogo[l-1][c-1] == 'X' || jogo[l-1][c-1] == 'O' || l > 3 || c > 3){
                if(jogo[l-1][c-1] == 'X' || jogo[l-1][c-1] == 'O'){
                    printf("\n!!! O %i x %i já foi listada, digite outro valor para marcar >>. ", l, c);
                    scanf("%i x %i", &l, &c);
                }else{
                    printf("\n!!! O %i x %i ultrapassou o jogo, digite outro valor para marcar >>. ", l, c);
                    scanf("%i x %i", &l, &c);
                }
            }

            // Atribuindo X ou O para a matriz
            if(jg1 == 1){
                jogo[l-1][c-1] = 'X';
                }else{
                    jogo[l-1][c-1] = 'O';
            }
            clrscr();

            layout(jogo); // exibindo layout
            cond = vencedor(jogo); // recebendo o valor do vencedor para o cond
            continuar( cond, &condjogo, jogo); // condição para continuar o jogo

            if(condjogo != 0){ // caso o jogo não for ecerrado continuar

                printf("\n\nJogador %i informe a linha e a coluna ex .: ( 1 x 2 ) >>. ", jg2);
                scanf("%i x %i", &l, &c);

                // Ciclo de repetição para caso o valor já tenha sido digitado ou ultrapassado
                while(jogo[l-1][c-1] == 'X' || jogo[l-1][c-1] == 'O' || l > 3 || c > 3){
                    if(jogo[l-1][c-1] == 'X' || jogo[l-1][c-1] == 'O'){
                        printf("\n!!! O %i x %i já foi listada, digite outro valor para marcar >>. ", l, c);
                        scanf("%i x %i", &l, &c);
                    }else{
                        printf("\n!!! O %i x %i ultrapassou o jogo, digite outro valor para marcar >>. ", l, c);
                        scanf("%i x %i", &l, &c);
                    }
                }
                // Atribuindo X ou O para a matriz
                if(jg2 == 1){
                    jogo[l-1][c-1] = 'X';
                    }else{
                        jogo[l-1][c-1] = 'O';
                    }
                clrscr();

                layout(jogo); // exibir o layout
                cond = vencedor(jogo); // recebendo o valor do vencedor para o cond

                clrscr();

                continuar( cond, &condjogo, jogo); // condição para continuar o jogo
            }
        }

    // Enquanto o usuário não tenha digitado 0 para sair ...

    }while(condjogo == 1);
}

int vencedor(char jogo[3][3]){

    // Aplicando todas as possibilidades de vitórias em X ou O

    if((jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X')||
       (jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X')||
       (jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X')||
       (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X')||
       (jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X')||
       (jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X')||
       (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X')||
       (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X')){
            printf("\n\n\t===================================================================");
            printf("\n\t\t\t!!! O jogador 1 (X) é o vencedor !!!");
            printf("\n\t===================================================================\n");
            getchar();
            return 1;
                }else{
                    if((jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O')||
                       (jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O')||
                       (jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O')||
                       (jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O')||
                       (jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O')||
                       (jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O')||
                       (jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O')||
                       (jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O')){
                            printf("\n\n\t==================================================================");
                            printf("\n\t\t\t!!! O jogador 2 (O) é o vencedor !!!");
                            printf("\n\t==================================================================\n");
                            getchar();
                            return 1;
                        }
                    }
}

void continuar(int cond, int *condjo, char jogo[3][3]){

    int condjogo;

    if(cond == 1){
        printf("\nDeseja jogar outro jogo?");
        printf("\nSe sim (1) se não (0) >>. ");
        scanf("%i", &condjogo);
        if(condjogo == 1){
            *condjo = condjogo;
            cond = 2;
            for(int i=0; i < 3; ++i){
                for(int j=0; j < 3; ++j){
                    jogo[i][j] = ' ';
                }
            }
            clrscr();
            layout(jogo);
        }else{
            *condjo = condjogo;
        }
    }
}
