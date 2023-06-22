#include <stdio.h>
#include <math.h>

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2);
void calcularPerimetro(float puntos[4][3], float *per, float *l1, float *l2, float *l3, float *l4, float *l5, float *l6);
float calcularArea(float *per, float *l1, float *l2, float *l3, float *l4, float *l5, float *l6);
void calcularVolumen(float area_base, float altura, float *volumen);

int main(int argc, char *argv[]) {

    float puntos[4][3] = {{0, 0, 3}, {3, 0, 0}, {0, 0, 0}, {1, 7, 1}};
    float per, l1, l2, l3, l4, l5, l6;
    calcularPerimetro(puntos, &per, &l1, &l2, &l3, &l4, &l5, &l6);
    float area_base = calcularArea(&per, &l1, &l2, &l3, &l4, &l5, &l6);
    float altura = 5.0;  
    float volumen;
    calcularVolumen(area_base, altura, &volumen);
    float area_superficial = area_base + l1 * altura + l2 * altura + l3 * altura + l4 * altura + l5 * altura + l6 * altura;
   
    printf("Perimetro de la base: %f\n", per);
    printf("Area de la base: %f\n", area_base);
    printf("Altura de la piramide: %f\n", altura);
    printf("Volumen de la piramide: %f\n", volumen);
    printf("Area superficial de la piramide: %f\n", area_superficial);
   
    return 0;
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2) {
    float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
    return dist;
}

void calcularPerimetro(float puntos[4][3], float *per, float *l1, float *l2, float *l3, float *l4, float *l5, float *l6) {
    *l1 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l2 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *l3 = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l4 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l5 = calcularDistancia(puntos[3][0], puntos[3][1], puntos[3][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l6 = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
}

float calcularArea(float *per, float *l1, float *l2, float *l3, float *l4, float *l5, float *l6) {
    float s = *per / 2;
    float area = sqrt(s * (s - *l1) * (s - *l2) * (s - *l3)) + sqrt(s * (s - *l4) * (s - *l5) * (s - *l6));
    return area;
}

void calcularVolumen(float area_base, float altura, float *volumen) {
    *volumen = (area_base * altura) / 3;
}
