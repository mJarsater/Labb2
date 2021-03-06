// Martin Jars�ter
// Labb2, IntVector.h � klassdefinition
#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>

using namespace std;
class IntVector
{
public:

    // Standard-konstruktor
    IntVector();

    // Konstrusktor f�r { element }
    IntVector(std::initializer_list<int>);


    // Copy-konstuktor (Const)
    IntVector(const IntVector& other);


    // Returnera storleken
    int size() const;

    // L�gg till int
    void push_back(int element);

    // Index operator
    int&  operator[](int index) const;


    // Tilldelnings kostruktor (?)
    const IntVector operator=(const IntVector& other);

    ~IntVector();

private:
    int length;
    int* data;
    friend std::ostream& operator<<(std::ostream&,
        const IntVector&);
};

#endif INTVECTOR_H