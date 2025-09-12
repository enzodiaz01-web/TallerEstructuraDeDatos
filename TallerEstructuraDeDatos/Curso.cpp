class NodoCurso;
class NodoAlumno;
#include <iostream>
#include <string>
using namespace std;
class Curso {
private:
	int codigo;
	string nombre;
	int cantEstudiantes;
	string carrera;
	string profesor;
	NodoCurso* siguiente;
	NodoAlumno* alumnosInscritos;
public:
	Curso(int codigo, string nombre, int cantEstudiantes, string carrera, string profesor) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->cantEstudiantes = cantEstudiantes;
		this->carrera = carrera;
		this->profesor = profesor;
		this->alumnosInscritos = nullptr;
		this->siguiente = nullptr;
	}
	Curso* buscarPorID(string id) {
		NodoCurso* aux = cabeza;
		while (aux) {
			if (aux->curso->getId() == id) {
				aux->curso->mostrarInfo();
				return aux->alumno;
			}
			aux = aux->siguiente;
		}
		cout << "No se encontro curso con el ID: " << id << endl;
		return nullptr;
	}
	void buscarPorNombre(string nombre) {
		NodoCurso* aux = cabeza;
		bool encontrado = false;
		while (aux) {
			if (aux->curso->getNombre() == nombre) {
				aux->curso->mostrarInfo();
				encontrado = true;
			}
			aux = aux->siguiente;
		}
		if (!encontrado) {
			cout << "No se encontro curso con el nombre: " << nombre << endl;
		}
	}

	int getCodigo() {
		return codigo;
	}
	string getNombre() {
		return nombre;
	}
	int getCantEstudiantes() {
		return cantEstudiantes;
	}
	string getCarrera() {
		return carrera;
	}
	string getProfesor() {
		return profesor;
	}
	NodoCurso* getSiguiente() {
		return siguiente;
	}
	NodoAlumno* getAlumnosInscritos() {
		return alumnosInscritos;
	}
	void setAlumnosInscritos(Nodo* Alumno) {
		this->alumnosInscritos = alumnosInscritos;	
	}
	void setSiguiente(Nodo* siguiente) {
		this->siguiente = siguiente;
	}
	void mostrarInfo() {
		cout << "ID: " << id << " Nombre: " << nombre << "Cant. Estudiantes: " << cantEstudiantes << " Carrera: " << carrera << "Profesor: " << profesor << endl;
	}

}