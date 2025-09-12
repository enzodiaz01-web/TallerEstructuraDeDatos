#include <iostream>
#include <string>
#include ListaAlumnos.cpp
#include Curso.cpp
#include Alumno.cpp

using namespace std;
class Alumno;
class Curso;
class ListaAlumnos;
ListaAlumnos listaAlumnos;
Curso curso;
Alumno alumno;

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
void menuAlumnos() {
	int opcion = 0;
	while (opcion != 5) {
		cout << "\n--- Manejo de Alumnos ---" << endl;
		cout << "1. Agregar Alumno" << endl;
		cout << "2. Buscar Alumno por ID" << endl;
		cout << "3. Buscar Alumno por Nombre" << endl;
		cout << "4. Eliminar Alumno" << endl;
		cout << "5. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			string ID;
			string nombre;
			string apellido;
			string carrera;
			string fecha
			cout << "Ingrese el ID: ";
			getline(cin, ID);
			if (!listaAlumnos.existe()) {
				cout << "Ingrese el nombre: ";
				getline(cin, nombre);
				cout << "Ingrese el apellido: ";
				getline(cin, apellido);
				cout << "Ingrese la carrera: ";
				getline(cin, carrera);
				cout << "Ingrese la fecha actual: ";
				getline(cin, fecha);
				Alumno p(ID, nombre, apellido, carrera, fecha);
				cout << "Alumno creado con exito: " << endl;
				p->mostrarInfo;
			}
			else {
				cout << "El ID ya existe, intente de nuevo." << endl;
			}
			break;
		case 2:
			string texto;
			cout << "Ingrese el ID a buscar: " << endl;
			cin >> texto;
			listaAlumnos.buscarPorID(texto);
			break;
		case 3:
			string texto;
			cout << "Ingrese el nombre a buscar: " << endl;
			cin >> texto;
			listaAlumnos.buscarporNombre(texto);
			break;
		case 4:
			string texto;
			cout << "Ingrese el ID a eliminar: " << endl;
			cin >> texto;
			listaAlumnos.eliminar(texto);
			break;
		case 5:
			cout << "Volviendo al menu principal..." << endl;
			break;
		default:
			cout << "Opcion invalida, intente de nuevo." << endl;
		}
	}
}

void menuInscripcion() {
	int opcion = 0;
	while (opcion != 4) {
		cout << "\n--- Manejo de Inscripciones ---" << endl;
		cout << "1. Inscribir Alumno a Curso" << endl;
		cout << "2. Eliminar Inscripcion de Alumno a Curso" << endl;
		cout << "3. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			string idAlumno;
			int codigoCurso;
			cout << "Ingrese el ID del alumno: ";
			cin >> idAlumno;
			cout << "Ingrese el codigo del curso: ";
			cin >> codigoCurso;
			alumno = listaAlumnos.buscarPorID(idAlumno);
			if (alumno) {
				curso = buscarCursoPorCodigo(codigoCurso); // Suponiendo que existe una funcion para buscar curso por codigo
				if (curso) {
					alumno->inscribirCurso(curso);
					cout << "Alumno inscrito al curso con exito." << endl;
				}
				else {
					cout << "Curso no encontrado." << endl;
				}
			}
			else {
				cout << "Alumno no encontrado." << endl;
			}
			break;
		case 2:
			string idAlumno;
			int codigoCurso;
			cout << "Ingrese el ID del alumno: ";
			cin >> idAlumno;
			cout << "Ingrese el codigo del curso: ";
			cin >> codigoCurso;
			alumno = listaAlumnos.buscarPorID(idAlumno);
			if (alumno) {
				alumno->eliminarInscripcion(codigoCurso);
			}
			else {
				cout << "Alumno no encontrado." << endl;
			}
			break;
		case 3:
			cout << "Volviendo al menu principal..." << endl;
			break;
		default:
			cout << "Opcion invalida, intente de nuevo." << endl;
		}
	}
}

void menuNotas() {
	int opcion = 0;
	while (opcion != 4) {
		cout << "\n--- Manejo de Notas ---" << endl;
		cout << "1. Registrar Nota" << endl;
		cout << "2. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			string idAlumno;
			int codigoCurso;
			float nota;
			cout << "Ingrese el ID del alumno: ";
			cin >> idAlumno;
			cout << "Ingrese el codigo del curso: ";
			cin >> codigoCurso;
			cout << "Ingrese la nota (1.0 - 7.0): ";
			cin >> nota;
			alumno = listaAlumnos.buscarPorID(idAlumno);
			if (alumno) {
				alumno->registrarNotas(codigoCurso, nota);
			}
			else {
				cout << "Alumno no encontrado." << endl;
			}
			break;
		case 2:
			cout << "Volviendo al menu principal..." << endl;
			break;
		default:
			cout << "Opcion invalida, intente de nuevo." << endl;
		}
	}
}

void menuReportes(){
	int opcion = 0;
	while (opcion != 4) {
		cout << "\n--- Consultas y Reportes ---" << endl;
		cout << "1. Obtener Alumnos por Carrera" << endl;
		cout << "2. Mostrar Cursos de un Alumno" << endl;
		cout << "3. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			string carrera;
			cout << "Ingrese la carrera: ";
			cin >> carrera;
			listaAlumnos.obtenerAlumnosPorCarrera(carrera);
			break;
		case 2:
			string idAlumno;
			cout << "Ingrese el ID del alumno: ";
			cin >> idAlumno;
			listaAlumnos.mostrarCursosDelAlumno(idAlumno);
			break;
		case 3:
			cout << "Volviendo al menu principal..." << endl;
			break;
		default:
			cout << "Opcion invalida, intente de nuevo." << endl;
		}
	}
}

void menu() {
	int opcion = 0;
	while (opcion != 6) {
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
				menuAlumnos();
				break;
			case 2:
				//llamar a manejo de cursos
				break;
			case 3:
				menuInscripcion();
				break;
			case 4:
				menuNotas();
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