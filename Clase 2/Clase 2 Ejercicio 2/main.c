#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 10
int main()
{
    char caracter;
    int i;
    int contA=0;
    int contE=0;
    int contI=0;
    int contO=0;
    int contU=0;

    for(i = 0; i < CANTIDAD; i++)
    {
        printf("Ingrese un caracter \n");
        fflush(stdin);
        scanf("%c", &caracter);

        switch(caracter)
        {
            case 'A':
            case 'a':
                contA++;
            break;

            case 'E':
            case 'e':
                contE++;
            break;

            case 'I':
            case 'i':
                contI++;
            break;

            case 'O':
            case 'o':
                contO++;
            break;

            case 'U':
            case 'u':
                contU++;
            break;
        }

    }
    printf("\nIngreso %d A, %d E, %d I, %d O, %d U. \n", contA, contE, contI, contO, contU);
    return 0;
}
