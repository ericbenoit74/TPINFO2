#include <Fifo.h>

CGeiiFifo::CGeiiFifo(void){
    iInIndex = 0;
    iOutIndex = 0;
    bOverflow = false;
}

void CGeiiFifo::init(void){
    iInIndex = 0;
    iOutIndex = 0;
    bOverflow = false;
}

bool CGeiiFifo::fifoIn(uint16_t val){
  bool l_bool_res = false;
  if( (iInIndex + 1) % FIFO_SIZE != iOutIndex){
    data[iInIndex] = val;
    iInIndex = (iInIndex + 1) % FIFO_SIZE;
    l_bool_res = true;
  }
  return(l_bool_res);
}

uint16_t CGeiiFifo::fifoOut(){
  uint16_t val = FIFO_EMPTY_DATA;
  int index;
  index = (iOutIndex + 1) % FIFO_SIZE;
  if(iOutIndex != iInIndex){
    val = data[iOutIndex];
    iOutIndex = index;
  }
  return(val);
}
