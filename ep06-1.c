#include <stdio.h>
#include <stdlib.h>

void *ordena_vetor(double *vetor,int n){
    int x=0,y=0,aux=0;

    for (x=0; x<n; x++){
        for (y=x; y<n; y++){
            if (*(vetor + x) > *(vetor + y)){
                aux = *(vetor+x);
                *(vetor+x) = *(vetor+y);
                *(vetor+y) = aux;
            }
        }
    }
}

void *printa_vetor(double *vetor, int n){
    for (int i=0;i<n;i++){
        if (*(vetor+(n-1))!=-1){
            printf("%.1lf ",*(vetor+i));
        }
    }
    printf("\n");
}

int main(){
    int num_inteiro = 0,pivo=0;
    scanf("%d",&num_inteiro);

    double *vetor = malloc(sizeof(double)*num_inteiro);

    for(int i=0;i<num_inteiro;i++){
        scanf("%lf",vetor+i);

        if (*(vetor+i) == -1){
            i=num_inteiro;
            pivo = 1;
        }

        if (pivo == 0){
            ordena_vetor(vetor,i+1);
            printa_vetor(vetor,i+1);
        }

    }

    printf("\n");
    //printa_vetor(vetor,num_inteiro);

    free(vetor);
    return 0;
}
