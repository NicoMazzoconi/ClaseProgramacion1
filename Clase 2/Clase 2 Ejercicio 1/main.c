#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int main()
{
    int numero;
    int suma;
    float promedio;
    int i;
    int maximo;
    int minimo;

    suma = 0;

    for(i = 0; i < CANTIDAD;i++)
    {
        do
        {
            printf("Ingrese un numero mayor a 0 \n");
            scanf("%d", &numero);
        }while(numero <= 0);

        suma = suma + numero;

        if(i == 0)
        {
            maximo = numero;
            minimo = numero;
        }

        if(numero > maximo)
        {
            maximo = numero;
        }
        else
        {
            if(numero < minimo)
            {
                minimo = numero;
            }
        }
    }

    promedio = (float)suma / i;

    printf("\nEl promedio es %.2f \n", promedio);
    printf("El maximo es %d \n", maximo);
    printf("El minimo es %d \n", minimo);

    return 0;
}
