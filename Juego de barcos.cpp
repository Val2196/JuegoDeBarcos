#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;
const int columna = 10;
const int renglon = 6;
int matriz[renglon][columna];
int matrizIA[renglon][columna];
int matrizIA_temporal[renglon][columna];

void Tablero_Usuario() {
	for (int i = 0; i < renglon; i++) {
		for (int j = 0; j < columna; j++) {
			matriz[i][j]=0;
		}
	}
}
void TableroIA() {
	for (int i = 0; i < renglon; i++) {
		for (int j = 0; j < columna; j++) {
			matrizIA[i][j] = 0;
		}
	}
}
void Barco1_IA(int vertical_horizontal1) {
	int contador = 0;
	while (contador < 1) {
		srand(time(NULL));
		int coordenada_x = rand() % 6;
		int coordenada_y = rand() % 10;
		
		if (vertical_horizontal1 == 0) {
			if (coordenada_y <= 4) {
				for (int i = coordenada_y; i < coordenada_y + 6; i++) {
					matrizIA[coordenada_x][i] = 1;
				}
				contador++;
			}
		}
		if (vertical_horizontal1 == 1) {
			if (coordenada_x == 0) {
				for (int i = coordenada_x; i < coordenada_x + 6; i++) {
					matrizIA[i][coordenada_y] = 1;
				}
				contador++;
			}
		}
	}	
}
vector<int> CoordenadaBarco1_IA(){
	vector<int>coordenadaBarco1;
	int xi = 0, yi = 0, xf = 0, yf = 0,cont = 0;
	for (int i = 0; i < renglon; i++) {
		for (int j = 0; j < columna; j++) {
			if (matrizIA[i][j] == 1) {
				cont++;
				if (cont == 1) {
					int xi = i;
					int yi = j;
					coordenadaBarco1.push_back(i);
					coordenadaBarco1.push_back(j);
				}
				if (cont == 6) {
					int xf = i;
					int yf = j;
					coordenadaBarco1.push_back(i);
					coordenadaBarco1.push_back(j);
				}
			}
		}
	}
	
	return coordenadaBarco1;
}
void Barco2_IA(int vertical_horizontal1,int vertical_horizontal2,vector<int>barco1) {
	int contador = 0;
	while (contador < 1) {
		srand(time(NULL));
		int coordenada_x = rand() % 6;
		int coordenada_y = rand() % 10;
		
		if (vertical_horizontal1 == 0) {
			if (vertical_horizontal2 == 0) {
				if ((coordenada_x<barco1[0] || coordenada_x>barco1[2]) && coordenada_y <= 7) {
					for (int i = coordenada_y; i < coordenada_y + 3; i++) {
						matrizIA[coordenada_x][i] = 2;
					}
					contador++;
				}			
			}
			if (vertical_horizontal2 == 1) {
				if ((coordenada_y<barco1[1] || coordenada_y>barco1[3]) && coordenada_x <= 3) {
					for (int i = coordenada_x; i < coordenada_x + 3; i++) {
						matrizIA[i][coordenada_y] = 2;
					}
					contador++;
				}
			}	
		}
		if (vertical_horizontal1 == 1) {
			if (vertical_horizontal2 == 1) {
				if ((coordenada_y<barco1[1] || coordenada_y>barco1[3]) && coordenada_x <= 3) {
					for (int i = coordenada_x; i < coordenada_x + 3; i++) {
						matrizIA[i][coordenada_y] = 2;
					}
					contador++;
				}
			}
			if (vertical_horizontal2 == 0) {
				if ((coordenada_x<barco1[0] || coordenada_x>barco1[2]) && coordenada_y <= 7) {
					for (int i = coordenada_y; i < coordenada_y + 3; i++) {
						matrizIA[coordenada_x][i] = 2;
					}
					contador++;
				}
			}
		}
	}
}
vector<int> CoordenadaBarco2_IA() {
	vector<int>coordenadaBarco2;
	int xi = 0, yi = 0, xf = 0, yf = 0, cont = 0;
	for (int i = 0; i < renglon; i++) {
		for (int j = 0; j < columna; j++) {
			if (matrizIA[i][j] == 2) {
				cont++;
				if (cont == 1) {
					int xi = i;
					int yi = j;
					coordenadaBarco2.push_back(i);
					coordenadaBarco2.push_back(j);
				}
				if (cont == 3) {
					int xf = i;
					int yf = j;
					coordenadaBarco2.push_back(i);
					coordenadaBarco2.push_back(j);
				}
			}
		}
	}
	return coordenadaBarco2;
}
void Barco3_IA(int vertical_horizontal1, int vertical_horizontal2, int vertical_horizontal3, vector<int>barco1, vector<int>barco2) {
	int contador = 0;
	while (contador < 1) {
		srand(time(NULL));
		int coordenada_x = rand() % 6;
		int coordenada_y = rand() % 10;
		if (vertical_horizontal3 == 0) {
			if (coordenada_y <= 6 && (matrizIA[coordenada_x][coordenada_y] == 0 && matrizIA[coordenada_x][coordenada_y + 1] == 0 && matrizIA[coordenada_x][coordenada_y + 2] == 0 && matrizIA[coordenada_x][coordenada_y + 3] == 0)) {
				for (int i = coordenada_y; i < coordenada_y + 4; i++) {
					matrizIA[coordenada_x][i] = 3;
				}
				contador++;
			}
		}
		if (vertical_horizontal3 == 1) {
			if (coordenada_x <= 2 && (matrizIA[coordenada_x][coordenada_y] == 0 && matrizIA[coordenada_x + 1][coordenada_y] == 0 && matrizIA[coordenada_x + 2][coordenada_y] == 0 && matrizIA[coordenada_x + 3][coordenada_y] == 0)) {
				for (int i = coordenada_x; i < coordenada_x + 4; i++) {
					matrizIA[i][coordenada_y] = 3;
				}
				contador++;
			}
		}
	}
}
void Barco1_Usuario() {
	int vertical_horizontal;
	int coordenada_x, coordenada_y;
	int contador = 0;

	while (contador < 1) {
		cout << "En cual coordenada quieres poner el barco #1 Y(0,9) & X(0,5)" << endl;
		cout << "Coordenada X:";
		cin >> coordenada_x;
		cout << endl;
		cout << "Coordenada Y:";
		cin >> coordenada_y;
		cout << endl;
		cout << "En que posicion lo quieres [1]Vertical o [0]Horizontal:";
		cin >> vertical_horizontal;
		if (vertical_horizontal == 0) {
			if (coordenada_y <= 4) {
				for (int i = coordenada_y; i < coordenada_y + 6; i++) {
					matriz[coordenada_x][i] = 1;
				}
				contador++;
			}
			else if (coordenada_y > 4) {
				cout << "Opcion no dispobible, intente de nuevo" << endl;
			}
		}
		if (vertical_horizontal == 1) {
			if (coordenada_x == 0) {
				for (int i = coordenada_x; i < coordenada_x + 6; i++) {
					matriz[i][coordenada_y] = 1;
				}
				contador++;
			}
			else {
				cout << "Opcion no dispobible, intente de nuevo" << endl;
			}
		}
	}

}
void Barco2_Usuario() {
	int vertical_horizontal;
	int coordenada_x, coordenada_y;
	int contador=0;
	while (contador < 1) {
		cout << "En cual coordenada quieres poner el barco #2 Y(0,9) & X(0,5)" << endl;
		cout << "Coordenada X:";
		cin >> coordenada_x;
		cout << endl;
		cout << "Coordenada Y:";
		cin >> coordenada_y;
		cout << endl;
		cout << "En que posicion lo quieres [1]Vertical o [0]Horizontal:";
		cin >> vertical_horizontal;

		if (vertical_horizontal == 0) {
			if (coordenada_x <= 3 && (matriz[coordenada_x][coordenada_y] == 0 && matriz[coordenada_x][coordenada_y + 1] == 0 && matriz[coordenada_x][coordenada_y + 2] == 0)) {
				for (int i = coordenada_y; i < coordenada_y + 3; i++) {
					matriz[coordenada_x][i] = 2;
				}
				contador++;
			}
			else {
				cout << "Opcion no valida, intente de nuevo" << endl;
			}
		}
		if (vertical_horizontal == 1) {
			if (coordenada_y <= 7 && (matriz[coordenada_x][coordenada_y] == 0 && matriz[coordenada_x + 1][coordenada_y] == 0 && matriz[coordenada_x + 2][coordenada_y] == 0)){
				for (int i = coordenada_x; i < coordenada_x + 3; i++) {
					matriz[i][coordenada_y] = 2;
				}
				contador++;
			}
		}
	}
}
void Barco3_Usuario() {
	int vertical_horizontal;
	int coordenada_x, coordenada_y;
	int contador = 0;
	while (contador < 1) {
		cout << "En cual coordenada quieres poner el barco #3 Y(0,9) & X(0,5)" << endl;
		cout << "Coordenada X:";
		cin >> coordenada_x;
		cout << endl;
		cout << "Coordenada Y:";
		cin >> coordenada_y;
		cout << endl;
		cout << "En que posicion lo quieres [1]Vertical o [0]Horizontal:";
		cin >> vertical_horizontal;

		if (vertical_horizontal == 0) {
			if (coordenada_y <= 6 && (matriz[coordenada_x][coordenada_y] == 0 && matriz[coordenada_x][coordenada_y + 1] == 0 && matriz[coordenada_x][coordenada_y + 2] == 0 && matriz[coordenada_x][coordenada_y + 3] == 0)) {
				for (int i = coordenada_y; i < coordenada_y + 4; i++) {
					matriz[coordenada_x][i] = 3;
				}
				contador++;
			}
			else {
				cout << "Opcion no valida, intente de nuevo" << endl;
			}
		}
		if (vertical_horizontal == 1) {
			if (coordenada_x <= 2 && (matriz[coordenada_x][coordenada_y] == 0 && matriz[coordenada_x + 1][coordenada_y] == 0 && matriz[coordenada_x + 2][coordenada_y] == 0 && matriz[coordenada_x + 3][coordenada_y] == 0)) {
				for (int i = coordenada_x; i < coordenada_x + 4; i++) {
					matriz[i][coordenada_y] = 3;
				}
				contador++;
			}
			else {
				cout << "Opcion no valida, intente de nuevo" << endl;
			}
		}
	}
	
}
void Usuario_Ataca() {
	int coordenada_x, coordenada_y;
	int contador = 0;
	cout << "Turno del usuario" << endl;
	cout << "Dame la coordenada que quieres atacar Y(0,9) & X(0,5)" << endl;
	cout << "Coordenada X:";
	cin >> coordenada_x;
	cout << "Coordenada Y:";
	cin >> coordenada_y;
	
	while (contador < 1) {
		
		if (matrizIA[coordenada_x][coordenada_y] == 0) {
			cout << "Jugador falla";
			contador++;
		}
		else if (matrizIA[coordenada_x][coordenada_y] == 9) {
			cout << "Ya habias dado en ese objetivo, vuelve a tirar" << endl;
			cout << "Dame la coordenada que quieres atacar Y(0,9) & X(0,5)" << endl;
			cout << "Coordenada X:";
			cin >> coordenada_x;
			cout << "Coordenada Y:";
			cin >> coordenada_y;
		}
		else if (matrizIA[coordenada_x][coordenada_y] == 1 || matrizIA[coordenada_x][coordenada_y] == 2 || matrizIA[coordenada_x][coordenada_y] == 3) {
			int contadortiro = 1;

			while (contadortiro != 0) {
				cout << "Has acertado el tiro" << endl;
				matrizIA[coordenada_x][coordenada_y] = 9;
				cout << "Vuelve a tirar" << endl;
				cout << "Coordenada X:";
				cin >> coordenada_x;
				cout << "Coordenada Y:";
				cin >> coordenada_y;
				if (matrizIA[coordenada_x][coordenada_y] == 0) {
					cout << "Jugador falla";
					contadortiro = 0;
				}
			}
			contador++;
		}
	}
}
void IA_Ataca() {
	cout << "Turno de la IA" << endl;
	int contador = 0;
	srand(time(NULL));
	int coordenada_x = rand() % 6;
	int coordenada_y = rand() % 10;
	cout << coordenada_x << coordenada_y;
	if (matriz[coordenada_x][coordenada_y] == 1 || matriz[coordenada_x][coordenada_y] == 2 || matriz[coordenada_x][coordenada_y] == 3) {
		
		int contadortiro = 1;
		while (contadortiro != 0) {
			if (matriz[coordenada_x][coordenada_y] == 1 || matriz[coordenada_x][coordenada_y] == 2 || matriz[coordenada_x][coordenada_y] == 3) {
				cout << "IA acerto el tiro" << endl;
				matriz[coordenada_x][coordenada_y] = 9;
				cout << "Vuelve a tirar IA" << endl;
				cout << coordenada_x << coordenada_y;
			}

			if (matrizIA[coordenada_x][coordenada_y] == 0) {
				cout << "IA falla" << endl;
				contadortiro = 0;
			}
			/*srand(time(NULL));*/
			coordenada_x = rand() % 6;
			coordenada_y = rand() % 10;
		}
		contador++;
	}
	else {
		cout << "IA falla";
	}
	
}
void Mostrar_Usuario() {
	for (int i = 0; i < renglon; i++) {
		for (int j = 0; j < columna; j++) {
			cout << matriz[i][j]<<" ";
		}
		cout << endl;
	}
}
void MostrarIA() {
	for (int i = 0; i < renglon; i++) {
		for (int j = 0; j < columna; j++) {
			cout << matrizIA[i][j] << " ";
		}
		cout << endl;
	}
}
int ContadorIA_x(int contadorXIA) {
	int contadorUsuario_x = 0;
	for (int i = 0; i < renglon; i++) {
		for (int j = 0; j < columna; j++) {
			if (matrizIA[i][j] == 9) {
				contadorUsuario_x++;
			}
		}
	}
	return contadorUsuario_x;
}
int ContadorUsuario_x(int contadorX) {
	int contadorIA_x = 0;
	for (int i = 0; i < renglon; i++) {
		for (int j = 0; j < columna; j++) {
			if (matriz[i][j] == 9) {
				contadorIA_x++;
			}
		}
	}
	return contadorIA_x;
}
int main() {
	srand(time(NULL));
	int vertical_horizontal1 = rand() % 2;
	int vertical_horizontal2 = rand() % 2;
	int vertical_horizontal3 = rand() % 2;
	cout << "Bienvenido a Juego de barcos" << endl;
	
	//GENERACION DE BARCOS IA
	TableroIA();
	Barco1_IA(vertical_horizontal1);
	vector<int>barco1 =CoordenadaBarco1_IA();
	Barco2_IA(vertical_horizontal1, vertical_horizontal2,barco1);
	vector<int>barco2 = CoordenadaBarco2_IA();
	Barco3_IA(vertical_horizontal1,vertical_horizontal2, vertical_horizontal3,barco1,barco2);
	cout << "Tablero IA" << endl;
	MostrarIA();
	cout << endl;
	
	/*GENERACION DE BARCOS USUARIO*/
	cout << "Genere su tablero con los barcos correspondientes:" << endl;
	cout << "Barco 1: 6 bloques" << endl;
	cout << "Barco 2: 3 bloques" << endl;
	cout << "Barco 3: 4 bloques" << endl << endl;
	cout << "Tablero Usuario" << endl;
	Tablero_Usuario();
	Mostrar_Usuario();
	Barco1_Usuario();
	Mostrar_Usuario();
	Barco2_Usuario();
	Mostrar_Usuario();
	Barco3_Usuario();
	Mostrar_Usuario();

	//JUEGO AUTOMATIZADO
	int opcion, contadorIA = 0, contadorUsuario = 0;
	int contadorXIA = 0, contadorXUsuario = 0;
	int fin = 0;
	int contadorTurno=0;
	int turno = 0;
	while (fin < 1) {
		
		if (contadorTurno == 0) {
			srand(time(NULL));
			turno = rand() % 2;
			contadorTurno=1;
		}
		if (turno == 0) {
			Usuario_Ataca();
			cout << endl;
			MostrarIA();
			cout << endl;
			contadorIA = ContadorIA_x(contadorXIA);
			cout << "contador Usuario:" << contadorIA << endl;
			
			if (contadorIA == 13) {
				fin = 1;
				break;
			}

			IA_Ataca();
			cout << endl;
			contadorUsuario = ContadorUsuario_x(contadorXUsuario);
			cout << "contador IA:" << contadorUsuario << endl;
			Mostrar_Usuario();
			
			if (contadorUsuario == 13) {
				fin = 1;
				break;
			}
		}
		if (turno == 1) {
			IA_Ataca();
			cout << endl;
			contadorUsuario = ContadorUsuario_x(contadorXUsuario);
			cout << "contador IA:" << contadorUsuario << endl;
			Mostrar_Usuario();

			if (contadorUsuario == 13) {
				fin = 1;
				break;
			}

			Usuario_Ataca();
			cout << endl;
			MostrarIA();
			cout << endl;
			contadorIA = ContadorIA_x(contadorXIA);
			cout << "contador Usuario:" << contadorIA << endl;
			
			if (contadorIA == 13) {
				fin = 1;
				break;
			}
		}
	}
	//GANADOR & PERDEDOR
	if (contadorIA > contadorUsuario) {
		cout << "Felicidades, Ganaste";
	}
	else {
		cout << "Gano la IA,Perdiste";
	}

	return 0;
}