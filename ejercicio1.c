#include "funciones.h"
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
int main(void)
{
    const int n=50;
    Reporte repeticion_texto[n];
    FILE *archivo = fopen("texto.txt", "r");
    extraer_palabra("texto.txt", &repeticion_texto, n);
    repeticiones_de_palabra("texto.txt", &repeticion_texto, n);
    imprimir_repeticiones(repeticion_texto, n);
    fclose(archivo);
    return;

}
