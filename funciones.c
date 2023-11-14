#include "funciones.h"
int recorrer_matriz_palabra(Reporte *repeticion_texto, char palabra_a_comparar[], const int renglon, int *coincidencia)
{
    int tam = strlen(palabra_a_comparar);
    //0=coincide, 1 = no coincide
    for (int i= 0; i<renglon; i++)
    {
        int j = 0;
        while (repeticion_texto[i].palabra[j]!= '\0')
        {
            if (repeticion_texto[i].palabra[j] != palabra_a_comparar[j])
            {
                coincidencia=1;
            }
            j++;
        }
        if (j==tam&&coincidencia==0)
        {
            coincidencia=0;
            return i;
        }
        else 
            coincidencia=1;
    }
    return -1;

}
void extraer_palabra(const char * dir , Reporte *repeticion_texto, const int renglon)
{
    int coincidencia;
    int i=0;
    char palabra_temporal[50];
    FILE *archivo = fopen(dir, "r");
    char c;
    while (feof(archivo)==0)
    {
        c = fgetc(archivo);
        if(c!= '\0'&& c>64)
        {
            strcat(palabra_temporal, c);
        }
        else
        {
            recorrer_matriz_palabra(&repeticion_texto,palabra_temporal,renglon, &coincidencia);//1 = no coincide, 0 = coincide
            if (coincidencia==1)
            {
                strcpy(repeticion_texto[i].palabra, palabra_temporal);
                repeticion_texto[i].palabra = 0;
                i++;
            }
        }
    }
    fclose(archivo);
    return;
}
void repeticiones_de_palabra(const char * dir , Reporte *repeticion_texto, const int renglon)
{
    char palabra_temporal[50];
    int coincidencia;
    int renglon_coincidencia;
    FILE *archivo = fopen(dir, "r");
    char c;
    while (feof(archivo)==0)
    {
        c = fgetc(archivo);
        if(c!= '\0'&& c>64)
        {
            strcat(palabra_temporal, c);
        }
        else
        {
            renglon_coincidencia=recorrer_matriz_palabra(&repeticion_texto,palabra_temporal,renglon, &coincidencia);
            if (coincidencia==0)
            {
                if (renglon_coincidencia>=0)
                {
                    repeticion_texto[renglon_coincidencia].repeticiones+=1;
                }
            }
        }
    }
    return;

}
void imprimir_repeticiones(Reporte repeticion_texto[], const int renglon)
{
    for (int i = 0; i<renglon;i++)
    {
        int j = 0;
        while (repeticion_texto[i].palabra[j]!= '\0')
        {
            printf("%c", repeticion_texto[i].palabra[j]);
            j++;
        }
        printf(": %d\n", repeticion_texto[i].repeticiones);
    }
    return;
}