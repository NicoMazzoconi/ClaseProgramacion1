

int mostrarArrayInt(int* array, int cantidad)
{
    int retorno = -1;
    int i;
    if(cantidad > 0)
    {
        retorno = 0;
        for(i=0;i<cantidad;i++)
        {
            printf("\n%d",array[i]);
        }

    }
    return retorno;
}

int ordenarArrayInt(int* array, int cantidad, int orden)
{
    int retorno = -1;
    int i,j;
    int auxiliar;
    if(cantidad > 0)
    {
        retorno = 0;
        for(i=0;i<cantidad-1;i++)
        {
            for(j=i+1;j<cantidad;j++)
            {
                if(array[i] > array[j] && orden == 0)
                {
                    auxiliar = array[j];
                    array[j] = array[i];
                    array[i] = auxiliar;
                }
                else if(array[i] < array[j] && orden == 1)
                {
                    auxiliar = array[j];
                    array[j] = array[i];
                    array[i] = auxiliar;
                }

            }
        }
    }
    return retorno;
}
