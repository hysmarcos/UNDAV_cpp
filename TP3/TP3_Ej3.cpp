#include<iostream>
#include <cstring>
#include<cstdlib>
#include<cstdio>

#define espacioEstacionamiento 10

using namespace std;

int verificaHora();
int verificaMinutos();
int verificaPatente();

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

int VerificaHora(){
	int horas;
	cout<<"Ingrese la hora del ingreso: ";
	cin>>horas;
	cin.clear();
	cin.ignore(20,'\n');
	cout<<endl;

	while(horas<7 or horas>21){
		cout<<"El valor ingresado no es correcto (debe ser entre 7 a 20), vuelva a ingresar: ";
		cin>>horas;
		cin.clear();
		cin.ignore(20,'\n');
		cout<<endl;
	}
	return horas;
}

int VerificaMinutos(int VM_hora){
	int minutos;
	if (VM_hora==21){
		minutos = 0;
	}
	else{
		cout<<"Ingrese los minutos del ingreso: ";
		cin>>minutos;
		cin.clear();
		cin.ignore(20,'\n');
		while(minutos<0 or minutos>59){
			cout<<"el valor ingresado no es correcto (solo de 0 a 59), vuelva a ingresar: ";
			cin>>minutos;
			cin.clear();
			cin.ignore(20,'\n');
			cout<<endl;
		}		
	}

	return minutos;
}

string VerificaPatente(){
	string VP_patente;
	do{
		cout << "Ingrese la patente: ";
		
		getline(cin, VP_patente);
	}while(VP_patente == "");
	return VP_patente;
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
	bool encontrePatente = false;
	EV_patenteRetirar = VerificaPatente();
	
	for (int i=0; i<tope; i++){
		if (EV_vehiculo[i].patente == EV_patenteRetirar){
			cout << "Se retira el vehiculo con patente "<< EV_vehiculo[i].patente << ". Hora de ingreso: " << EV_vehiculo[i].hora << ":" << EV_vehiculo[i].minuto << endl;
			EV_vehiculo[i] = BorroPatente();
			EV_cocheraOcupadas--;
			encontrePatente = true;
		}
	}
	if (encontrePatente == false){
		cout << "No se encontro la patente: " << EV_patenteRetirar << endl;
	}
	system("PAUSE");
}

vehiculos IngresoVehiculo (){
	vehiculos IV_vehiculo;
	
	IV_vehiculo.patente=VerificaPatente();
	
	IV_vehiculo.hora=VerificaHora();

	IV_vehiculo.minuto=VerificaMinutos(IV_vehiculo.hora);
	
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
	M_opcion = toupper(M_opcion);
	cin.ignore();
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
		if (opcion == 'I'){  // INGRESO DE VEHICULOS
			IngresoVehiculos(vehiculo, espacioEstacionamiento, cocheraOcupadas);
		}
		else if (opcion == 'S'){ // EGRESO DE VEHICULOS
			EgresoVehiculos(vehiculo, espacioEstacionamiento, cocheraOcupadas);
		}
		else if (opcion == 'L'){ // LISTA DE VEHICULOS
			ListadoVehiculos(vehiculo, espacioEstacionamiento);
		}
		else if (cocheraOcupadas>0){
			cout << "Hay vehiculos en el estacionamiento." << endl;
			system("PAUSE");
		}
		else{
			cout << "Menu incorrecto" << endl;
		}
		opcion = Menu();
	};
	cout << "No hay vehiculos.";
	return 0;
}


