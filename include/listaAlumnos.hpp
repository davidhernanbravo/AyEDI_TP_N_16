#ifndef LISTAALUMNOS_HPP
#define LISTAALUMNOS_HPP

#include "alumno.hpp"

const int MAX_ALUMNOS = 100;

class ListaAlumnos 
{
    private:
        Alumno alumnos[MAX_ALUMNOS];
        int contador;

    public:
        ListaAlumnos();
        bool insertarAlumno(const Alumno &alumno);
        bool eliminarAlumno(int id);
        int buscarAlumno(const std::string &nombre) const;
        void mostrarAlumno(int indice) const;
        void mostrarListaAlumnos() const;
        void ordenarListaAlumnos(bool ascendente);
        int obtenerContador() const;
        Alumno obtenerAlumno(int indice) const;
};

#endif