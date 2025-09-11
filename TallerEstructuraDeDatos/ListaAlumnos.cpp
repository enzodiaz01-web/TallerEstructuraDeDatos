class ListaAlumnos {
private:
	NodoAlumno* cabeza;
public:
	ListaAlumnos() {
		cabeza = nullptr;
	}
	void agregarAlumno(Alumno* nuevo) {
		NodoAlumno* nodo = new NodoAlumno(nuevo);
		if (!cabeza) {
			cabeza = nodo;
		}
		else {
			NodoAlumno* aux = cabeza;
			while (aux->siguiente) {
				aux = aux->siguiente;
			}
			aux->siguiente = nodo;
		}
		cout << "Alumno agregado";
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

				}else {
					cabeza = aux->siguiente;
				}
				NodoCurso* curso = aux->alumno->getCursosInscritos();
				while (curso) {
					NodoCurso* tmp = curso;
					curso = curso->siguiente;
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
		cont << "No se encontro alumno con ID: " << id << endl; 
	}
	void MostrarTodo() {
		NodoAlumno* aux = cabeza;
		while (aux) {
			aux->alumno->mostrarInfo();
			aux = aux->siguiente;
		}
	}
	//Seccion de Consultas y reportes 
	// 1. Obtener todos los alumnos de una carrera
	void obtenerAlumnosPorCarrera(dtring carrera) {
		NodoAlumno* aux = cabeza;
		bool encontrado = false;
		cout << "Alumnos de la carrera " << carrera << ":" << endl;
		while (aux) {
			if (aux->alumno->getCarrera() == carrera) {
				aux->alumno->mostrarInfo();
				encontrado = true;
			}
			aux = aux->siguiente;	

		}
		if(!encontrado) {
			cout << "No se encontraron alumnos en la carrera: " << carrera << endl;
		}
	}
	// 2. Obtener todos los cursos en los que un alumno está inscrito
	void mostrarCursosDelAlumno(string id) {
		Alumno* alumno = buscarPorID(id);
		if(!alumno){
			return;
		}
		NodoCurso* curso = alumno->getCursosInscritos();
		if(!curso){
			cout << "El alumno no esta inscrito en ningun curso." << endl;
			return;
		}
		cout << "Cursos en los que esta inscrito el alumno " << alumno->getNombre() << ":" << endl;
		while (curso) {
			cout << curso->curso->getNombre() << " (Codigo: " << curso->curso->getCodigo() << ")" << endl;
			curso = curso->siguiente;
		}
	}
	// 3. Calcular el promedio de notas de un alumno en un curso
	// 
	// 4. Calcular el promedio general de un alumno
};