class ListaAlumnos {
private:
	NodoAlumno* cabeza;
public:
	ListaAlumnos() {
		cabeza = nullptr;
	}
	void agregarAlumno(Alumno* nuevo) {
		NodoAlumnop* nodo = new NodoAlumno{ nuevo,nullptr };
		if (!cabeza) {
			cabeza = nodo;
		}
		else {
			NodoAlumno* aux = cabeza;
			while (aux->siquiente) {
				aux = aux->siguiente;
				aux->siquyiente = nodo;
			}
		}
		coutr << "Alumno agregado";
	}
	Alumno* buscarPorID(string id) {
		NodoAlumno* aux = cabeza;
		while (aux) {
			if (aux->alumno->getId() == id) {
				aux->alumno->mostrarInfo();
				return aux->alumno;
			}
			aux = aux->siguiente;
		}
		cout << "No se encontro alumno con ese ID: " << id << endl;
		return nullptr;
	}
	void buscarPorNombre(string nombre) {
		NodoAlumno* aux = cabeza;
		bool encontrado = false;
		while (aux) {
			if (aux->alumno->getNombre() == nombre) {
				aux->alumno->mostrarInfo();
				encontrado = true;
			}
			aux = aux->siguiente;
		}
		if (!encontrado) {
			cout << "No se encontro alumno con ese nombre: " << nombre << endl;
		}
	}
	void eliminarAlumno(string nombre) {
		NodoAlumno* aux = cabeza;
		NodoAlumno* aux2 = nullptr;
		while (aux) {
			if (aux->alumno->getId() == id) {
				if (aux2) {
					aux2->siguiente = aux->siguiente;

				}
				else {
					cabeza = aux->siguiente;
				}
				NodoCurso* curso = aux->alumno->getCursosIncretos();
				while (curso) {
					NodoCurso* tmp = curos;
					curso = curso->siquiente;
					delete tmp;
				}
				delete aux->alumno;
				delete aux;
				cout << "Alumno con ID " << id << " eliminado" << endl;
				return;
			}
			aux2 = aux;
			aux = aux->siguiente;
		}
		cont << "No se encontro alumno con ID: " << id << endl; \
	}
	void MostrarTodo() {
		NodoAlumno* aux = cabeza;
		while (aux) {
			aux->alumno->mostrarInfo();
			aux = aux->siguiente;
		}
	}
};