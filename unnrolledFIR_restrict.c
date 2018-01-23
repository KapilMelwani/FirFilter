
/*
 * unrolledFIR.c ~ UNROLLED FIR FILTER
 *
 *  Created on: Jan 4, 2018
 *      Author: Kapil Ashok Melwani Chugani
 *      Subject: Arquitecturas Avanzadas y de Propósito Específico
 *      Institution: Universidad de La Laguna - ETSII (2017)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COEF 5
#define SAMPLES 5

/*Inicializacion de coeficientes: Cargamos el archivo que contienen los 
coeficientes llamado "Coeficientes.csv" e integramos los valores del csv en
un array de float */
float* inicializacion_coeficientes()
{
    float* restrict vector_coeficientes = (float*) malloc(COEF*sizeof(float));
    int i=0;
    FILE *fich_coef = fopen ("Coeficientes.csv", "r");
    while(fscanf(fich_coef, "%f", &vector_coeficientes[i]) != EOF && i<COEF)
    	i++;
    fclose(fich_coef);

    return vector_coeficientes;
}

/*Inicializacion del vector de Entrada: Cargamos el fichero con los valores
del IBEX 35*/
float* inicializacion_vector_in()
{
    int i=0;
    FILE *fich = fopen ("IBEX35_2.csv", "r");
    float* restrict vector_entrada = (float*) malloc((SAMPLES+COEF-1)*sizeof(float));
    float ibex35_close_float;
    char* ibex35_close_char;
    char *ibex35_data;
    char* restrict date = (char*)malloc((SAMPLES*COEF-1)*sizeof(char));
    float* restrict close = (float*)malloc((SAMPLES*COEF-1)*sizeof(float));
    int j;
    const size_t line_size = 3000;
    const char token[2] = ";";
    char* line = malloc(line_size);
    //Inicializacion Prologo y Epílogo
    for(i=0; i<(COEF-1)/2; i++){
        vector_entrada[i] = 0;
        vector_entrada[SAMPLES+i] = 0;
    }
    i=0;
    while (fgets(line, line_size, fich) != NULL && i<=SAMPLES+COEF-1){
        ibex35_data = strtok(line,token);
        ibex35_close_char = strtok(NULL,token);
        ibex35_close_float = strtod(ibex35_close_char,NULL);
        vector_entrada[i] = ibex35_close_float;
        i++;
    }
    return vector_entrada;
}


int main(void)
{
    float* restrict vector_in;
    float* restrict vector_coef;
    float* restrict vector_out = (float*) malloc(SAMPLES+COEF-1); //Inicializacion de Vector Out
    int i;
    vector_in = inicializacion_vector_in();
    vector_coef = inicializacion_coeficientes();
    printf("============================================\n");
    printf("\t\tCOEFICIENTES:\n");
    for(i=0;i<COEF;i++)
    	printf("%f\n",vector_coef[i]);
    printf("============================================\n\n\n");
   	printf("============================================\n");
   	printf("\t\tIBEX 35:\n");
    for(i=0;i<SAMPLES+COEF-1;i++)
    	printf("%f\n",vector_in[i]);
    printf("============================================\n\n\n");
    
    //APLICACION DEL UNROLLED FIR FILTER
    vector_out[0] += vector_coef[0] * vector_in[0] + vector_coef[1] * vector_in[0] + vector_coef[2] * vector_in[0] + vector_coef[3] * vector_in[0] + vector_coef[4] * vector_in[0];
    vector_out[1] += vector_coef[1] * vector_in[1] + vector_coef[2] * vector_in[1] + vector_coef[3] * vector_in[1] + vector_coef[4] * vector_in[1] + vector_coef[5] * vector_in[1];
    vector_out[2] += vector_coef[2] * vector_in[2] + vector_coef[3] * vector_in[2] + vector_coef[4] * vector_in[2] + vector_coef[5] * vector_in[2] + vector_coef[6] * vector_in[2];
    vector_out[3] += vector_coef[3] * vector_in[3] + vector_coef[4] * vector_in[3] + vector_coef[5] * vector_in[3] + vector_coef[6] * vector_in[3] + vector_coef[7] * vector_in[3];
    vector_out[4] += vector_coef[4] * vector_in[4] + vector_coef[5] * vector_in[4] + vector_coef[6] * vector_in[4] + vector_coef[7] * vector_in[4] + vector_coef[8] * vector_in[4];
    vector_out[5] += vector_coef[5] * vector_in[5] + vector_coef[6] * vector_in[5] + vector_coef[7] * vector_in[5] + vector_coef[8] * vector_in[5] + vector_coef[9] * vector_in[5];
    vector_out[6] += vector_coef[6] * vector_in[6] + vector_coef[7] * vector_in[6] + vector_coef[8] * vector_in[6] + vector_coef[9] * vector_in[6] + vector_coef[10] * vector_in[6];
    vector_out[7] += vector_coef[7] * vector_in[7] + vector_coef[8] * vector_in[7] + vector_coef[9] * vector_in[7] + vector_coef[10] * vector_in[7] + vector_coef[11] * vector_in[7];
    vector_out[8] += vector_coef[8] * vector_in[8] + vector_coef[9] * vector_in[8] + vector_coef[10] * vector_in[8] + vector_coef[11] * vector_in[8] + vector_coef[12] * vector_in[8];
    vector_out[9] += vector_coef[9] * vector_in[9] + vector_coef[10] * vector_in[9] + vector_coef[11] * vector_in[9] + vector_coef[12] * vector_in[9] + vector_coef[13] * vector_in[9];



   	printf("============================================\n");
   	printf("\t\tVECTOR SALIDA:\n");
    for(i=0;i<SAMPLES+COEF-1;i++)
    	printf("%f\n",vector_out[i]);
   	printf("============================================\n");

    return 0;
}
