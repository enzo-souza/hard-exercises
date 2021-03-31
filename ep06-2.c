
#include <stdlib.h>
#include <stdio.h>

int *duplica_impares(int *v, int n_entrada, int *n_retorno) {
    int tamanho_vetor = n_entrada;

    int verifica_primo(int n){
        int i;
        if (n%2==0){return 0;}
        return 1;
    }

    int conta_primos(int *v, int tamanho_vetor){// esta função conta quantos primos tem no vetor *v
        int i,j=0,cont;

        for(i=0; i<n_entrada; i++){
            if (verifica_primo(*(v+i)) ==1 ){
                j++;;
            }
        }
        return j;
    }



    int i,j=0,x;

    x = conta_primos(v,tamanho_vetor) + n_entrada;
    printf("%d",x);

    n_retorno = malloc(sizeof(int)*x); //esta linha faz o vetor n_retorno ter o tamanho necessário


    for (i=0;i<(n_entrada);i++){
        n_retorno[j] = *(v+i);

        if ( verifica_primo(*(v+i)) == 1){
            j++;
            n_retorno[j] = *(v+i);
        }

        j++;
    }

    return *n_retorno;
}

int main(){
    int x=0;
    int *v = malloc(sizeof(int)*3);
    *(v+0) = 5;
    *(v+1) = 1;
    *(v+2) = 6;
    int n_entrada=3, *n_retorno;


    printf("%d",duplica_impares(v,n_entrada,&n_retorno));


    free(n_retorno);

    return 0;
}
