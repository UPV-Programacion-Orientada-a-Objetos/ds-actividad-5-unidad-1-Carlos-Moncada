#ifndef MATRIZDINAMICA_H
#define MATRIZDINAMICA_H

#include "MatrizBase.h"

template <typename T>
class MatrizDinamica : public MatrizBase<T> {
private:
    T** datos; 
    
    void liberar() {
        if (datos) {
            for (int i = 0; i < this->filas; ++i) {
                delete[] datos[i];
            }
            delete[] datos;
            datos = nullptr;
        }
    }
    void reservar(int f, int c) {
        this->filas = f;
        this->columnas = c;
        datos = new T*[this->filas];
        for (int i = 0; i < this->filas; ++i) {
            datos[i] = new T[this->columnas](); 
        }
    }

public:

    MatrizDinamica(int f, int c) : MatrizBase<T>(f, c) {
        std::cout << "-> Creando Matriz Dinamica (" << f << "x" << c << ")..." << std::endl;
        reservar(f, c);
    }

    virtual ~MatrizDinamica() {
        std::cout << "-> Llamando al destructor de MatrizDinamica..." << std::endl;
        liberar();
    }

    MatrizDinamica(const MatrizDinamica& otra) : MatrizBase<T>(otra.filas, otra.columnas) {
        std::cout << "-> Constructor de COPIA de MatrizDinamica..." << std::endl;
        reservar(otra.filas, otra.columnas);
        for (int i = 0; i < this->filas; ++i) {
            for (int j = 0; j < this->columnas; ++j) {
                datos[i][j] = otra.datos[i][j];
            }
        }
    }

    MatrizDinamica& operator=(const MatrizDinamica& otra) {
        std::cout << "-> Operador de ASIGNACION de MatrizDinamica..." << std::endl;
        if (this == &otra) { 
            return *this;
        }
        liberar();
        reservar(otra.filas, otra.columnas);
        for (int i = 0; i < this->filas; ++i) {
            for (int j = 0; j < this->columnas; ++j) {
                datos[i][j] = otra.datos[i][j];
            }
        }
        return *this;
    }
    

    virtual void cargarValores() override {
        // Valores del ejemplo A
        this->setValor(0, 0, static_cast<T>(1.5));
        this->setValor(0, 1, static_cast<T>(2.0));
        this->setValor(1, 0, static_cast<T>(0.0));
        this->setValor(1, 1, static_cast<T>(1.0));
        this->setValor(2, 0, static_cast<T>(4.5));
        this->setValor(2, 1, static_cast<T>(3.0));
    }

    virtual void imprimir() const override {
        for (int i = 0; i < this->filas; ++i) {
            std::cout << "| ";
            for (int j = 0; j < this->columnas; ++j) {
                std::cout << this->getValor(i, j) << " | ";
            }
            std::cout << std::endl;
        }
    }

    virtual void setValor(int f, int c, T valor) override {
        if (f >= 0 && f < this->filas && c >= 0 && c < this->columnas) {
            datos[f][c] = valor;
        }
    }

    virtual T getValor(int f, int c) const override {
        if (f >= 0 && f < this->filas && c >= 0 && c < this->columnas) {
            return datos[f][c];
        }
        return T();
    }

    virtual MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override {
        if (this->filas != otra.getFilas() || this->columnas != otra.getColumnas()) {
            return nullptr; 
        }

        MatrizDinamica<T>* resultado = new MatrizDinamica<T>(this->filas, this->columnas);

        for (int i = 0; i < this->filas; ++i) {
            for (int j = 0; j < this->columnas; ++j) {
                T valorSuma = this->getValor(i, j) + otra.getValor(i, j);
                resultado->setValor(i, j, valorSuma);
            }
        }
        return resultado;
    }
};
#endif 