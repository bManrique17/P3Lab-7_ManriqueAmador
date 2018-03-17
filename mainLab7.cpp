#include <string>
#include "Racional.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int menu();
void crearFraccion();
void suma();
void sumaAsignacion();
void resta();
void restaAsignacion();
void multiplicacion();
void multiplicacionAsignacion();
void division();
void divisionAsignacion();
void imprimirFraccion(Racional*);
void guardarArchivo(string);

vector <Racional*> listaFracciones;

int main(){
    Racional* f1 = new Racional(10,18);
    Racional* f2 = new Racional(10,18);
    const Racional* res = *f1 + *f2;     
    cout<<res->getNumerador()<<" / "<<res->getDenominador()<<endl;
    Racional* f5 = new Racional(5,2);
    Racional* f4 = new Racional(5,2);
    *f5 += *f4;
    cout<<f5->getDenominador();
    int opcion;    
    do{
        opcion = menu();
        if(opcion!=1 && listaFracciones.size()<2){
            cout<<"\n**No hay fracciones suficientes para operar\n"<<endl;
            opcion = 10;
        }

        switch(opcion){
            case 1:
                crearFraccion();
            break;
            case 2:
                suma();
            break;
            case 3:
                sumaAsignacion();
            break;
            case 4:
                resta();
            break;
            case 5:
                restaAsignacion();
            break;
            case 6:
                multiplicacion();
            break;
            case 7:
                multiplicacionAsignacion();
            break;
            case 8:
                division();
            break;
            case 9:
                divisionAsignacion();
            break;
            case 0:
                opcion = 0;
            break;
            default:
            break;
        }
    }while(opcion != 0);

}

int menu(){
    cout<<"CASIO C++ ExpertCalculatorMaster1.0"<<endl;
    cout<<"(1)Crear fraccion"<<endl
        <<"(2)Suma"<<endl
        <<"(3)Suma y asignacion"<<endl
        <<"(4)Resta"<<endl
        <<"(5)Resta y asignacion"<<endl
        <<"(6)Multiplicacion"<<endl
        <<"(7)Multiplicacion y asignacion"<<endl
        <<"(8)Division"<<endl
        <<"(9)Division y asignacion"<<endl
        <<"(0)Salir"<<endl
        <<"->Ingrese su opcion: ";
    int respuesta;
    cin>>respuesta;
    return respuesta;    
}

void crearFraccion(){
    int num=1,den=0;
    while(den==0){        
        cout<<"    *Crear fraccion"<<endl;
        cout<<"->Ingrese el numerador: ";
        cin>>num;
        cout<<"->Ingrese el denominador(no puede ser 0): ";
        cin>>den;
        listaFracciones.push_back(new Racional(num,den));
        cout<<"[Fraccion creada]\n"<<endl;
    }
}

void suma(){
    int indice1,indice2;
    cout<<"    *Sumar"<<endl;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }
    cout<<"->Seleccione su primera fraccion: ";
    cin>>indice1;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }    
    cout<<"->Seleccione su segunda fraccion: ";
    cin>>indice2;
    indice1--;
    indice2--;
    const Racional* resActual;    
    resActual = *listaFracciones[indice1] + *listaFracciones[indice2];
    int den1,num1,den2,num2;
    den1 = (listaFracciones[indice1])->getDenominador();
    den2 = (listaFracciones[indice2])->getDenominador();
    num1 = (listaFracciones[indice1])->getNumerador();
    num2 = (listaFracciones[indice2])->getNumerador();
    cout<<"Operacion: "<<num1<<"/"<<den1<<" + "<<num2<<"/"<<den2<<" = "<<resActual->getNumerador()<<"/"<<resActual->getDenominador()<<endl;
    string operacion,espacio = "_";
    stringstream sstream;
    sstream<<"Operacion:"<<espacio<<num1<<"/"<<den1<<espacio<<"+"<<espacio<<num2<<"/"<<den2<<espacio<<"="<<espacio<<resActual->getNumerador()<<"/"<<resActual->getDenominador()<<endl;
    sstream>>operacion;
    guardarArchivo(operacion);
}

void sumaAsignacion(){
    int indice1,indice2;
    cout<<"    *Sumar y asignar"<<endl;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }
    cout<<"->Seleccione su primera fraccion: ";
    cin>>indice1;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }    
    cout<<"->Seleccione su segunda fraccion: ";
    cin>>indice2;
    indice1--;
    indice2--;        
    int den1,num1,den2,num2;
    num1 = (listaFracciones[indice1])->getNumerador();
    num2 = (listaFracciones[indice2])->getNumerador();
    *listaFracciones[indice1] += *listaFracciones[indice2];
    
    den1 = (listaFracciones[indice1])->getDenominador();
    den2 = (listaFracciones[indice2])->getDenominador();
    
    cout<<"Operacion:"<<num1<<"/"<<den1<<"+="<<num2<<"/"<<den2<<endl;
    string operacion,espacio = "_";
    stringstream acumulador;
    acumulador<<"Operacion:"<<espacio<<num1<<"/"<<den1<<espacio<<"+="<<espacio<<num2<<"/"<<den2<<endl;
    acumulador>>operacion;
    guardarArchivo(operacion);
}

void resta(){
    int indice1,indice2;
    cout<<"    *Restar"<<endl;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }
    cout<<"->Seleccione su primera fraccion: ";
    cin>>indice1;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }    
    cout<<"->Seleccione su segunda fraccion: ";
    cin>>indice2;
    indice1--;
    indice2--;
    const Racional* resActual;    
    resActual = *listaFracciones[indice1] - *listaFracciones[indice2];
    int den1,num1,den2,num2;
    den1 = (listaFracciones[indice1])->getDenominador();
    den2 = (listaFracciones[indice2])->getDenominador();
    num1 = (listaFracciones[indice1])->getNumerador();
    num2 = (listaFracciones[indice2])->getNumerador();
    cout<<"Operacion: "<<num1<<"/"<<den1<<" - "<<num2<<"/"<<den2<<" = "<<resActual->getNumerador()<<"/"<<resActual->getDenominador()<<endl;
    
    string operacion,espacio = "_";
    stringstream acumulador;
    acumulador<<"Operacion:"<<espacio<<num1<<"/"<<den1<<espacio<<"-"<<espacio<<num2<<"/"<<den2<<espacio<<"="<<espacio<<resActual->getNumerador()<<"/"<<resActual->getDenominador()<<endl;
    acumulador>>operacion;
    guardarArchivo(operacion);
}

void restaAsignacion(){
    int indice1,indice2;
    cout<<"    *Restar y asignar"<<endl;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }
    cout<<"->Seleccione su primera fraccion: ";
    cin>>indice1;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }    
    cout<<"->Seleccione su segunda fraccion: ";
    cin>>indice2;
    indice1--;
    indice2--;        
    int den1,num1,den2,num2;
    num1 = (listaFracciones[indice1])->getNumerador();
    num2 = (listaFracciones[indice2])->getNumerador();
    *listaFracciones[indice1] -= *listaFracciones[indice2];
    
    den1 = (listaFracciones[indice1])->getDenominador();
    den2 = (listaFracciones[indice2])->getDenominador();
    
    cout<<"Operacion: "<<num1<<"/"<<den1<<" -= "<<num2<<"/"<<den2<<endl;

    string operacion,espacio = "_";
    stringstream acumulador;
    acumulador<<"Operacion:"<<espacio<<num1<<"/"<<den1<<espacio<<"-="<<espacio<<num2<<"/"<<den2<<endl;
    acumulador>>operacion;
    guardarArchivo(operacion);
}

void multiplicacion(){
    int indice1,indice2;
    cout<<"    *Multiplicar"<<endl;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }
    cout<<"->Seleccione su primera fraccion: ";
    cin>>indice1;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }    
    cout<<"->Seleccione su segunda fraccion: ";
    cin>>indice2;
    indice1--;
    indice2--;
    const Racional* resActual;    
    resActual = *listaFracciones[indice1] * *listaFracciones[indice2];
    int den1,num1,den2,num2;
    den1 = (listaFracciones[indice1])->getDenominador();
    den2 = (listaFracciones[indice2])->getDenominador();
    num1 = (listaFracciones[indice1])->getNumerador();
    num2 = (listaFracciones[indice2])->getNumerador();
    cout<<"Operacion: "<<num1<<"/"<<den1<<" * "<<num2<<"/"<<den2<<" = "<<resActual->getNumerador()<<"/"<<resActual->getDenominador()<<endl;

    string operacion,espacio = "_";
    stringstream acumulador;
    acumulador<<"Operacion:"<<espacio<<num1<<"/"<<den1<<espacio<<"*"<<espacio<<num2<<"/"<<den2<<espacio<<"="<<espacio<<resActual->getNumerador()<<"/"<<resActual->getDenominador()<<endl;
    acumulador>>operacion;
    guardarArchivo(operacion);
}

void multiplicacionAsignacion(){
    int indice1,indice2;
    cout<<"    *Multiplicar y asignar"<<endl;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }
    cout<<"->Seleccione su primera fraccion: ";
    cin>>indice1;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }    
    cout<<"->Seleccione su segunda fraccion: ";
    cin>>indice2;
    indice1--;
    indice2--;        
    int den1,num1,den2,num2;
    num1 = (listaFracciones[indice1])->getNumerador();
    num2 = (listaFracciones[indice2])->getNumerador();
    *listaFracciones[indice1] *= *listaFracciones[indice2];
    
    den1 = (listaFracciones[indice1])->getDenominador();
    den2 = (listaFracciones[indice2])->getDenominador();
    
    cout<<"Operacion: "<<num1<<"/"<<den1<<" *= "<<num2<<"/"<<den2<<endl;

    string operacion,espacio = "_";
    stringstream acumulador;
    acumulador<<"Operacion:"<<espacio<<num1<<"/"<<den1<<espacio<<"*="<<espacio<<num2<<"/"<<den2<<endl;
    acumulador>>operacion;
    guardarArchivo(operacion);
}

void division(){
    int indice1,indice2;
    cout<<"    *Dividir"<<endl;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }
    cout<<"->Seleccione su primera fraccion: ";
    cin>>indice1;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }    
    cout<<"->Seleccione su segunda fraccion: ";
    cin>>indice2;
    indice1--;
    indice2--;
    const Racional* resActual;    
    resActual = *listaFracciones[indice1] / *listaFracciones[indice2];
    int den1,num1,den2,num2;
    den1 = (listaFracciones[indice1])->getDenominador();
    den2 = (listaFracciones[indice2])->getDenominador();
    num1 = (listaFracciones[indice1])->getNumerador();
    num2 = (listaFracciones[indice2])->getNumerador();
    cout<<"Operacion: "<<num1<<"/"<<den1<<" / "<<num2<<"/"<<den2<<" = "<<resActual->getNumerador()<<"/"<<resActual->getDenominador()<<endl;

    string operacion,espacio = "_";
    stringstream acumulador;
    acumulador<<"Operacion:"<<espacio<<num1<<"/"<<den1<<espacio<<"/"<<espacio<<num2<<"/"<<den2<<espacio<<"="<<espacio<<resActual->getNumerador()<<"/"<<resActual->getDenominador()<<endl;
    acumulador>>operacion;
    guardarArchivo(operacion);
}

void divisionAsignacion(){
    int indice1,indice2;
    cout<<"    *Dividir y asignar"<<endl;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }
    cout<<"->Seleccione su primera fraccion: ";
    cin>>indice1;
    for(int i = 0 ; i<listaFracciones.size() ; i++){
        cout<<(i+1)<<"--"<<listaFracciones[i]->getNumerador()<<"/"<<listaFracciones[i]->getDenominador()<<endl;
    }    
    cout<<"->Seleccione su segunda fraccion: ";
    cin>>indice2;
    indice1--;
    indice2--;        
    int den1,num1,den2,num2;
    num1 = (listaFracciones[indice1])->getNumerador();
    num2 = (listaFracciones[indice2])->getNumerador();
    *listaFracciones[indice1] /= *listaFracciones[indice2];
    
    den1 = (listaFracciones[indice1])->getDenominador();
    den2 = (listaFracciones[indice2])->getDenominador();
    
    cout<<"Operacion: "<<num1<<"/"<<den1<<" /= "<<num2<<"/"<<den2<<endl;

    string operacion,espacio = "_";
    stringstream acumulador;
    acumulador<<"Operacion:"<<espacio<<num1<<"/"<<den1<<espacio<<"/="<<espacio<<num2<<"/"<<den2<<endl;
    acumulador>>operacion;
    guardarArchivo(operacion);
}

void imprimirFraccion(Racional* fraccion){
    int den1,num1;
    den1 = fraccion->getDenominador();    
    num1 = fraccion->getNumerador();    
    cout<<num1<<"/"<<den1<<" / "<<endl;
}

void guardarArchivo(string operacion){

    ofstream escritor;    
    escritor.open("bitacoraCalculadora.txt",ios::app);
    
    escritor<<operacion+"\n";
    
	escritor.close();
}
/*
vector<Cancion*> DataCanciones:: getCanciones(string file){
    vector<Cancion*> retval;

    //strng a carater
    //el string.c_str()

    //abrir archivo
   ifstream canciones (file.c_str());

    //mientras hay lineas en el archivo
    if(canciones.is_open()){
        while(!canciones.eof()){
            //Leer una linea
            string line;
            getline(canciones,line);
            if(line=="."){
                break;
            }

            //Parsearla linea y agrear al vector
            Cancion* leido= nuevaCancion(line);
            //TODO: valdar
            retval.push_back(leido);

        }

        //cerrar al archivo}
        canciones.close();

    }

    return retval;


}*/