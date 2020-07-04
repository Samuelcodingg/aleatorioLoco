#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n,limSup,limInf,cantPares=0,cantImpares=0,cantPerfect=0,promPar=0,min=999,max=0,promGen=0,aux=0;
    int promImp=0,maxPar=0,maxImp=0,minPar=999,minImp=999, div=0;

    printf("Indica la cantidad de numeros aleatorias a generar: "); scanf("%d",&n);
    printf("\tIndica el rango\n");
    printf("Limite inferior: "); scanf("%d",&limInf);
    printf("Limite superior: "); scanf("%d",&limSup);
    srand(time(NULL));
    printf("\nNumeros: ");
    for(int i=0;i<n;i++){
        aux=limInf+rand()%(limSup+1-limInf);  //Generar aleatorio
        if(aux%2==0){            //Determinar si es par
            cantPares++;
            promPar+=aux;
            if(aux>maxPar){             //Para el máximo par
                maxPar=aux;
            }
            if(aux<minPar){              //Para el mínimo par
                minPar=aux;
            }
        }
        else{                        //Determinar si es impar
            promImp+=aux;
            cantImpares++;
            if(aux>maxImp){             //Máximo impar
                maxImp=aux;
            }
            if(aux<minImp){          //Para el mínimo impar
                minImp=aux;
            }
        }
        if(aux>max){                   //Determinar numero maximo
            max=aux;
        }
        if(aux<min){                 //Determinar numero minimo
            min=aux;
        }
        promGen+=aux;         
        for(int j=aux-1;j>0;j--){    //El for e if son para determinar si es perfecto el numero
            if(aux%j==0){
                div+=j;
            }
        }
        if(div==aux){
            cantPerfect++;
        }
        div=0;
        printf("%d ",aux);
    }
    promPar/=cantPares;
    promImp/=cantImpares;
    promGen/=n;

    printf("\nPromedio general: %d\n",promGen);
    printf("Promedio de pares: %d\n",promPar);
    printf("Promedio de impares: %d\n",promImp);
    printf("Mayor numero par: %d\n",maxPar);
    printf("Menor numero par: %d\n",minPar);
    printf("Mayor numero impar: %d\n",maxImp);
    printf("Menor numero impar: %d\n",minImp);
    printf("Mayor numero: %d",max);
    if(max%2==0){
        printf(" es par");
    }
    else{
        printf(" es impar");
    }

    for(int j=max-1;j>0;j--){
        if(max%j==0){
            div+=j;
        }
    }

    if(max==div){
        printf(" y es perfecto\n");
    }
    else{
        printf(" y no es perfecto\n");
    }

    div=0;

    printf("Menor numero: %d",min);
    if(min%2==0){
        printf(" es par");
    }
    else{
        printf(" es impar");
    }

    for(int j=min-1;j>0;j--){
        if(min%j==0){
            div+=j;
        }
    }

    if(min==div){
        printf(" y es perfecto\n");
    }
    else{
        printf(" y no es perfecto\n");
    }
    printf("Cantidad total de numeros: %d\n",n);
    printf("Cantidad total de pares: %d\n",cantPares);
    printf("Cantidad total de impares: %d\n",cantImpares);
    printf("Cantidad total de perfectos: %d\n",cantPerfect);

    system("pause");
    return 0;
}
