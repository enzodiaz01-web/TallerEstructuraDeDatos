#include <iostream>
#include <string>
using namespace std;
class Alumno;
class Curso;

struct NodoAlumno {
	Alumno* alumno;
	NodoAlumno* siguiente;
};
struct NodoCurso{
	Curso* curso;
	NodoCurso* siguiente;
};


