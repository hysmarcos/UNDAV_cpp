/*
ESTE EJEMPLO:
-PERMITE EL INGRESO DE UNA LISTA DE ALUMNXS CON LOS DATOS: nombre, apellido y edad
QUE SE CARGAN EN UN VECTOR DE TAMAÑO 4. ES DECIR QUE, LA CANTIDAD MÁXIMA DE ALUMNXS
A CARGAR ES 4.
-MUESTRA LOS ALUMNXS INGRESADOS, DETALLANDO TODOS SUS DATOS.
*/
#include <iostream>
#include <cstring>
#define topeAlumnos 4

using namespace std;

struct persona{
	char nombre[20];
	char apellido[20];
	int edad =5;
};

void IngresarPersonas(persona personas[], int tope);
void InicializarPersonasVacias(persona personas[], int tope);
persona IngresarPersona();
persona PersonaVacia();
void MostrarPersonas(persona personas[], int tope);
bool EsPersonaVacia(persona persona);
void MostrarPersona(persona persona);


int main() {
	persona alumnos[topeAlumnos];
	
	cout << "****Ingresar alumnos****" <<endl;
    IngresarPersonas(alumnos, topeAlumnos);
    cout <<"****Alumnos ingresados****";
    MostrarPersonas(alumnos, topeAlumnos);
       
    return 0;
}

bool Continuar()
{
	char condicion;
	do
	{
	cout << "Desea continuar. Ingrese S (Si) o N (No): "<< endl;
	cin >> condicion;
	cin.ignore();
	}while (condicion!='S' && condicion !='N');
	if (condicion == 'S') 
		return true;
	else
		return false;	
}

void IngresarPersonas(persona personas[], int tope)
{
	bool continuar = true;
	InicializarPersonasVacias(personas,tope);
	for(int i=0; i<tope && continuar==true ; i++) 
	{
	  personas[i]=IngresarPersona();
	  continuar= Continuar();
    }
} 

void InicializarPersonasVacias(persona personas[], int tope)
{
	for(int i=0; i<tope; i++)
	{
		personas[i]= PersonaVacia();
    }
} 

persona PersonaVacia()
{
	persona persona;
	
	strcpy(persona.nombre,"");
	strcpy(persona.apellido,"");
	persona.edad= 0;
	 
	return persona;
}

persona IngresarPersona()
{
	persona persona;
	do
	{ 
		cout << endl<< "Ingrese nombre: "<< endl;
		cin.getline(persona.nombre,19);
		cout << "Ingrese apellido: "<< endl;
		cin.getline(persona.apellido,19);
	    cout<< "Ingrese edad (numerica): "<< endl; 
		cin>>persona.edad;
		cin.ignore();
	} while (strcmp(persona.nombre,"")==0 || strcmp(persona.apellido,"")==0 || persona.edad==0);
	
	return persona;
}


void MostrarPersonas(persona personas[], int tope)
{
	for (int i=0; i<tope && EsPersonaVacia(personas[i])==false ; i++)  
    {
    	MostrarPersona(personas[i]);
	}
}

bool EsPersonaVacia(persona persona)
{	
	if(	strcmp(persona.nombre,"")==0 && strcmp(persona.apellido,"")==0 && persona.edad==0) 
	return true;
	else
	return false;	
}

void MostrarPersona(persona persona)
{
	cout << endl << "Nombre: "<< persona.nombre << endl;
	cout << "Apellido: " << persona.apellido << endl;
	cout << "Edad: " << persona.edad << endl;
}
