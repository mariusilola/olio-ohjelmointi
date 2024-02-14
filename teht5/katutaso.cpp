#include "katutaso.h"
#include "kerros.h"
#include <iostream>
using namespace std;

Katutaso::Katutaso()
{
    cout<<"Katutaso luotu"<<endl;
}

Katutaso::~Katutaso()
{
    delete as1;
    delete as2;
    as1 = nullptr;
    as2 = nullptr;
}

void Katutaso::maaritaAsunnot()
{
    cout<<"Maaritetaan 2 kpl katutason asuntoja"<<endl;
    as1->maarita(2,100);
    as2->maarita(2,100);
}

double Katutaso::laskeKulutus(double hinta)
{
    int kokokulutus=as1->laskeKulutus(1)+as2->laskeKulutus(1);
    return kokokulutus;
}
