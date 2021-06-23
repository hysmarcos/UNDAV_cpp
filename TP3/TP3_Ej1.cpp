#include <iostream>
#include <cstring>

#define diasSemana 7

using namespace std;

struct tiempo{
	int hora;
	int minutos;
	int segundos;
};

void MuestroTiempo(tiempo MT_diaSemana){
	cout << "Tiempo: "<< MT_diaSemana.hora << ":" << MT_diaSemana.minutos << ":" << MT_diaSemana.segundos <<endl<<endl;
}

void EvaluoTiempo(tiempo ET_diaSemana, tiempo ET_tiempoMinimo, int dia){
	if (ET_diaSemana.hora == ET_tiempoMinimo.hora){
		if (ET_diaSemana.minutos == ET_tiempoMinimo.minutos){
			if (ET_diaSemana.segundos == ET_tiempoMinimo.segundos){
				cout << "Dia " << dia+1 << endl;
			}
		}
	}
}

void MuestroEstadisticas(tiempo IDS_diaSemana[], tiempo ME_tiempoPromedio, tiempo ME_tiempoMinimo, tiempo ME_tiempoMaximo, int tope){
	int ME_horasASegundos = ME_tiempoPromedio.hora * 3600;
	int ME_minutosASegundos = ME_tiempoPromedio.minutos * 60;
	int ME_totalSegundos = (ME_horasASegundos + ME_minutosASegundos + ME_tiempoPromedio.segundos) / tope;

	// Mejor tiempo
	cout << "Mejor tiempo: " << ME_tiempoMinimo.hora << ":" << ME_tiempoMinimo.minutos << ":" << ME_tiempoMinimo.segundos <<endl;
	cout << "Dias con mejor tiempo: " << endl;
	for (int i=0; i<tope; i++){
		EvaluoTiempo(IDS_diaSemana[i], ME_tiempoMinimo, i);
	}
	// Peor tiempo
	cout << endl << "Peor tiempo: " << ME_tiempoMaximo.hora << ":" << ME_tiempoMaximo.minutos << ":" << ME_tiempoMaximo.segundos <<endl;
	cout << "Dias con peor tiempo: " << endl;
	for (int i=0; i<tope; i++){
		EvaluoTiempo(IDS_diaSemana[i], ME_tiempoMaximo, i);
	}	
	// Tiempo promedio
	ME_tiempoPromedio.hora = (ME_totalSegundos) / 3600;
	ME_tiempoPromedio.minutos = (ME_totalSegundos - ME_tiempoPromedio.hora * 3600 ) / 60;
	ME_tiempoPromedio.segundos = (ME_totalSegundos - (ME_tiempoPromedio.hora * 3600) - (ME_tiempoPromedio.minutos * 60));
	cout << endl << "Tiempo promedio: " << ME_tiempoPromedio.hora << ":" << ME_tiempoPromedio.minutos << ":" << ME_tiempoPromedio.segundos <<endl;
}

void CalculoTiempos(tiempo CT_diaSemana, tiempo &CT_tiempoPromedio, tiempo &CT_tiempoMinimo, tiempo &CT_tiempoMaximo){
	int CT_horasASegundos, CT_minutosASegundos, CT_totalSegundos, CT_segundosAHoras, CT_segundosAMinutos;
	// Si el tiempo minimo es igual a 0, le asigno el valor del tiempo a calcular
	if (CT_tiempoMinimo.hora == 0 && CT_tiempoMinimo.minutos == 0 && CT_tiempoMinimo.segundos == 0){
		CT_tiempoMinimo.hora = CT_diaSemana.hora;
		CT_tiempoMinimo.minutos = CT_diaSemana.minutos;
		CT_tiempoMinimo.segundos = CT_diaSemana.segundos;
		CT_tiempoMaximo.hora = CT_diaSemana.hora;
		CT_tiempoMaximo.minutos = CT_diaSemana.minutos;
		CT_tiempoMaximo.segundos = CT_diaSemana.segundos;		
	}
	
	
	// Calculo tiempo minimo y maximo
	else{
		// Calculo tiempo minimo
		if (CT_diaSemana.hora < CT_tiempoMinimo.hora){
			CT_tiempoMinimo.hora = CT_diaSemana.hora;
			CT_tiempoMinimo.minutos = CT_diaSemana.minutos;
			CT_tiempoMinimo.segundos = CT_diaSemana.segundos;
		}
		else if (CT_diaSemana.hora == CT_tiempoMinimo.hora){
			if (CT_diaSemana.minutos < CT_tiempoMinimo.minutos){
				CT_tiempoMinimo.hora = CT_diaSemana.hora;
				CT_tiempoMinimo.minutos = CT_diaSemana.minutos;
				CT_tiempoMinimo.segundos = CT_diaSemana.segundos;
			}
			else if(CT_diaSemana.minutos == CT_tiempoMinimo.minutos){
				if(CT_diaSemana.segundos < CT_tiempoMinimo.segundos){
					CT_tiempoMinimo.hora = CT_diaSemana.hora;
					CT_tiempoMinimo.minutos = CT_diaSemana.minutos;
					CT_tiempoMinimo.segundos = CT_diaSemana.segundos;
				}
			}
		}
		// Calculo tiempo maximo
		if (CT_diaSemana.hora > CT_tiempoMaximo.hora){
			CT_tiempoMaximo.hora = CT_diaSemana.hora;
			CT_tiempoMaximo.minutos = CT_diaSemana.minutos;
			CT_tiempoMaximo.segundos = CT_diaSemana.segundos;
		}
		else if (CT_diaSemana.hora == CT_tiempoMaximo.hora){
			if(CT_diaSemana.minutos > CT_tiempoMaximo.minutos){
				CT_tiempoMaximo.hora = CT_diaSemana.hora;
				CT_tiempoMaximo.minutos = CT_diaSemana.minutos;
				CT_tiempoMaximo.segundos = CT_diaSemana.segundos;
			}
			else if(CT_diaSemana.minutos == CT_tiempoMaximo.minutos){
				if(CT_diaSemana.segundos > CT_tiempoMaximo.segundos){
					CT_tiempoMaximo.hora = CT_diaSemana.hora;
					CT_tiempoMaximo.minutos = CT_diaSemana.minutos;
					CT_tiempoMaximo.segundos = CT_diaSemana.segundos;
				}
			}
		}
	}
	// Suma de tiempo promedio
	CT_tiempoPromedio.hora = CT_tiempoPromedio.hora + CT_diaSemana.hora;
	CT_tiempoPromedio.minutos = CT_tiempoPromedio.minutos + CT_diaSemana.minutos;
	CT_tiempoPromedio.segundos = CT_tiempoPromedio.segundos + CT_diaSemana.segundos;
}

void MuestroTiempos(tiempo MT_diaSemana[], int tope){
	for (int i=0; i<tope; i++){
		cout<< endl << "Dia " << i+1 << endl;
    	MuestroTiempo(MT_diaSemana[i]);
	}	
}

tiempo IngresoTiempoDia(int dia){
	tiempo ITD_tiempoDia;
	cout<< endl << "Dia " << dia+1 << endl;
	do{ 
		do{
			cout << endl<< "Ingrese la hora: ";
			cin >> ITD_tiempoDia.hora;
			cin.ignore();			
		}while(ITD_tiempoDia.hora<0);
		do{
			cout << endl<< "Ingrese los minutos: ";
			cin >> ITD_tiempoDia.minutos;
			cin.ignore();			
		}while(ITD_tiempoDia.minutos<0 || ITD_tiempoDia.minutos>59);
		do{
			cout << endl<< "Ingrese los segundos: ";
			cin >> ITD_tiempoDia.segundos;
			cin.ignore();			
		}while(ITD_tiempoDia.segundos<0 || ITD_tiempoDia.segundos>59);
	} while (ITD_tiempoDia.hora==0 && ITD_tiempoDia.minutos==0 && ITD_tiempoDia.segundos==0);
	cout<<endl;
	return ITD_tiempoDia;
}


tiempo DiaVacio (){
	tiempo DV_diaVacio;
	DV_diaVacio.hora = 0;
	DV_diaVacio.minutos = 0;
	DV_diaVacio.segundos = 0;
	return DV_diaVacio;
}

void InicializoDiaVacio(tiempo IDV_diaSemana[], int tope){
	for (int i=0; i<tope; i++){
		IDV_diaSemana[i] = DiaVacio();
	}
}

void IngresoDiaSemana(tiempo IDS_diaSemana[], int tope){
	tiempo IDS_tiempoPromedio = {0, 0, 0}, IDS_tiempoMaximo = {0, 0, 0}, IDS_tiempoMinimo = {0, 0, 0};
	int posTiempoMax[tope], posTiempoMin[tope], i=0;
	InicializoDiaVacio(IDS_diaSemana, tope);
	for (int i=0; i<tope; i++){
		IDS_diaSemana[i] = IngresoTiempoDia(i);
		CalculoTiempos(IDS_diaSemana[i], IDS_tiempoPromedio, IDS_tiempoMinimo, IDS_tiempoMaximo);
	}
	cout << "-- Estadisticas --" << endl << endl;
	MuestroEstadisticas(IDS_diaSemana, IDS_tiempoPromedio, IDS_tiempoMinimo, IDS_tiempoMaximo, tope);
}

int main(){
	tiempo diaSemana[diasSemana];
	IngresoDiaSemana(diaSemana, diasSemana);
	//MuestroTiempos(diaSemana, diasSemana);
	return 0;
}
