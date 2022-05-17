#ifndef GEIIUTIL_FIFO_H
#define GEIIUTIL_FIFO_H
#include <Arduino.h>

#define FIFO_SIZE 256
#define FIFO_EMPTY_DATA 65535

class CGeiiFifo {
    int iInIndex = 0;
    int iOutIndex = 0;
    bool bOverflow = false;
    uint16_t data[FIFO_SIZE];

    public:

    CGeiiFifo(void);

    void init(void);
  
    bool fifoIn(uint16_t val);

    uint16_t fifoOut(void);
};




#endif
