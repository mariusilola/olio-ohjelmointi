#ifndef KERROSTALO_H
#define KERROSTALO_H
#include "kerros.h"
#include "katutaso.h"
#include <iostream>
using namespace std;

class Kerrostalo
{
public:
    Kerrostalo();
    ~Kerrostalo();
    double laskeKulutus(double);

private:
    Katutaso* eka = new Katutaso();
    Kerros* toka = new Kerros();
    Kerros* kolmas = new Kerros();
};

#endif // KERROSTALO_H
