#include "Racional.h"
#include <string>
#include <stdlib.h>

using namespace std;

Racional::Racional(){}        

Racional::Racional(int num,int den){
    int mayor,menor,cont;
    if(num>den){
        mayor = num;
        menor = den;
    }else{
        mayor = den;
        menor = num;
    }
    do{
        cont = 0;
        for(int i=1 ; i<=menor ;i++){
            if(num%i==0 && den%i==0){
                num=num/i;
                den=den/i;
            }
        }
        for(int j=2 ; j<=menor ;j++){
            if(num%j == 0 && den%j == 0)
                cont++;
        }
    }while(cont>0);

    numerador = num;
    denominador = den;
}


int Racional::getNumerador() const{
    return numerador;
}

int Racional::getDenominador() const{
    return denominador;
}

void Racional::setNumerador(int num){
    numerador = num;
}

void Racional::setDenominador(int den){
    denominador = den;
}

void Racional::simplificarFraccion(int num, int den){
    int mayor,menor,cont;
    if(num>den){
        mayor = num;
        menor = den;
    }else{
        mayor = den;
        menor = num;
    }
    do{
        cont = 0;
        for(int i=1 ; i<=menor ;i++){
            if(num%i==0 && den%i==0){
                num=num/i;
                den=den/i;
            }
        }
        for(int j=2 ; j<=menor ;j++){
            if(num%j == 0 && den%j == 0)
                cont++;
        }
    }while(cont>0);

    numerador = num;
    denominador = den;
}

const Racional* Racional::operator+(const Racional& fraccion)const{
    int den,num;
    den = denominador * fraccion.getDenominador();
    num = (den / denominador) * numerador  + (den / fraccion.getDenominador()) * fraccion.getNumerador();
    return new Racional(num,den);
}


const Racional* Racional::operator+=(const Racional& fraccion){
        
    int den,num;
    den = denominador * fraccion.getDenominador();
    num = (den / denominador) * numerador  + (den / fraccion.getDenominador()) * fraccion.getNumerador();

    simplificarFraccion(num,den);
}
//no probados

const Racional* Racional::operator-(const Racional& fraccion)const{
    int den,num;
    den = denominador * fraccion.getDenominador();
    num = (den / denominador) * numerador  - (den / fraccion.getDenominador()) * fraccion.getNumerador();
    return new Racional(num,den);
}

const Racional* Racional::operator-=(const Racional& fraccion){
    int den,num;
    den = denominador * fraccion.getDenominador();
    num = (den / denominador) * numerador  - (den / fraccion.getDenominador()) * fraccion.getNumerador();

    simplificarFraccion(num,den);
}

const Racional* Racional::operator*(const Racional& fraccion)const{
    int den,num;
    den = denominador * fraccion.getDenominador();
    num = numerador * fraccion.getNumerador();
    return new Racional(num,den);
}

const Racional* Racional::operator*=(const Racional& fraccion){
    int den,num;
    den = denominador * fraccion.getDenominador();
    num = numerador * fraccion.getNumerador();

    simplificarFraccion(num,den);
}

const Racional* Racional::operator/(const Racional& fraccion)const{
    int den,num;
    num = numerador * fraccion.getDenominador();
    den = denominador * fraccion.getNumerador();
    return new Racional(num,den);
}

const Racional* Racional::operator/=(const Racional& fraccion){
    int den,num;
    num = numerador * fraccion.getDenominador();
    den = denominador * fraccion.getNumerador();
    simplificarFraccion(num,den);
}
