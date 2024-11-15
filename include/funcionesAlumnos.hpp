#ifndef FUNCIONESALUMNOS_HPP
#define FUNCIONESALUMNOS_HPP

#include "ListaAlumnos.hpp"

void cargarDesdeArchivo(ListaAlumnos &lista);
void guardarEnArchivo(const ListaAlumnos &lista);
void mostrarMenu(ListaAlumnos &lista);

#endif