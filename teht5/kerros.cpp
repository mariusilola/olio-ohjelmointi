#include "kerros.h"
#include <iostream>
using namespace std;

Kerros::Kerros()
{
    cout<<"Kerros luotu"<<endl;
}

Kerros::~Kerros()
{
    delete as1;
    delete as2;
    delete as3;
    delete as4;
    as1 = nullptr;
    as2 = nullptr;
    as3 = nullptr;
    as4 = nullptr;
}

void Kerros::maaritaAsunnot()
{
    cout<<"Maaritetaan katutasolta perittyja asuntoja"<<endl;
    cout<<"Maaritetaan 4 kpl asuntoja"<<endl;
    as1->maarita(2,100);
    as2->maarita(2,100);
    as3->maarita(2,100);
    as4->maarita(2,100);
}


double Kerros::laskeKulutus(double hinta)
{

    int summa=as1->laskeKulutus(1)+as2->laskeKulutus(1)+as3->laskeKulutus(1)+as4->laskeKulutus(1);
    return summa;
}
