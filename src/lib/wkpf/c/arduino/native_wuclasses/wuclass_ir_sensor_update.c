#include "debug.h"

#include "../../common/native_wuclasses/native_wuclasses.h"

#include <avr/io.h>

#include "../../common/native_wuclasses/GENERATEDwuclass_pir_sensor.h"

#include <math.h>

#define set_input(portdir, pin) portdir &= ~(1<<pin)

#define output_high(port, pin) port |= (1<<pin)

#define input_get(port, pin) ((port & (1 << pin)) != 0)

void wuclass_ir_sensor_setup(wuobject_t *wuobject) {

 DEBUG_LOG(DBG_WKPFUPDATE, "WKPFUPDATE(IrSensor): setup\n");

}

void wuclass_ir_sensor_update(wuobject_t *wuobject) {

 //enable ADC and set prescaler value

 ADCSRA = _BV(ADEN) | _BV(ADPS2);

 //ADCSRA = _BV(ADEN) | (6 & 7); // set prescaler value

 //set ADC channel, reference value and left shift

 uint8_t channel = 0;

 //ADMUX = (channel & 0x0f) | 0xc0 | _BV(ADLAR);

 ADMUX = (channel & 0x0f) | 0xc0;

 //ADMUX = (ADMUX & 0xc0) | _BV(ADLAR) | (channel & 0x0f);

 //ADCSRB |= (channel & 0x20)>>2;

 //do conversion

 ADCSRA |= _BV(ADSC);

 //wait for conversion complete

 while(!(ADCSRA & _BV(ADIF)));

 //clear ADIF

 ADCSRA &= ~(_BV(ADIF));

 //uint16_t cm = 0;

 uint16_t sensorValue = ADCL;

 sensorValue += (ADCH << 8);

 sensorValue /= 2;

 //float volts = sensorValue * 0.0048828125;

 //uint16_t distance = 65 * pow(volts, -1.10);

 float volts = 10650.08 * pow(sensorValue, -0.935);

 uint16_t distance = (uint16_t)(volts - 10);

 //cm = (uint16_t)pow(sensorValue, 1);

 DEBUG_LOG(DBG_WKPFUPDATE, "WKPFUPDATE(irSensor): Sensed ir value: %d, ADC: %d\n",distance, sensorValue);

 wkpf_internal_write_property_int16(wuobject, WKPF_PROPERTY_IR_SENSOR_SIGNAL, distance);

}
