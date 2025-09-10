#include <iostream>
#include <string>
using namespace std;
class Alumno;
class Curso;
struct NodoAlumno {
	Alumno* alumno;
	NodoAlumno* siguiente;
};
struct NodoCurso {
	Curso* curso;
	NodoNota* notas;
	NodoCurso* siguiente;
};
struct NodoNota {
	float nota;
	NodoNota* siguiente;
};
void menu() {
	int opcion = 0;
	while (opcion != 5) {
		cout << "Menu de opciones:" << endl;
		cout << "1. Manejo de Alumnos" << endl;
		cout << "2. Manejo de Cursos" << endl;
		cout << "3. Manejo de Inscripciones" << endl;
		cout << "4. Manejo de Notas" << endl;
		cout << "5. Consultas y Reportes" << endl;
		cout << "6. Cerrar programa" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch(opcion) {
			case 1:
				//llamar a manejo de alumnos
				break;
			case 2:
				//llamar a manejo de cursos
				break;
			case 3:
				//llamar a manejo de inscripciones
				break;
			case 4:
				//llamar a manejo de notas
				break;
			case 5:
				//llamar a reportes y calculadora de promedios
				break;
			case 6:
				cout << "Saliendo del programa..." << endl;
				break;
			default:
				cout << "Opcion invalida, intente de nuevo." << endl;
		}
	}
}

int main() {
	menu();
	return 0;
}