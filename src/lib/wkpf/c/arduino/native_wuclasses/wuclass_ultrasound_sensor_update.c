#include "debug.h"
#include "../../common/native_wuclasses/native_wuclasses.h"
#include <avr/io.h>
#include "../../common/native_wuclasses/GENERATEDwuclass_pir_sensor.h"
#define F_CPU         16000000
#include <util/delay.h>
//#define F_CPU         16000000
#define US_PORT PORTH
#define US_PIN PINH
#define US_DDR DDRH
#define US_POS PH4
#define US_ERROR 0xffff
#define US_NO_OBSTACLE 0xfffe
#define set_input(portdir, pin) portdir &= ~(1<<pin)
#define output_high(port, pin) port |= (1<<pin)
#define input_get(port, pin) ((port & (1 << pin)) != 0)
uint16_t getPulseWidth()
{
  uint32_t i, result;
  //wait for the rising edge
  for(i=0;i<600000;i++)
  {
        if(!(US_PIN & (1<<US_POS))) continue; else break;
  }
  if(i==600000)
        return 0xffff;//Indicates time out
  //High Edge Found
  //Setup Timer1
  TCCR1A=0x00;
  TCCR1B=(1<<CS11);//Prescaler = Fcpu/8
  TCNT1=0x00;          //Init counter
  //Now wait for the falling edge
  for(i=0;i<600000;i++)
  {
        if(US_PIN & (1<<US_POS))
        {
          if(TCNT1 > 60000) break; else continue;
        }
        else
          break;
  }
  if(i==600000)
        return 0xffff; //Indicates time out
  //Falling edge found
  result=TCNT1;
  //Stop Timer
  TCCR1B=0x00;
  if(result > 60000)
        return 0xfffe; //No obstacle
  else
        return (result>>1);
}
void wuclass_ultrasound_sensor_setup(wuobject_t *wuobject) {}
void wuclass_ultrasound_sensor_update(wuobject_t *wuobject) {
  uint16_t r;
  uint16_t avg;
  static uint16_t c1, c2, c3, c4, c5;
  uint16_t maxNum, minNum;
  maxNum = 0;
  minNum = 0;
  //Set Ultra Sonic Port as out
  US_DDR |= (1<<US_POS);
  US_PORT&=(~(1<<US_POS));  //Low
  _delay_us(2);
  //Give the US pin a 5us High Pulse
  US_PORT |= (1<<US_POS);  //High
  _delay_us(5);
  US_PORT&=(~(1<<US_POS));  //Low
  //Now make the oin input
  US_DDR&=(~(1<<US_POS));
  //Measure the width of pulse
  r=getPulseWidth();
  int d;
  d=(int)(r/58.0);
  c1 = c2;
  c2 = c3;
  c3 = c4;
  c4 = c5;
  c5 = d;
  if((c1>=c2) && (c1>=c3) && (c1>=c4) && (c1>=c5)) {maxNum = c1;}
  if((c2>=c1) && (c2>=c3) && (c2>=c4) && (c2>=c5)) {maxNum = c2;}
  if((c3>=c1) && (c3>=c2) && (c3>=c4) && (c3>=c5)) {maxNum = c3;}
  if((c4>=c1) && (c4>=c2) && (c4>=c3) && (c4>=c5)) {maxNum = c4;}
  if((c5>=c1) && (c5>=c2) && (c5>=c3) && (c5>=c4)) {maxNum = c5;}
  if((c1<=c2) && (c1<=c3) && (c1<=c4) && (c1<=c5)) {minNum = c1;}
  if((c2<=c1) && (c2<=c3) && (c2<=c4) && (c2<=c5)) {minNum = c2;}
  if((c3<=c1) && (c3<=c2) && (c3<=c4) && (c3<=c5)) {minNum = c3;}
  if((c4<=c1) && (c4<=c2) && (c4<=c3) && (c4<=c5)) {minNum = c4;}
  if((c5<=c1) && (c5<=c2) && (c5<=c3) && (c5<=c4)) {minNum = c5;}
  avg = (c1 + c2 + c3 + c4 + c5 - maxNum - minNum) / 3;
  //Handle Errors
  if(r==US_ERROR)
  {
        DEBUG_LOG(DBG_WKPFUPDATE, "Ultrasound Sensor Error!");
  }
  else if(r==US_NO_OBSTACLE)
  {
        DEBUG_LOG(DBG_WKPFUPDATE, "Ultrasound Sensor Clear!");
  }
  else
  {
  DEBUG_LOG(DBG_WKPFUPDATE, "WKPFUPDATE(UltrasoundSensor): Sensed distance value: %d cm\n", avg);
  wkpf_internal_write_property_int16(wuobject, WKPF_PROPERTY_ULTRASOUND_SENSOR_SIGNAL, avg);
  }
}

