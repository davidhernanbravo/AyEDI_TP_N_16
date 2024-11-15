#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <string>

using namespace std;

class Alumno 
    {
        public:
            int id;
            string nombre;
            string domicilio;

            bool operator>(const Alumno &otro) const;
            bool operator<(const Alumno &otro) const;
    };

#endif