#include <Arduino.h>
#include <unity.h>
#include <Fifo.h>

CGeiiFifo g_fifo;

void setUp(void)
{
  g_fifo.init();
}

void tearDown(void)
{
  // clean stuff up here
}

void test_initialization(void){
  g_fifo.init();
  TEST_ASSERT_EQUAL(FIFO_EMPTY_DATA, g_fifo.fifoOut());
}

void test_one_data(void)
{
  g_fifo.fifoIn(1234);
  TEST_ASSERT_EQUAL(1234, g_fifo.fifoOut());
}

void test_2in_3out(void)
{
  g_fifo.fifoIn(1);
  g_fifo.fifoIn(2);
  TEST_ASSERT_EQUAL(1, g_fifo.fifoOut());
  TEST_ASSERT_EQUAL(2, g_fifo.fifoOut());
  TEST_ASSERT_EQUAL(FIFO_EMPTY_DATA, g_fifo.fifoOut());
}

void test_fifo_full(){
  for(int l_int1=0; l_int1<FIFO_SIZE-2; l_int1++){
    g_fifo.fifoIn(l_int1);
  }
  // fifo presque pleine
  TEST_ASSERT_TRUE_MESSAGE(g_fifo.fifoIn(1000),"fifo non pleine identifiee comme pleine");
  // fifo pleine
  TEST_ASSERT_FALSE_MESSAGE(g_fifo.fifoIn(1000),"fifo pleine non detectee");
}


void setup()
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_initialization);
  RUN_TEST(test_one_data);
  RUN_TEST(test_2in_3out);
  RUN_TEST(test_fifo_full);
  UNITY_END();
}


void loop()
{

}