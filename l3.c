ex 1

Acest prim exercițiu este unul practic, de conectare a componentelor și observare a comportamentului codului original.
Conectarea pinilor: Conform cerinței, trebuie să conectezi pinul de ieșire al senzorului (Vout) la pinul RB7 al microcontrolerului, pinul GND la masa plăcii, iar pinul Vin la sursa de 3.3V. Pinul RB7 este cel pe care este disponibilă funcționalitatea de întrerupere externă INT0.
Comportamentul observat (cu programul inițial): Senzorul de obstacol returnează valoarea 1 logic atâta timp cât nu are niciun obstacol în față și 0 logic atunci când detectează unul. Programul exemplu inițial are polaritatea setată pe 1 (_INT0EP = 1;), ceea ce înseamnă că întreruperea este declanșată doar pe front negativ (la trecerea din 1 în 0).
Rezultat: Vei observa că LED-ul își va schimba starea (dacă e stins, se aprinde; dacă e aprins, se stinge) doar atunci când pui mâna/obiectul în fața senzorului. Când iei mâna (trecerea din 0 în 1, front pozitiv), nu se va întâmpla nimic, deoarece acea tranziție nu declanșează o întrerupere cu setările curente.

ex 2

#include "p33Fxxxx.h"

void __attribute__ ((interrupt, no_auto_psv)) _INT0Interrupt(void)
{
    if (_RB7 == 0) {
        _RB15 = 1;       
        _INT0EP = 0;     
    } else {
        _RB15 = 0;       
        _INT0EP = 1;     
    }

    _INT0IF = 0;         
}

int main(void)
{
    TRISB = 0x0000;      
    _TRISB7 = 1;         
    
    PORTB = 0x0000;      

    _INT0IF = 0;         
    _INT0IE = 1;         
    _INT0EP = 1;         
    
    while(1)
    {
    }
}