problema 2

#include "p33fxxxx.h"

void Init_Timer1(void)
{
    T1CON = 0;             // Resetare registru de control [cite: 289]
    T1CONbits.TCKPS = 0b00; // Selectare prescaler 1:1 
    TMR1 = 0;              // Initializare registru numarator [cite: 292]
    PR1 = 14000;           // Valoarea calculata pentru 350us
    
    _T1IF = 0;             // Resetare flag de intrerupere [cite: 295]
    _T1IP = 1;             // Setare prioritate intrerupere [cite: 296]
    _T1IE = 1;             // Activare intrerupere Timer1 [cite: 297]
    T1CONbits.TON = 1;     // Pornire Timer1 [cite: 298]
}

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void)
{
    _RB15 ^= 1;            // Comutare stare RB15 exclusiv (fara if) 
    _T1IF = 0;             // Resetare flag de intrerupere [cite: 304, 305]
}

int main(void)
{
    TRISB = 0x0000;        // Configurare pini port B ca iesire [cite: 309]
    PORTB = 0xF000;        // Initializare stare port B [cite: 311]
    
    Init_Timer1();         // Configurare Timer 1 [cite: 312, 316]
    
    while(1)
    {
        // Bucla infinita, actiunea are loc in intrerupere [cite: 313]
    }
}

problema 3

#include "p33fxxxx.h"

void Init_Timer32(void)
{
    T2CON = 0;             // Oprire si resetare configuratii pentru Timer2 
    T3CON = 0;             // Oprire Timer3
    
    T2CONbits.T32 = 1;     // Activare mod de functionare pe 32 de biti 
    T2CONbits.TCKPS = 0b00;// Prescaler 1:1, controlat exclusiv din Timer2 [cite: 241]
    
    TMR3 = 0;              // Resetare registre TMR (MSW) [cite: 282]
    TMR2 = 0;              // Resetare registre TMR (LSW) [cite: 282]
    
    PR3 = 0x017D;          // Partea mai semnificativa a valorii de comparatie [cite: 281]
    PR2 = 0x7840;          // Partea mai putin semnificativa a valorii de comparatie [cite: 281]
    
    _T3IF = 0;             // Resetare flag intrerupere (pentru modul 32-biti se foloseste T3) 
    _T3IP = 1;             // Prioritate intrerupere
    _T3IE = 1;             // Activare intrerupere pentru Timer3 
    
    T2CONbits.TON = 1;     // Pornire canal pe 32 de biti (se activeaza de la Type B / Timer2) 
}

void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void)
{
    _RB14 ^= 1;            // Comutam pinul RB14 fara conditionalitati logice
    _T3IF = 0;             // Resetam corect flag-ul canalului de tip C 
}

int main(void)
{
    TRISB = 0x0000;        // Toate iesiri [cite: 309]
    PORTB = 0x0000;        // Initializare pini pe 0
    
    Init_Timer32();        // Initializam canalul de timp concatenat
    
    while(1)
    {
        // Programul stationeaza aici, in timp ce timerul lucreaza in fundal
    }
}