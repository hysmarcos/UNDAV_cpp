#include<iostream>
#include <cstring>
#include<cstdlib>
#include<cstdio>

#define espacioEstacionamiento 2

using namespace std;

struct vehiculos{
	string patente;
	int hora;
	int minuto;
};

vehiculos BorroPatente(){
	vehiculos automovil;
	automovil.patente = "";
	automovil.hora = 0;
	automovil.minuto = 0;
	return automovil;
}

void BorroPatentes(vehiculos BP_vehiculo[], int tope){
	for (int i=0; i<tope; i++){
		BP_vehiculo[i] = BorroPatente();
		cout << BP_vehiculo[i].patente<<endl;
	}
}

void ListadoVehiculos(vehiculos LV_vehiculos[], int tope){
	cout << "Num. Cochera     | Patente   |   Hora Ingreso " <<endl;
	for(int i=0; i<tope; i++){

		cout << "     " <<i+1 << "                 " << LV_vehiculos[i].patente << "        " << LV_vehiculos[i].hora << ":" << LV_vehiculos[i].minuto << endl;
	}
	system ("PAUSE");
}

void EgresoVehiculos(vehiculos EV_vehiculo[], int tope, int &EV_cocheraOcupadas){
	string EV_patenteRetirar;
	int i = 0;
	cout << "Ingrese la patente a retirar: ";
	cin >> EV_patenteRetirar;
	
	for (int i=0; i<tope; i++){
		if (EV_vehiculo[i].patente == EV_patenteRetirar){
			cout << "Se retira el vehiculo con patente "<< EV_vehiculo[i].patente << ". Hora de ingreso: " << EV_vehiculo[i].hora << ":" << EV_vehiculo[i].minuto << endl;
			EV_vehiculo[i] = BorroPatente();
			EV_cocheraOcupadas--;
		}
	}
}

vehiculos IngresoVehiculo (){
	vehiculos IV_vehiculo;
	do{
		cout << "Ingrese la patente: ";
		cin >> IV_vehiculo.patente;
		cin.ignore();		
	}while(IV_vehiculo.patente=="");
	do{
		cout << "Ingrese la hora de ingreso: ";
		cin >> IV_vehiculo.hora;
		cin.ignore();		
	}while(IV_vehiculo.hora<7 || IV_vehiculo.hora>20);
	do{
		cout << "Ingrese el minuto de ingreso: ";
		cin >> IV_vehiculo.minuto;
		cin.ignore();	
	}while(IV_vehiculo.minuto<0 || IV_vehiculo.minuto>59);

	return IV_vehiculo;
}

void BuscoEspacioLibre(vehiculos BEL_vehiculo, bool &BEL_encuentroEspacio){
	if(BEL_vehiculo.patente == ""){
		BEL_encuentroEspacio = true;
	}
}

void IngresoVehiculos(vehiculos IV_vehiculo[], int tope, int &IV_cocheraOcupadas){
	int numCochera = -1;
	bool encuentroEspacio = false;
	while(numCochera<tope && encuentroEspacio == false){
		numCochera++;
		BuscoEspacioLibre(IV_vehiculo[numCochera], encuentroEspacio);
		cout << "numCochera " << numCochera<<endl; 
		cout << "encuentroEspacio " << encuentroEspacio << endl;
	}
	if (encuentroEspacio==true){
		cout << "Numero espacio libre: " << numCochera+1 << endl;
		IV_vehiculo[numCochera] = IngresoVehiculo();
		IV_cocheraOcupadas++;
	}
	else{
		cout << "No hay espacios libres.";
	}
}

char Menu (){
	char M_opcion;
	system("CLS");
	cout<<"---|       BIENVENIDO         |---"<<endl<<endl;
	cout<<"     Ingresar vehiculo------->(I): "<<endl;
	cout<<"     Salida vehiculo--------->(S): "<<endl;
	cout<<"     Lista de vehiculos ----->(L): "<<endl;
	cout<<"     Fin--------------------->(F): "<<endl<<endl;
	cout<<"ingrese opcion: ";
	cin  >> M_opcion;
	system("CLS");
	return M_opcion;
}

int main(){
	vehiculos vehiculo[espacioEstacionamiento];
	int cocheraOcupadas=0;
	char opcion;
	opcion = Menu();
	BorroPatentes(vehiculo, espacioEstacionamiento);
	while(opcion!='F' || cocheraOcupadas>0){
		cout << "-  COCHERAS OCUPADAS = "<<cocheraOcupadas<< " DE "<< espacioEstacionamiento << "  -" << endl;
		cout << "--------------------------------" << endl << endl;
		if (opcion == 'I' || opcion == 'i'){  // INGRESO DE VEHICULOS
			IngresoVehiculos(vehiculo, espacioEstacionamiento, cocheraOcupadas);
		}
		else if (opcion == 'S' || opcion == 's'){ // EGRESO DE VEHICULOS
			EgresoVehiculos(vehiculo, espacioEstacionamiento, cocheraOcupadas);
		}
		else if (opcion == 'L' || opcion == 'l'){ // LISTA DE VEHICULOS
			ListadoVehiculos(vehiculo, espacioEstacionamiento);
		}
		else if (cocheraOcupadas>0){
			cout << "Hay vehiculos en el estacionamiento." << endl;
		}
		else{
			cout << "Menu incorrecto" << endl;
		}
		opcion = Menu();
	};
	cout << "No hay vehiculos.";
	return 0;
}
