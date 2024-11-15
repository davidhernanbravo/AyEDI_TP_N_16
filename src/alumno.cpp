#include "../include/Alumno.hpp"

bool Alumno::operator>(const Alumno &otro) const 
    {
        return nombre > otro.nombre;
    }

bool Alumno::operator<(const Alumno &otro) const 
    {
        return nombre < otro.nombre;
    }