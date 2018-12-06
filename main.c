#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>

void layout(char jogo[3][3]);
void ler_jogo(int jg1, int jg2, char jogo[3][3]);

int main()
{
    int jg1 = 0, jg2 = 0;
    char jogo[3][3];

    for(int i=0; i < 3; ++i){
        for(int j=0; j < 3; ++j){
            jogo[i][j] = ' ';
        }
    }

    printf("\t\t================== Jogo da Velha ===================\n");
    printf("\n!!! O jogo só será executado se houver dois jogadores !!!");

    printf("\n\nSeleciona o jogador1 (x) e o jogador2 (o)..");
    printf("\n\nOs jogadores selecionados terão sua vez na sequência determinada ");
    printf("\nDigite (1) para o jogador que usara (x) e 2 para o que vai usar (o) ex.: ( 2,1 )>>. ");
    scanf("%i,%i", &jg1, &jg2);

    clrscr();

    ler_jogo(jg1, jg2, jogo);


    return 0;
}
void layout(char jogo[3][3]){

        printf("\n\t===========================================================");
        printf("\n\t\t\t\tJogo da velha\n");
        printf("\t===========================================================\n");

        printf("\n");

        printf("\t\t\t       |       |       \n");
        printf("\t\t\t   %c   |  %c    |  %c   \n", jogo[0][0], jogo[0][1], jogo[0][2]);
        printf("\t\t\t_______|_______|_______\n");
        printf("\t\t\t       |       |       \n");
        printf("\t\t\t   %c   |  %c    |  %c   \n", jogo[1][0], jogo[1][1], jogo[1][2]);
        printf("\t\t\t_______|_______|_______\n");
        printf("\t\t\t       |       |       \n");
        printf("\t\t\t   %c   |  %c    |  %c   \n", jogo[2][0], jogo[2][1], jogo[2][2]);
        printf("\t\t\t       |       |       \n");

        printf("\n=================================================");

}

void ler_jogo(int jg1, int jg2, char jogo[3][3]){

    int l, c;
    int cond;
    int condjogo = 2;

    do{

        while(cond != 1){

            layout(jogo);
            l = 0, c = 0;
            printf("\n\nJogador %i informe a linha e a coluna ex.: ( 1 x 2 ) >>. ", jg1);
            scanf("%i x %i", &l, &c);
            if(jg1 == 1){
                jogo[l-1][c-1] = 'X';
                }else{
                    jogo[l-1][c-1] = 'O';
                }
            clrscr();
            layout(jogo);
            printf("\n\nJogador %i informe a linha e a coluna ex .: ( 1 x 2 ) >>. ", jg2);
            scanf("%i x %i", &l, &c);
            if(jg2 == 1){
                jogo[l-1][c-1] = 'X';
                }else{
                    jogo[l-1][c-1] = 'O';
                }
            clrscr();
            layout(jogo);

            if((jogo[0][0] == jogo [0][1] && jogo[0][0] == jogo[0][2])||
               (jogo[1][0] == jogo [1][1] && jogo[1][0] == jogo[1][2])||
               (jogo[2][0] == jogo [2][1] && jogo[2][0] == jogo[2][2])||
               (jogo[0][0] == jogo [1][0] && jogo[0][0] == jogo[2][0])||
               (jogo[0][1] == jogo [1][1] && jogo[0][1] == jogo[2][1])||
               (jogo[0][2] == jogo [1][2] && jogo[0][2] == jogo[2][2])||
               (jogo[0][0] == jogo [1][1] && jogo[0][0] == jogo[2][2])||
               (jogo[0][2] == jogo [1][1] && jogo[0][2] == jogo[2][0])){
                   if(jogo[0][0] == 'X' || jogo[2][0] == 'X' || jogo[0][2] == 'X' ||
                      jogo[2][2] == 'X'){
                        printf("\n=============================================");
                        printf("\n\nO jogador 1 (X) é o vencedor !!!");
                        cond == 1;
                    }else{
                        printf("\n=============================================");
                        printf("\n\nO jogador 2 (O) é o vencedor !!!");
                        cond == 1;
                    }
               }
               clrscr();
        }

        printf("\nDeseja jogar outro jogo?");
        printf("\nSe sim (1) se não (0) >>. ");
        scanf("%i", &condjogo);
        clrscr();

    }while(condjogo != 0);
}
