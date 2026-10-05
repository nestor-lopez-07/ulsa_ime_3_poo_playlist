// Implementación de la clase Playlist.

#include "Playlist.h"
#include <algorithm>
#include <iostream>

// TODO 4.1: implementa el constructor de Playlist.
Playlist::Playlist(const std::string& nombre) : nombre(nombre) {}

// TODO 4.2: implementa  bool Playlist::agregarCancion(Cancion* cancion)
//   Devuelve false si el puntero es nullptr o si la canción ya está en la
//   playlist; en otro caso la agrega y devuelve true.
bool Playlist::agregarCancion(Cancion* cancion) {
    if (cancion == nullptr) {
        return false;
    }

    // Verificar si ya existe en la lista para evitar duplicados
    for (const auto* c : canciones) {
        if (c == cancion) {
            return false;
        }
    }

    canciones.push_back(cancion);
    return true;
}

// TODO 4.3: implementa  bool Playlist::agregarPodcast(Podcast* podcast)
//   Mismas reglas que agregarCancion.
bool Playlist::agregarPodcast(Podcast* podcast) {
    if (podcast == nullptr) {
        return false;
    }

    // Verificar si ya existe en la lista para evitar duplicados
    for (const auto* p : podcasts) {
        if (p == podcast) {
            return false;
        }
    }

    podcasts.push_back(podcast);
    return true;
}

// TODO 4.4: implementa  int Playlist::cantidadPistas() const
int Playlist::cantidadPistas() const {
    return canciones.size() + podcasts.size();
}

// TODO 4.5: implementa  Duracion Playlist::duracionTotal() const
//   Suma los segundos de todas las pistas y devuelve una Duracion.
Duracion Playlist::duracionTotal() const {
    int totalSegundos = 0;

    for (const auto* c : canciones) {
        if (c != nullptr) {
            totalSegundos += c->getDuracion().totalSegundos();
        }
    }

    for (const auto* p : podcasts) {
        if (p != nullptr) {
            totalSegundos += p->getDuracion().totalSegundos();
        }
    }

    // El constructor Duracion(0, totalSegundos) se encarga de convertir y normalizar los segundos a minutos.
    return Duracion(0, totalSegundos);
}

// TODO 4.6: implementa  void Playlist::mostrar() const
//   Imprime el nombre, cada pista, la cantidad de pistas y la duración total.
void Playlist::mostrar() const {
    std::cout << "Playlist: " << nombre << std::endl;

    std::cout << "Canciones" << std::endl;
    for (const auto* c : canciones) {
        if (c != nullptr) {
            c->mostrar();
        }
    }

    std::cout << "Podcasts" << std::endl;
    for (const auto* p : podcasts) {
        if (p != nullptr) {
            p->mostrar();
        }
    }

    std::cout << "Total de pistas: " << cantidadPistas() << std::endl;
    std::cout << "Duracion total: ";
    duracionTotal().imprimir();
    std::cout << std::endl;
}

void Playlist::ordenarPorDuracion() {
    std::vector<const Pista*> pistas;

    for (const auto* c : canciones) {
        if (c != nullptr) {
            pistas.push_back(c);
        }
    }

    for (const auto* p : podcasts) {
        if (p != nullptr) {
            pistas.push_back(p);
        }
    }

    std::sort(pistas.begin(), pistas.end(),
              [](const Pista* a, const Pista* b) {
                  return a->getDuracion().totalSegundos() < b->getDuracion().totalSegundos();
              });

    std::cout << "Playlist ordenada por duracion:" << std::endl;
    for (const auto* pista : pistas) {
        if (pista != nullptr) {
            std::cout << "- " << pista->getTitulo() << " (";
            pista->getDuracion().imprimir();
            std::cout << ")" << std::endl;
        }
    }
}

void Playlist::mostrarPistaMasLarga() const {
    const Pista* masLarga = nullptr;

    for (const auto* c : canciones) {
        if (c != nullptr && (masLarga == nullptr || c->getDuracion().totalSegundos() > masLarga->getDuracion().totalSegundos())) {
            masLarga = c;
        }
    }

    for (const auto* p : podcasts) {
        if (p != nullptr && (masLarga == nullptr || p->getDuracion().totalSegundos() > masLarga->getDuracion().totalSegundos())) {
            masLarga = p;
        }
    }

    if (masLarga == nullptr) {
        std::cout << "No hay pistas en la playlist." << std::endl;
        return;
    }

    std::cout << "Pista mas larga: " << masLarga->getTitulo() << " (";
    masLarga->getDuracion().imprimir();
    std::cout << ")" << std::endl;
}

void Playlist::mostrarPistaMasCorta() const {
    const Pista* masCorta = nullptr;

    for (const auto* c : canciones) {
        if (c != nullptr && (masCorta == nullptr || c->getDuracion().totalSegundos() < masCorta->getDuracion().totalSegundos())) {
            masCorta = c;
        }
    }

    for (const auto* p : podcasts) {
        if (p != nullptr && (masCorta == nullptr || p->getDuracion().totalSegundos() < masCorta->getDuracion().totalSegundos())) {
            masCorta = p;
        }
    }

    if (masCorta == nullptr) {
        std::cout << "No hay pistas en la playlist." << std::endl;
        return;
    }

    std::cout << "Pista mas corta: " << masCorta->getTitulo() << " (";
    masCorta->getDuracion().imprimir();
    std::cout << ")" << std::endl;
}

void Playlist::mostrarMasLargaYMasCorta() const {
    mostrarPistaMasLarga();
    mostrarPistaMasCorta();
}
