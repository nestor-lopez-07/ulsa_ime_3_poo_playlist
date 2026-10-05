// Implementación de la clase Pista.

#include "Pista.h"

#include <iostream>

// La Duracion se construye en la lista de inicialización.
Pista::Pista(const std::string& titulo, int min, int seg)
    : titulo(titulo), duracion(min, seg) {
    // TODO 2.1: si el título llega vacío, guarda "Sin título".
    if (this->titulo.empty()) {
        this->titulo = "Sin título";
    }
}

std::string Pista::getTitulo() const { return titulo; }

Duracion Pista::getDuracion() const { return duracion; }

// TODO 2.2: implementa  void Pista::setTitulo(const std::string& nuevoTitulo)
//   Aplica la misma regla del título vacío.
void Pista::setTitulo(const std::string& nuevoTitulo) {
    if (nuevoTitulo.empty()) {
        titulo = "Sin título";
    } else {
        titulo = nuevoTitulo;
    }
}

// TODO 2.3: implementa  void Pista::mostrarInfo() const
//   Imprime el título y la duración en una sola línea.
void Pista::mostrarInfo() const {
    std::cout << "Titulo: " << titulo << " | Duracion: ";
    duracion.imprimir();
}
  // Pregunta: ¿qué pasaría si quitaras duracion(min, seg) de la
    // lista de inicialización? Pruébalo y lee el error del compilador. el constructor seria automatico y fallaria