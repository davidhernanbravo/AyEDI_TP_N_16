#include "../include/listaAlumnos.hpp"

#include <iostream>

ListaAlumnos::ListaAlumnos() 
    : contador(0) {}

bool ListaAlumnos::insertarAlumno(const Alumno &alumno) 
    {
        if (contador < MAX_ALUMNOS) 
            {
                alumnos[contador++] = alumno;
                return true;
            } else 
                {
                    cout << "Lista llena. No se puede insertar mas alumnos." << endl;
                    return false;
                }
    }

bool ListaAlumnos::eliminarAlumno(int id) 
    {
        for (int i = 0; i < contador; i++) 
            {
                if (alumnos[i].id == id) 
                    {
                        for (int j = i; j < contador - 1; j++) 
                            {
                                alumnos[j] = alumnos[j + 1];
                            }

                        contador--;

                        return true;
                    }
            }

        cout << "Alumno con ID " << id << " no encontrado." << endl;
        
        return false;
    }

int ListaAlumnos::buscarAlumno(const string &nombre) const 
    {
        for (int i = 0; i < contador; i++) 
            {
                if (alumnos[i].nombre == nombre) 
                    {
                        return i;
                    }
            }

        return -1;
    }

void ListaAlumnos::mostrarAlumno(int indice) const 
    {
        if (indice >= 0 && indice < contador) 
            {
                cout << "ID: " << alumnos[indice].id << endl;
                cout << "Nombre: " << alumnos[indice].nombre << endl;
                cout << "Domicilio: " << alumnos[indice].domicilio << endl << endl;
            }
    }

void ListaAlumnos::mostrarListaAlumnos() const 
    {
        for (int i = 0; i < contador; i++) 
            {
                mostrarAlumno(i);
            }
    }

void ListaAlumnos::ordenarListaAlumnos(bool ascendente) 
{
    for (int i = 0; i < contador - 1; i++) 
        {
            for (int j = i + 1; j < contador; j++) 
                {
                    if ((ascendente && alumnos[i] > alumnos[j]) || (!ascendente && alumnos[i] < alumnos[j])) 
                        {
                            Alumno temp = alumnos[i];
                            alumnos[i] = alumnos[j];
                            alumnos[j] = temp;
                        }
                }
        }
}

int ListaAlumnos::obtenerContador() const 
    {
        return contador;
    }

Alumno ListaAlumnos::obtenerAlumno(int indice) const 
    {
        return alumnos[indice];
    }