#include <stdio.h>
#include <stdlib.h>

int getInt(char* msg,char* msgE,int cIntentos,long numMin,long numMax,int* result)
{
    int codError=-1;
    long auxNum;
    int intentos=cIntentos;

    do
    {
        printf("%s",msg);
        scanf("%ld",&auxNum);

        intentos--;

        if(auxNum<numMin || auxNum>numMax)
        {
            codError=-1;
            printf("%s\n",msgE);
        }
        else
            codError=0;
    }while(codError!=0 && intentos>0);

    if(intentos==0)
        codError=-1;
    else
    {
        codError=0;
        *result=auxNum;
    }

    return codError;
}
