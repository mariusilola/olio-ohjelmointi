#ifndef KATUTASO_H
#define KATUTASO_H
#include "kerros.h"
#include <iostream>
using namespace std;

class Katutaso : public Kerros{
public:
    Katutaso();
    virtual ~Katutaso();
    Asunto* as1 = new Asunto();
    Asunto* as2 = new Asunto();
    void maaritaAsunnot() override;
    double laskeKulutus(double);
};

#endif // KATUTASO_H
