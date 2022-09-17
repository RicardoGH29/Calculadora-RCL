#include <stdio.h>
#include <math.h>
#include "functions.c"
double voltaje;
double desfase;
int siFrecuencia;
double r;
double c;
double l;
int esSerie;


double frecuencia;
double w;

int main() {
    printf("Calculadora circuito RCL\n");
    printf("Digite o valor del Voltaje: ");
    scanf("%lf", &voltaje);
    printf("Digite o valor del desfase: ");
    scanf("%lf", &desfase);
    printf("Se tiene el valor de frecuencia? (1 = si, 0 = no): ");
    scanf("%i", &siFrecuencia);
    if (siFrecuencia == 1) {
        printf("Digite el valor de la frecuencia: ");
        scanf("%lf", &frecuencia);
    } else {
        printf("Digite el valor de la W: ");
        scanf("%lf", &w);
    }
    printf("Digite o valor de R: ");
    scanf("%lf", &r);
    printf("Digite o valor de C: ");
    scanf("%lf", &c);
    printf("Digite o valor de L: ");
    scanf("%lf", &l);
    printf("El circuito es serie o paralelo? (1 = serie, 0 = paralelo): ");
    scanf("%i", &esSerie);
    double xl = obtainXl(w,frecuencia, l);
    double xc = obtainXc(w,frecuencia, c);
    printf(" Xl: %lf", xl);
    printf(" Xc: %lf", xc);
    double z = obtainZ(esSerie, r, xl, xc);
    printf(" Z: %lf", z);
    double angulo = obtainAngulo( esSerie,r, xl, xc);
    printf(" Angulo: %lf", angulo);
    double intensidadTotal = obtainIntensidad(voltaje, z);
    printf(" Intensidad: %lf", intensidadTotal);
    if (esSerie == 0) {
        double intensidadResistencia = obtainIntensidadResistencia(voltaje, r);
        printf(" Intensidad Resistencia: %lf", intensidadResistencia);
        double intensidadBobina = obtainIntensidadBobina(voltaje, xl, xc);
        printf(" Intensidad Bobina: %lf", intensidadBobina);
        double intensidadCapacitor = obtainIntensidadCapacitor(voltaje, xl, xc);
        printf(" Intensidad Capacitor: %lf", intensidadCapacitor);
    }
    printf(" Factor de potencia: %lf", obtainFactorPotencia(desfase,angulo));
}
