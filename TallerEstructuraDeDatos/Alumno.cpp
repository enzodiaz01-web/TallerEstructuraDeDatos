class NodoAlumno;
class NodoCurso;
#include <iostream>
#include <string>
using namespace std;

class Alumno {
private:
	    string id;
		string nombre;
		string apellido;
		string carrera;
		string fecha;
		NodoCurso* cursosIncretos;
		NodoAlumno* siguiente;
public:
	Alumno(string id, string nombre, string apellido, string carrera, string fecha) {
			this->id = id;
			this->nombre = nombre;
			this->apellido = apellido;
			this->carrera = carrera;
			this->fecha = fecha;
			this->cursosIncretos = nullptr;
			this->siguiente = nullptr;
		}
		string getId() {
			return id;
		}
		string getNombre() {
			return nombre;
		}
		string getApellido() {
			return apellido;
		}
		string getCarrera() {
			return carrera;
		}
		string getFecha() {
			return fecha;
		}
		NodoCurso* getCursosIncretos() {
			return cursosIncretos;
		}
		NodoAlumno* getSiguiente() {
			return siguiente;
		}
		void setCursosIncretos(NodoCurso* cursosIncretos) {
			this->cursosIncretos = cursosIncretos;
		}
		void setSiguiente(NodoAlumno* siguiente) {
			this->siguiente = siguiente;
		}

};