#include <iostream>
#include <string>
#include <limits>
using namespace std;	
// declaracion de existencia
class Alumno;
class Curso;
struct NodoCurso;
struct NodoAlumno;
struct NodoNota;
//Nodos 
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
//Clase Curso
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
		return cantEstudiantes;
	}
	string getCarrera() {
		return carrera;
	}
	string getProfesor() {
		return profesor;
	}
	NodoAlumno* getAlumnosInscritos() {
		return alumnosInscritos;
	}
	NodoCurso* getSiguiente() {
		return siguiente;
	}
	void setAlumnosInscritos(NodoAlumno* alumno) {
		this->alumnosInscritos = alumno;
	}
	void setSiguiente(NodoCurso* siguiente) {
		this->siguiente = siguiente;
	}
	void agregarAlumno(Alumno* alumno) {
		NodoAlumno* nuevo = new NodoAlumno{ alumno,nullptr };
		if (!alumnosInscritos) {
			alumnosInscritos = nuevo;	
		}
		else {
			NodoAlumno* aux = alumnosInscritos;
			while (aux->siguiente) {
				aux = aux->siguiente;
			}
		}
	}
	void eliminarAlumno(Alumno* alumno) {
		NodoAlumno* aux = alumnosInscritos;
		NodoAlumno* aux2 = nullptr;
		while(aux) {
			if (aux->alumno == alumno) {
				if (aux2) {
					aux2->siguiente = aux->siguiente;
				}
				else {
					alumnosInscritos = aux->siguiente;
				}
				delete aux;
				return;
			}
			aux2 = aux;
			aux = aux->siguiente;
		}
	}
	void mostrarInfo() {
		cout << "Codigo: " << codigo << " Nombre: " << nombre << " Cantidad de Estudiantes: " << cantEstudiantes << " Carrera: " << carrera << " Profesor: " << profesor << endl;
	}
};
//Clase Alumno
class Alumno {
private:
	string id;
	string nombre;
	string apellido;
	string carrera;
	string fecha;
	NodoCurso* cursosInscritos;
	NodoAlumno* siguiente;
public:
	Alumno(string id, string nombre, string apellido, string carrera, string fecha) {
		this->id = id;
		this->nombre = nombre;
		this->apellido = apellido;
		this->carrera = carrera;
		this->fecha = fecha;
		this->cursosInscritos = nullptr;
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
	NodoCurso* getCursosInscritos() {
		return cursosInscritos;
	}
	NodoAlumno* getSiguiente() {
		return siguiente;
	}
	void setCursosInscritos(NodoCurso* cursosInscritos) {
		this->cursosInscritos = cursosInscritos;
	}
	void setSiguiente(NodoAlumno* siguiente) {
		this->siguiente = siguiente;
	}
	void mostrarInfo() {
		cout << "ID: " << id << " Nombre: " << nombre << " " << apellido << " Carrera: " << carrera << " Fecha ingreso: " << fecha << endl;
	}
//Manejo de Incripcion
	void inscribirCurso(Curso* curso) {
		NodoCurso* nuevo = new NodoCurso{ curso, nullptr, cursosInscritos };
		cursosInscritos = nuevo;
		curso->agregarAlumno(this);
		cout << "Inscripcion al curso " << curso->getNombre() << " realizada con exito." << endl;
	}
	void eliminarInscripcion(int codigoCurso) {
		NodoCurso* aux = cursosInscritos;
		NodoCurso* aux2 = nullptr;
		while (aux) {
			if (aux->curso->getCodigo() == codigoCurso) {
				aux->curso->eliminarAlumno(this);	
				if (aux2) {
					aux2->siguiente = aux->siguiente;
				}
				else {
					cursosInscritos = aux->siguiente;
				}
				NodoNota* nota = aux->notas;	
				while (nota) {
					NodoNota* tmpNota = nota;
					nota = nota->siguiente;
					delete tmpNota;
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
//Manejo de Notas
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
				cout << "Nota " << nota << "registrada en curso " << aux->curso->getNombre() << endl;
				return;
			}
			aux = aux->siguiente;
		}
		cout << "El alumno no esta inscrito en el curso con codigo: " << codigoCurso << endl;
	}
};
//Clase ListaAlumnos
class ListaAlumnos {
private:
	NodoAlumno* cabeza;
public:
	ListaAlumnos() {
		cabeza = nullptr;
	}
	void agregarAlumno(Alumno* nuevo) {
		NodoAlumno* nodo = new NodoAlumno{ nuevo, nullptr };
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
		cout << "Alumno agregado" <<endl;
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
	bool existe(string id) {
		NodoAlumno* aux = cabeza;
		while (aux) {
			if (aux->alumno->getId() == id) {
				return true;
			}
			aux = aux->siguiente;
		}
		return false;
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
	void eliminarAlumno(string id) {
		NodoAlumno* aux = cabeza;
		NodoAlumno* aux2 = nullptr;
		while (aux) {
			if (aux->alumno->getId() == id) {
				NodoCurso* curso = aux->alumno->getCursosInscritos();
				while (curso) {
					NodoCurso* tempCurso = curso;
					curso->curso->eliminarAlumno(aux->alumno); 
					NodoNota* nota = curso->notas;
					while (nota) {
						NodoNota* tempNota = nota;
						nota = nota->siguiente;
						delete tempNota;
					}
					curso = curso->siguiente;
					delete tempCurso;
				}
				if (aux2) { 
					aux2->siguiente = aux->siguiente; 
				}
				else { 
					cabeza = aux->siguiente; 
				}
				delete aux->alumno;
				delete aux;
				cout << "Alumno con ID " << id << " eliminado" << endl;
				return;
			}
			aux2 = aux;
			aux = aux->siguiente;
		}
		cout << "No se encontro alumno con ID: " << id << endl;
	}
	void mostrarTodos() {
		NodoAlumno* aux = cabeza;
		if(!aux) {
			cout << "No hay alumnos registrados." << endl;
			return;
		}
		while (aux) {
			aux->alumno->mostrarInfo();
			aux = aux->siguiente;
		}
	}
//Consultas y Reportes
	void obtenerAlumnosPorCarrera(string carrera) {
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
		if (!encontrado) {
			cout << "No se encontraron alumnos en la carrera: " << carrera << endl;

		}
	}void mostrarCursosDelAlumno(string id) {
		Alumno* alumno = buscarPorID(id);
		if(!alumno) {
			cout << "Alumno no encontrado." << endl;
			return;
		}
		NodoCurso* curso = alumno->getCursosInscritos();	
		if (!curso) {
			cout << "El alumno no esta inscrito en ningun curso." << endl;
			return;
		}	
		cout << "Cursos en los que el alumno esta inscrito:" << endl;	
		while (curso) {
			cout << curso->curso->getNombre() << " (Codigo: " << curso->curso->getCodigo() << ")" << endl;
			curso = curso->siguiente;
		}
	}
	void promedioAlumnoEnCurso(string id, int codigoCurso) {
		Alumno* alumno = buscarPorID(id);
		if (!alumno) {
			cout << "Alumno no encontrado." << endl;
			return;
		}
		NodoCurso* curso = alumno->getCursosInscritos();
		while (curso) {
			if (curso->curso->getCodigo() == codigoCurso) {
				NodoNota* nota = curso->notas;
				if (!nota) {
					cout << "El alumno no tiene notas registradas en este curso." << endl;
					return;
				}
				float suma = 0.0;
				int contador = 0;
				while (nota) {
					suma += nota->nota;
					contador++;
					nota = nota->siguiente;
				}
				float promedio = suma / contador;
				cout << "El promedio de notas del alumno " << alumno->getNombre() << " en el curso " << curso->curso->getNombre() << " es: " << promedio << endl;
				return;
			}
			curso = curso->siguiente;
		}
		cout << "El alumno no esta inscrito en el curso con codigo: " << codigoCurso << endl;
	}
	void promedioGeneralAlumno(string id) {
		Alumno* alumno = buscarPorID(id);
		if (!alumno) {
			cout << "Alumno no encontrado." << endl;
			return;
		}
		NodoCurso* curso = alumno->getCursosInscritos();
		if (!curso) {
			cout << "El alumno no esta inscrito en ningun curso." << endl;
			return;
		}
		float sumaPromedio = 0.0;
		int cantidadCursos = 0;
		while (curso) {
			NodoNota* nota = curso->notas;
			if (nota) {
				float suma = 0;
				int cont = 0;
				while (nota) {
					suma += nota->nota;
					cont++;
					nota = nota->siguiente;
				}
				sumaPromedio += (suma / cont);
				cantidadCursos++;
			}
			curso = curso->siguiente;
		}
		if (cantidadCursos == 0) {
			cout << "El alumno no tiene notas registradas." << endl;
			return;
		}
		cout << "Promedio general de " << alumno->getNombre() << " es: "
			<< (sumaPromedio / cantidadCursos) << endl;
		}
};
//Clase ListaCursos
class ListaCursos {
private:
	NodoCurso* cabeza;
public:
    ListaCursos() {
		cabeza = nullptr;
    }
	void agregarCurso(Curso* nuevo) {
		NodoCurso* nodo = new NodoCurso{ nuevo, nullptr, nullptr };
		if (!cabeza) {
			cabeza = nodo;
		}
		else {
			NodoCurso* aux = cabeza;
			while (aux->siguiente) {
				aux = aux->siguiente;
			}
			aux->siguiente = nodo;
		}
		cout << "Curso agregado"<< endl;
	}
	Curso* buscarPorCodigo(int codigo) {
		NodoCurso* aux = cabeza;
		while (aux) {
			if (aux->curso->getCodigo() == codigo) {
				aux->curso->mostrarInfo();
				return aux->curso;
			}
			aux = aux->siguiente;
		}
		cout << "No se encontro curso con ese codigo: " << codigo << endl;
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
	void eliminarCurso(int codigo) {
		NodoCurso* aux = cabeza;
		NodoCurso* aux2 = nullptr;
		while (aux) {
			if (aux->curso->getCodigo() == codigo) {
				NodoAlumno* alumno = aux->curso->getAlumnosInscritos();
				while (alumno) {
					alumno->alumno->eliminarInscripcion(codigo); 
					alumno = alumno->siguiente;
				}
				if (aux2) {
					aux2->siguiente = aux->siguiente;
				}
				else {
					cabeza = aux->siguiente;
				}
				delete aux->curso;
				delete aux;

				cout << "Curso con codigo " << codigo << " eliminado." << endl;
				return;
			}
			aux2 = aux;
			aux = aux->siguiente;
		}
		cout << "No se encontro curso con codigo: " << codigo << endl;
	}
	void mostrarTodos() {
		NodoCurso* aux = cabeza;
		if(!aux) {
			cout << "No hay cursos registrados." << endl;
			return;
		}
		while (aux) {
			aux->curso->mostrarInfo();
			aux = aux->siguiente;
		}
	}
};
//Menus
void menuAlumnos(ListaAlumnos &);
void menuCursos(ListaCursos &,ListaAlumnos &);	
void menuInscripcion(ListaAlumnos &, ListaCursos &);	
void menuNotas(ListaAlumnos &);	
void menureportes(ListaAlumnos&);	
//main

int main() {
	ListaAlumnos listaAlumnos;
	ListaCursos listaCursos;
	int opcion;
	do {
		cout << "Menu de opciones:" << endl;
		cout << "1. Manejo de Alumnos" << endl;
		cout << "2. Manejo de Cursos" << endl;
		cout << "3. Manejo de Inscripciones" << endl;
		cout << "4. Eliminar Alumno de Curso" << endl;
		cout << "5. Manejo de Notas" << endl;
		cout << "6. Consultas y Reportes" << endl;
		cout << "0. Cerrar programa" << endl;
		cout << "Ingrese una opcion: ";
		switch(opcion) {
		case 1:menuAlumnos(listaAlumnos);	break;
		case 2:menuCursos(listaCursos,listaAlumnos);break;
		case 3:menuInscripcion(listaAlumnos, listaCursos);	break;
		case 4: {
			string idAlumno;
			int codigoCurso;
			cout << "Ingrese el ID del alumno: ";
			getline(cin, idAlumno);
			cout << "Ingrese el codigo del curso: ";
			cin >> codigoCurso;
			Alumno* alumno = listaAlumnos.buscarPorID(idAlumno);
			if (alumno) {
				alumno->eliminarInscripcion(codigoCurso);
			}
			else {
				cout << "Alumno no encontrado." << endl;
			}
			break;
		}
		case 5:menuNotas(listaAlumnos);	break;
		case 6:menureportes(listaAlumnos);	break;
		case 0:cout << "Saliendo del programa..." << endl;break;
		default:cout << "Opcion invalida, intente de nuevo." << endl;
		}
	} while (opcion != 0);
	return 0;
};
//submenus
void menuAlumnos(ListaAlumnos& listaAlumnos) {
	int opcion;
	do {
		cout << "\n--- Manejo de Alumnos ---" << endl;
		cout << "1. Agregar Alumno" << endl;
		cout << "2. Buscar Alumno por ID" << endl;
		cout << "3. Buscar Alumno por Nombre" << endl;
		cout << "4. Eliminar Alumno" << endl;
		cout << "5. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		switch (opcion) {
		case 1: {
			string ID;
			string nombre;
			string apellido;
			string carrera;
			string fecha;
			cout << "Ingrese el ID: ";
			getline(cin, ID);
			if (!listaAlumnos.existe(ID)) {
				cout << "Ingrese el nombre: ";
				getline(cin, nombre);
				cout << "Ingrese el apellido: ";
				getline(cin, apellido);
				cout << "Ingrese la carrera: ";
				getline(cin, carrera);
				cout << "Ingrese la fecha actual: ";
				getline(cin, fecha);
				listaAlumnos.agregarAlumno(new Alumno(ID, nombre, apellido, carrera, fecha));
				cout << "Alumno creado con exito: " << endl;
				break;
			}
			else {
				cout << "El ID ya existe, intente de nuevo." << endl;
			}
			break;;
		}
		case 2: {
			string id; cout << "ID: "; getline(cin, id);
			listaAlumnos.buscarPorID(id);
			break;
		}
		case 3: {
			string nombre; cout << "Nombre: "; getline(cin, nombre);
			listaAlumnos.buscarPorNombre(nombre);
			break;
		}
		case 4: {
			string id; cout << "ID: "; getline(cin, id);
			listaAlumnos.eliminarAlumno(id);
			break;
		}
		case 0: break;
		default: cout << "Opcion invalida, intente de nuevo.\n";
		}
	} while (opcion != 0);
}
		
void menuCursos(ListaCursos& listaCursos, ListaAlumnos& listaAlumnos) {
	int opcion;
	do {
		cout << "\n--- Manejo de Cursos ---" << endl;
		cout << "1. Agregar Curso" << endl;
		cout << "2. Buscar Curso por Codigo" << endl;
		cout << "3. Buscar Curso por Nombre" << endl;
		cout << "4. Eliminar Curso" << endl;
		cout << "5. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		switch (opcion) {
		case 1: {
			int codigo;
			string nombre;
			int cantEstudiantes;
			string carrera;
			string profesor;
			cout << "Ingrese el codigo: ";
			cin >> codigo;
			if (!listaCursos.buscarPorCodigo(codigo)) {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Ingrese el nombre: ";
				getline(cin, nombre);
				cout << "Ingrese la cantidad de estudiantes: ";
				cin >> cantEstudiantes;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Ingrese la carrera: ";
				getline(cin, carrera);
				cout << "Ingrese el nombre del profesor: ";
				getline(cin, profesor);
				listaCursos.agregarCurso(new Curso(codigo, nombre, cantEstudiantes, carrera, profesor));
				cout << "Curso creado con exito: " << endl;
				break;
			}
			else {
				cout << "El codigo ya existe, intente de nuevo." << endl;
			}
			break;;
		}
		case 2: {
			int codigo; cout << "Codigo: "; cin >> codigo;
			listaCursos.buscarPorCodigo(codigo);
			break;
		}
		case 3: {
			string nombre; cout << "Nombre: "; getline(cin, nombre);
			listaCursos.buscarPorNombre(nombre);
			break;
		}
		case 4: {
			int codigo; cout << "Codigo: "; cin >> codigo;
			listaCursos.eliminarCurso(codigo);
			break;
		}
		case 0: break;
		default: cout << "Opcion invalida, intente de nuevo";
		}
	} while (opcion != 0);
}
void menuInscripcion(ListaAlumnos& listaAlumnos, ListaCursos& listaCursos) {
	int opcion;
	do {
		cout << "\n--- Manejo de Inscripciones ---" << endl;
		cout << "1. Inscribir Alumno a Curso" << endl;
		cout << "2. Eliminar Inscripcion de Alumno a Curso" << endl;
		cout << "3. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
			string idAlumno;
			int codigoCurso;
			cout << "Ingrese el ID del alumno: ";
			getline(cin, idAlumno);
			cout << "Ingrese el codigo del curso: ";
			cin >> codigoCurso;
			Alumno* alumno = listaAlumnos.buscarPorID(idAlumno);
			if (alumno) {
				Curso* curso = listaCursos.buscarPorCodigo(codigoCurso); 
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
		}
		case 2: {
			string idAlumno;
			int codigoCurso;
			cout << "Ingrese el ID del alumno: ";
			getline(cin,idAlumno);
			cout << "Ingrese el codigo del curso: ";
			cin >>codigoCurso;
			Alumno* alumno = listaAlumnos.buscarPorID(idAlumno);
			if (alumno) {
				alumno->eliminarInscripcion(codigoCurso);
			}
			else {
				cout << "Alumno no encontrado." << endl;
			}
			break;
		}
		case 3: 
			cout << "Volviendo al menu principal..." << endl; 
			break;
		default: cout << "Opcion invalida, intente de nuevo." << endl;
		}
	} while (opcion != 4);
}
void menuNotas(ListaAlumnos& listaAlumnos) {
	int opcion;
	do {
		cout << "\n--- Manejo de Notas ---" << endl;
		cout << "1. Registrar Nota" << endl;
		cout << "2. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
			string id; 
			int codigo; 
			float nota;
			cout << "Ingrese el ID del alumno: ";
			getline(cin, id);
			cout << "Ingrese el codigo del curso: ";
			cin >> codigo;
			cout << "Ingrese la nota (1.0 - 7.0): ";
			cin >> nota;
			Alumno* alumno = listaAlumnos.buscarPorID(id);
			if (alumno) {
				alumno->registrarNotas(codigo, nota);
			}
			else {
				cout << "Alumno no encontrado." << endl;
			}
			break;
		}
		case 2: 
			cout << "Volviendo al menu principal..." << endl; 
			break;
		default: cout << "Opcion invalida, intente de nuevo.\n";
		}
	} while (opcion != 0);
}
void menureportes(ListaAlumnos& listaAlumnos) {
	int opcion = 0;
	while (opcion != 4) {
		cout << "\n--- Consultas y Reportes ---" << endl;
		cout << "1. Obtener Alumnos por Carrera" << endl;
		cout << "2. Mostrar Cursos de un Alumno" << endl;
		cout << "3. Promedio de un Alumno en un Curso" << endl;
		cout << "4. Promedio General de un Alumno" << endl;
		cout << "5. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
			string carrera;
			cout << "Ingrese la carrera: ";
			getline(cin, carrera);
			listaAlumnos.obtenerAlumnosPorCarrera(carrera);
			break;
		}
		case 2: {
			string idAlumno;
			cout << "Ingrese el ID del alumno: ";
			getline(cin, idAlumno);
			listaAlumnos.mostrarCursosDelAlumno(idAlumno);
			break;
		}
		case 3: {
			string idAlumno;
			int codigoCurso;
			cout << "Ingrese el ID del alumno: ";
			getline(cin, idAlumno);
			cout << "Ingrese el codigo del curso: ";
			cin >> codigoCurso;
			listaAlumnos.promedioAlumnoEnCurso(idAlumno, codigoCurso);
			break;
		}
		case 4: {
			string idAlumno;
			cout << "Ingrese el ID del alumno: ";
			getline(cin, idAlumno);
			listaAlumnos.promedioGeneralAlumno(idAlumno);
			break;
		}
		case 0: 
			cout << "Volviendo al menu principal..." << endl; 
			break;
		default: cout << "Opcion invalida, intente de nuevo." << endl;
		}
	}
}