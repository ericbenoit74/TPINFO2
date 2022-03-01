#include <Timer3.h>

void CTimer3PE3::InitTimer3PE3(void) {
    TCCR3A = B01000000;
    TCCR3B = B00001010;
    TCCR3C = 0;
    OCR3A = 1000;
    DDRE = DDRE | BIT3;
}


void CTimer3PE3::DemTimer3PE3(void) {
    DDRE = DDRE | BIT3;
}

void CTimer3PE3::StopTimer3PE3(void) {
    DDRE = DDRE & ~BIT3;
}

void CTimer3PE3::FreqTimer3PE3(unsigned long ulFrequence) {
    word wOCR3A = 0;
    wOCR3A = 1000000 / ulFrequence;
    OCR3A = wOCR3A;
}
