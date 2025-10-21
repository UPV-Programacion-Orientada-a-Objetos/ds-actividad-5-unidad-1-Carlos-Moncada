#ifndef MATRIZESTATICA_H
#define MATRIZESTATICA_H

#include "MatrizBase.h"

template <typename T, int M, int N>
class MatrizEstatica : public MatrizBase<T> {
private:
    T datos[M][N];

public:

    MatrizEstatica() : MatrizBase<T>(M, N) {
        std::cout << "-> Creando Matriz Estatica (" << M << "x" << N << ")..." << std::endl;
    }

    virtual ~MatrizEstatica() {
        std::cout << "-> Llamando al destructor de MatrizEstatica..." << std::endl;
    }

    virtual void cargarValores() override {
        for (int i = 0; i < this->filas; ++i) {
            for (int j = 0; j < this->columnas; ++j) {
                this->setValor(i, j, static_cast<T>(i + j + 0.5)); 
            }
        }
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

        MatrizEstatica<T, M, N>* resultado = new MatrizEstatica<T, M, N>();

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