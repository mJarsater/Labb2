// Martin Jars�ter
// Labb2, IntVector.h � klassdefinition
#pragma once
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

    IntVector(IntVector& other);


    // Returnera storleken
    int const size();

    // L�gg till int
    void push_back(int element);

    // Index operator
    int& const operator[](int index);


    // Tilldelnings kostruktor (?)
    const IntVector operator=(const IntVector& other);

private:
    int length;
    int* data;
    
};