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
	int getCodigo() {
		return codigo;
	}
	string getNombre() {
		return nombre;
	}
	int getCantEstudiantes() {
		return cant_estudiantes;
	}
	string getCarrera() {
		return carrera;
	}
	string getProfesor() {
		return profesor;
	}
	Nodo* getSiguiente() {
		return siguiente;
	}
	void setAlumnosInscritos(Nodo* Alumno) {
		this->alumnosInscritos = alumnosInscritos;	
	}
	void setSiguiente(Nodo* siguiente) {
		this->siguiente = siguiente;
	}

}