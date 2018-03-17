#ifndef RACIONAL_H
#define RACIONAL_H

#include <string>
#include <stdlib.h>

using namespace std;

class Racional{
    private:        
        int numerador, denominador;
    public:
        Racional();        
        Racional(int,int);
        int getNumerador()const;
        int getDenominador()const;
        void setNumerador(int);
        void setDenominador(int);  
        void simplificarFraccion(int,int);
        const Racional* operator+(const Racional&)const;        
        const Racional* operator+=(const Racional&);        
        
        const Racional* operator-(const Racional&)const;
        const Racional* operator-=(const Racional&);                
        const Racional* operator*(const Racional&)const;
        const Racional* operator*=(const Racional&);
        const Racional* operator/(const Racional&)const;
        const Racional* operator/=(const Racional&);             
        
};
#endif