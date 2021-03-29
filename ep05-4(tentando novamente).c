#include <stdio.h>
#include <math.h>

void estatisticas_frase(char frase[],int *min,int *max, int *soma, double *media, double *desvio) {
    int i=0,cont_palavra=0,op=0,j=0;
    *max =0;
    *media = 0;
    *desvio =0;

    while (op<=1){

        if ((frase[i] >= 'A' && frase[i] <= 'Z')||(frase[i] >= 'a' && frase[i] <= 'z'))    {
            cont_palavra++;
        }
        else{
            if(cont_palavra != 0){
                if(j==0){*min = cont_palavra;}
                else{
                    if(*min > cont_palavra){*min = cont_palavra;}
                    if(*max < cont_palavra){*max = cont_palavra;}
                }

                *soma += cont_palavra;

                printf("%d\n",cont_palavra);
                cont_palavra = 0;
                j++;
            }
        }


        i++;
        if(frase[i]=='\0'||op==1){op++;}
    }
    *media = (double)*soma/j;

    //printf("\n%d\n%d\n%d\n%f\n",*min,*max,*soma,*media);


    printf("\n");
    i=0,cont_palavra=0,op=0;

    while (op<=1){

        if ((frase[i] >= 'A' && frase[i] <= 'Z')||(frase[i] >= 'a' && frase[i] <= 'z'))    {
            cont_palavra++;
        }
        else{
            if(cont_palavra != 0){

                *desvio += pow((cont_palavra - *media),2);

                printf("%d;%f\n",cont_palavra,*desvio);
                cont_palavra = 0;
            }
        }


        i++;
        if(frase[i]=='\0'||op==1){op++;}
    }
    printf("-%f",*desvio);
    *desvio = sqrt(*desvio/j);

    printf("\n%d\n%d\n%d\n%f\n%f\n",*min,*max,*soma,*media,*desvio);

}

int main(){
    int min,max,soma;
    double media,desvio;
    char frase[50] = {' ','a','o','m','z','-',' ','f','e','i','j','a','o','.',' ','c',' ','c','u','c','u','z',' ','l','\0'};
    estatisticas_frase(frase,&min,&max,&soma,&media,&desvio);

    //printf("\n");
    //printf("=-=-=-= %d %d %d %lf %lf",min, max, soma, media, desvio);
    return 0;
}
