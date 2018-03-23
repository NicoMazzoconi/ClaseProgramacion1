#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int numeroTres;
    int mayor;

    printf("Ingrese el primer numeros \n ");
    scanf("%d", &numeroUno);

    printf("Ingrese el primer numeros \n ");
    scanf("%d", &numeroDos);

    printf("Ingrese el primer numeros \n ");
    scanf("%d", &numeroTres);

    printf("Numero a comprar %d, %d, %d \n", numeroUno, numeroDos, numeroTres);

    if(numeroUno > numeroDos & numeroUno > numeroDos)
    {
        mayor = numeroUno;
    }
    else
        {
            if(numeroDos > numeroTres)
            {
                mayor = numeroDos;
            }
            else
            {
                mayor = numeroTres;
            }
        }

    printf("El numero mas grande es %d", mayor);

    return 0;
}
