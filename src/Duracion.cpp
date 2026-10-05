// Implementación de la clase Duracion.

#include "Duracion.h"
#include <iostream>
#include <iomanip> // Para std::setw y std::setfill

Duracion::Duracion(int min, int seg) {
    // TODO 1.1: valida y normaliza.
    if (min < 0 || seg < 0) {
        minutos = 0;
        segundos = 0;
    } else {
        minutos = min + (seg / 60);
        segundos = seg % 60;
    }
}

int Duracion::getMinutos() const { return minutos; }

int Duracion::getSegundos() const { return segundos; }

// TODO 1.2: implementa int Duracion::totalSegundos() const
//   Devuelve la duración completa expresada en segundos.
int Duracion::totalSegundos() const {
    return (minutos * 60) + segundos;
}

// TODO 1.3: implementa void Duracion::imprimir() const
//   Imprime con el formato m:ss (por ejemplo 3:05, no 3:5).
void Duracion::imprimir() const {
    std::cout << minutos << ":" 
              << std::setw(2) << std::setfill('0') << segundos;
}
// Pregunta: ¿por qué conviene validar aquí y no en main? para tener siempre un estado valido
