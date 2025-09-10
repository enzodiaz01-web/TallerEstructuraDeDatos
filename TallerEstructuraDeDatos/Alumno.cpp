class NodoAlumno;
class NodoCurso;
class NodoNota;

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
			this->cursosIncritos = cursosIncretos;
		}
		void setSiguiente(NodoAlumno* siguiente) {
			this->siguiente = siguiente;
		}
		void mostrarInfo() {
			cout << "ID: " << id << " Nombre: " << nombre << " " << apellido << " Carrera: " << carrera << "Fecha ingreso" << fecha << endl;
		}
		void inscribirCurso(Curso* curso) {
			NodoCurso* nuevo = new NodoCurso{ curso, nullptr };
			nuevo->siguiente = cursosInscritos;
			cursosInscritos = nuevo;
		}
		void eliminarInscripcion(int codigoCurso) {
			NodoCurso* aux = cursosInscritos;
			NodoCurso* aux2 = nullptr;
			while (aux) {
				if (aux->curso->getCodigo() == codigoCurso) {
					if (aux2) {
						aux2->siguiente = aux->siguiente;
					}
					else {
						cursosInscritos = aux->siguiente;
					}
					delete aux;
					cout << "Inscripcion al curso con codigo " << codigoCurso << " eliminada." << endl;
					return;
				}
				aux2 = aux;
				aux = aux->siguiente;
			}
			cout << "El alumno no esta inscrito en el curso con codigo: " << codigoCurso << endl;
		}
		void registrarNotas(int codigoCurso, float nota) {
			if (nota < 1.0 || nota>7.0) {
				cout << "Nota invalida, debe estar entre 1.0 y 7.0" << endl;
				return;
			}
			NodoCurso* aux = cursosInscritos;
			while (aux) {
				if (aux->curso->getCodigo() == codigoCurso) {
					NodoNota* nueva = new NodoNota{ nota, nullptr };
					if (!aux->notas) {
						aux->notas = nueva;
					}
					else {
						NodoNota* aux2 = aux->notas;
						while (aux2->siguiente) {
							aux2 = aux2->siguiente;
						}
						aux2->siguiente = nueva;
					}
					aux->curso->agregarNota(nota);
					cout << "Nota " << nota << "registrada en curso " << aux->curso->getNombre() << endl;
					return;
				}
				aux = aux->siguiente;
			}
			cout << "El alumno no esta inscrito en el curso con codigo: " << codigoCurso << endl;
		}
		void mostrarNotas(int codigoCurso) {
			NodoCurso* aux = cursosInscritos;
			while (aux) {
				if (aux->curso->getCodigo() == codigoCurso) {
					cout << "Notas del curso " << aux->curso->getNombre() << ":" << endl;
					NodoNota* aux2 = aux->notas;
					while (aux2) {
						cout << aux2->nota << " ";
						aux2 = aux2->siguiente;
					}
					cout << endl;
					return;
				}
				aux = aux->siguiente;
			}
			cout << "El alumno no esta inscrito en el curso con codigo: " << codigoCurso << endl;
		}
};