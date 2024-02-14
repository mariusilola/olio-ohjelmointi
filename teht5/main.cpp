#include <iostream>
#include "kerros.h"
#include "katutaso.h"
#include "asunto.h"
#include "kerrostalo.h"

using namespace std;

int main()
{


    Kerrostalo *tiedot = new Kerrostalo;

    int kokonaisuus=tiedot->laskeKulutus(1);
    cout<<"asuntojen kulutus, kun hinta=1, on "<<kokonaisuus<<endl;

    return 0;
}
