// lo que devuelves/operador(extremo1, extremo2) de la operacion

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_FILAS = 4;
const int MAX_COLUMNAS = 4;

typedef double tMatrizDatos[MAX_FILAS][MAX_COLUMNAS];

typedef struct tMatriz {
	int nFils, nCols;
	tMatrizDatos mat;
};


bool leer(string nomFichero, tMatriz& matriz);
double calcularDiagonal(tMatriz& matriz);
bool comprobarFila(tMatriz& matriz, int fil, const double numMag);
bool comprobarColumna(tMatriz& matriz, int col, const double numMag);
bool sumabienF(tMatriz& matriz, int fil, const double numMag);
bool sumabienC(tMatriz& matriz, int col, const double numMag);
bool comprobarMatrizMag(tMatriz& matriz, int fil, int col, const double numMag);



int main() {
	tMatriz matriz;
	double constante;
	leer("matriz.txt", matriz);
	 constante = calcularDiagonal(matriz);
	 if ((matriz.nFils = matriz.nCols) && comprobarMatrizMag(matriz, matriz.nFils, matriz.nCols, constante)) {
		 cout << " EL CUADRADO ES UN CUADRADO MAGICO" << endl;
	 }
	 else {
		 cout << " EL CUADRADO NOOOOOO ES UN CUADRADO MAGICO" << endl;

	 }

	return 0;
}

bool leer(string nomFichero, tMatriz& matriz) {
	ifstream archivo;
	bool abierto;
	archivo.open(nomFichero);
	abierto = archivo.is_open();
	if (abierto) {
		archivo >> matriz.nFils >> matriz.nCols;
		for (int i = 0; i < matriz.nFils; i++) {
			for (int j = 0; j < matriz.nCols; j++) {
				archivo >> matriz.mat[i][j];
			}
		}
		archivo.close();
	}
	else
		cout << " NO SE HA PODIDO ABRIR EL ARCHIVO " << endl;

	return abierto;
}


double calcularDiagonal(tMatriz& matriz) {
	double constante = 0;
	for (int i = 0; i < matriz.nFils; i++) {
			constante = constante + matriz.mat[i][i];
	}
	return constante;
}


bool comprobarFila(tMatriz& matriz, int fil, const double numMag) {
	double constante = 0;
	bool filaBien;
	int j = 0;

	while ((constante < numMag) && (j < matriz.nFils)) {
		constante = constante + matriz.mat[fil][j];
		j++;
	}
	if (constante == numMag) {
		filaBien = true;
	}

	else {
		filaBien = false;
	}
	return filaBien;
}


bool comprobarColumna(tMatriz& matriz, int col, const double numMag) {
	double constante = 0;
	bool columnaBien;
	int i = 0;

	while ((constante < numMag) && (i < matriz.nCols)) {
		constante = constante + matriz.mat[i][col];
		i++;
	}
	if (constante == numMag) {
		columnaBien = true;
	}

	else {
		columnaBien = false;
	}
	return columnaBien;
}

bool sumabienF(tMatriz& matriz, int fil, const double numMag) {
	int fila = 0;
	bool seguir = true;
	while ((fila < matriz.nFils) && seguir) {
		if (comprobarFila(matriz, fila, numMag)) {
			seguir = true;
			fila++;
		}
		else {
			seguir = false;
		}
	}
	return seguir;
}

bool sumabienC(tMatriz& matriz, int col, const double numMag) {
	int columna = 0;
	bool seguir = true;
	while (columna < matriz.nCols && seguir) {
		if (comprobarColumna(matriz, columna, numMag)) {
			seguir = true;
			columna++;
		}
		else {
			seguir = false; 
		}
	}
	return seguir;
}


bool comprobarMatrizMag(tMatriz& matriz, int fil, int col, const double numMag) {
	bool magico = false;
	bool filaBien = sumabienF(matriz, fil, numMag);
	bool columnaBien = sumabienC(matriz, col, numMag);
	if (filaBien && columnaBien) {
		magico = true;
	}

	return magico;
}