#pragma once

#include "size.hh"
#include <iostream>

#define MIN_DIFF 0.01

template <typename Type, int Size>
class Vector {

private:

    Type size[Size];     //Tablica wektora

public:

    Vector();

    Vector(Type [Size]);

    Vector<Type, Size> operator + (const Vector<Type, Size> &v);

    Vector<Type, Size> operator - (const Vector<Type, Size> &v);

    Vector<Type, Size> operator * (const Type &tmp);

    Vector<Type, Size> operator / (const Type &tmp);

    const Type &operator [] (unsigned int index) const;

    Type &operator [] (unsigned int index);

    bool operator == (const Vector<Type, Size> &v) const;

};

std::ostream &operator << (std::ostream &out, Vector<double, SIZE> const &tmp);

std::istream &operator >> (std::istream &in, Vector<double, SIZE> &tmp);



/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <typename Type, int Size>
Vector<Type, Size>::Vector() {
    for (int i = 0; i < Size; ++i) {
        size[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <typename Type, int Size>
Vector<Type, Size>::Vector(Type tmp[SIZE]) {
    for (int i = 0; i < Size; ++i) {
        size[i] = tmp[i];
    }
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <typename Type, int Size>
Vector<Type, Size> Vector<Type, Size>::operator + (const Vector<Type, Size> &v) {
    for (int i = 0; i < Size; ++i) {
        size[i] += v[i];
    }
    return *this;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <typename Type, int Size>
Vector<Type, Size> Vector<Type, Size>::operator - (const Vector &v) {
    for (int i = 0; i < Size; ++i) {
        size[i] -= v[i];
    }
    return *this;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <typename Type, int Size>
Vector<Type, Size> Vector<Type, Size>::operator * (const Type &tmp) {
    for (int i = 0; i < Size; ++i) {
        size[i] *= tmp;
    }
    return *this;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <typename Type, int Size>
Vector<Type, Size> Vector<Type, Size>::operator / (const Type &tmp) {
    for (int i = 0; i < Size; ++i) {
        size[i] /= tmp;
    }

    return *this;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <typename Type, int Size>
const Type &Vector<Type, Size>::operator [] (unsigned int index) const {
    if (index >= Size) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <typename Type, int Size>
Type &Vector<Type, Size>::operator[](unsigned int index) {
    return const_cast<Type &>(const_cast<const Vector *>(this)->operator[](index));
}


template <typename Type, int Size>
bool Vector<Type, Size>::operator == (const Vector<Type, Size> &v) const {
    for (int i = 0; i < Size; ++i){
        if(abs(size[i] - v[i]) > MIN_DIFF){
            return 0;
        }
    }
    return 1;     
}

