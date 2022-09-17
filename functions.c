#include <math.h>
double invertirNumero (double numeroInvertir)
{
    return 1/numeroInvertir;
}
//Obtencion de Xl y Xc
double obtainXl(double w,double Frecuencia,double Inductancia)
{
    if (Frecuencia == 0)
    {
        return (w*Inductancia);
    }
    else {
        return (2 * M_PI * Frecuencia * Inductancia);
    }
}
double obtainXc(double w,double Frecuencia,double Capacitancia)
{
    if (Frecuencia == 0)
    {
        return (1/(w*Capacitancia));
    }
    else {
        return (1/(2 * M_PI * Frecuencia * Capacitancia));
    }
}

//Obtencion de la impedancia total

double obtainZ(int esSerie,double Resistencia, double Xl, double Xc)
{
    if (esSerie == 1)
    {
        return (sqrt(pow(Resistencia,2) + pow(Xl-Xc,2)));
    }
    else {
        return invertirNumero(sqrt(pow(invertirNumero(Resistencia),2) + pow((invertirNumero(Xl)- invertirNumero(Xc)),2)));
    }
}
double obtainAngulo(int esSerie,double Resistencia, double Xl, double Xc)
{
    if (esSerie == 1)
    {
        return ((atan((Xl-Xc)/Resistencia)) * 180 / M_PI);
    }
    else {
        return ((atan((invertirNumero(Xl)- invertirNumero(Xc))/invertirNumero(Resistencia))) * 180 / M_PI);
    }
}
//Obtencio de intensidades
double obtainIntensidad(double voltaje,double Z)
{
    return (voltaje/Z);
}
double obtainIntensidadResistencia(double voltaje,double Resistencia)
{
    return (voltaje/Resistencia);
}
double obtainIntensidadBobina(double voltaje,double Xl, double Xc)
{
    return (voltaje/Xl);
}
double obtainIntensidadCapacitor(double voltaje,double Xl, double Xc)
{
    return (voltaje/Xc);
}

//Obtencion Factor de potencia
double obtainFactorPotencia(double desfaseLinea,double angulo)
{
    return (desfaseLinea-angulo);
}
