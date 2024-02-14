#include "asunto.h"
#include <iostream>
using namespace std;

Asunto::Asunto()
{
    cout<<"asunto luotu"<<endl;
}
void Asunto::maarita(int a, int b)
{
    asukasMaara=a;
    neliot=b;
    cout<<"Asunto maaritetty, asukkaita= "<<a<<" nelioita= "<<b<<endl;
}
double Asunto::laskeKulutus(double hinta)
{
    int kulutus=hinta*asukasMaara*neliot;
    cout<<"Kokonaiskulutus kun hinta = "<<hinta<<", kulutus = "<<kulutus<<endl;

    return kulutus;
}
