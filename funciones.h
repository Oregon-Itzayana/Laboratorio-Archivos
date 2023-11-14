#pragma once
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int recorrer_matriz_palabra(Reporte *repeticion_texto, char palabra_a_comparar[], const int renglon, int *coincidencia);
void extraer_palabra(const char * dir , Reporte *repeticion_texto,const int renglon);
void repeticiones_de_palabra(const char * dir , Reporte *repeticion_texto, const int renglon);
void imprimir_repeticiones(Reporte repeticion_texto[], const int renglon);