#include <Timer3.h>

#define TCCRnA_COMnA_MSK 0xC0
#define TCCRnA_COMnA_OFF 0
#define TCCRnA_COMnA_TOGGLE 0x40
#define TCCRnA_WGMn_CTCOCRnA 0

#define TCCRnB_WGMn_CTCOCRnA 0x08 
#define TCCRnB_CS_CLK8 0x02
#define TCCRnB_ICNC_ON 0x80
#define TCCRnB_ICES_ON 0x40

#define DODEKA_NOTES "CKDTEFHGPAVBC"
#define DODEKA_LA 440
#define DODEKA_DEMITON 1.05946309


void CTimer3PE3::InitTimer3PE3(void) {
    TCCR3A = TCCRnA_COMnA_TOGGLE | TCCRnA_WGMn_CTCOCRnA;
    TCCR3B = TCCRnB_WGMn_CTCOCRnA | TCCRnB_CS_CLK8;
    TCCR3C = 0;
    OCR3A = 1000;
    DDRE = DDRE | BIT3;
}


void CTimer3PE3::DemTimer3PE3(void) {
    //DDRE = DDRE | BIT3;
    TCCR3A = (TCCR3A & ~TCCRnA_COMnA_MSK) | TCCRnA_COMnA_TOGGLE;
}

void CTimer3PE3::StopTimer3PE3(void) {
    //DDRE = DDRE & ~BIT3;
    TCCR3A = (TCCR3A & ~TCCRnA_COMnA_MSK) | TCCRnA_COMnA_OFF;
}

void CTimer3PE3::FreqTimer3PE3(unsigned long ulFrequence) {
    word wOCR3A = 0;
    wOCR3A = 1000000 / ulFrequence;
    OCR3A = wOCR3A;
}
