#include <debug.h>
#include <string.h>
#include "wkcomm.h"
#include "wkpf_wuclasses.h"
#include "wkpf_properties.h"
#include "native_wuclasses.h"
#include "GENERATEDwuclass_or_gate.h"
#include "GENERATEDwuclass_led.h"
#include "GENERATEDwuclass_pir_sensor.h"
#include "GENERATEDwuclass_ir_sensor.h"
#include "GENERATEDwuclass_ultrasound_sensor.h"
#include "GENERATEDwuclass_magnetic_sensor.h"

        uint8_t wkpf_native_wuclasses_init() {
          uint8_t retval = WKPF_OK;
          wuobject_t *wuobject;
          wuobject = NULL;
          DEBUG_LOG(DBG_WKPF, "WKPF: (INIT) Running wkpf native init for node id: %x\n", wkcomm_get_node_id());
        
                        wkpf_register_wuclass(&wuclass_or_gate);
                        wuclass_or_gate.flags |= WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE;
                        wkpf_register_wuclass(&wuclass_led);
                        retval = wkpf_create_wuobject(wuclass_led.wuclass_id, 1, 0, true);
                        if (retval != WKPF_OK)
                            return retval;
                        wkpf_get_wuobject_by_port(1, &wuobject);
                        wuclass_led.setup(wuobject);
                        
                        wkpf_register_wuclass(&wuclass_pir_sensor);
                        retval = wkpf_create_wuobject(wuclass_pir_sensor.wuclass_id, 2, 0, true);
                        if (retval != WKPF_OK)
                            return retval;
                        wkpf_get_wuobject_by_port(2, &wuobject);
                        wuclass_pir_sensor.setup(wuobject);
                        
                        wkpf_register_wuclass(&wuclass_ir_sensor);
                        retval = wkpf_create_wuobject(wuclass_ir_sensor.wuclass_id, 3, 0, true);
                        if (retval != WKPF_OK)
                            return retval;
                        wkpf_get_wuobject_by_port(3, &wuobject);
                        wuclass_ir_sensor.setup(wuobject);
                        
                        wkpf_register_wuclass(&wuclass_ultrasound_sensor);
                        retval = wkpf_create_wuobject(wuclass_ultrasound_sensor.wuclass_id, 4, 0, true);
                        if (retval != WKPF_OK)
                            return retval;
                        wkpf_get_wuobject_by_port(4, &wuobject);
                        wuclass_ultrasound_sensor.setup(wuobject);
                        
                        wkpf_register_wuclass(&wuclass_magnetic_sensor);
                        retval = wkpf_create_wuobject(wuclass_magnetic_sensor.wuclass_id, 5, 0, true);
                        if (retval != WKPF_OK)
                            return retval;
                        wkpf_get_wuobject_by_port(5, &wuobject);
                        retval = wkpf_internal_write_property_int16(wuobject, WKPF_PROPERTY_MAGNETIC_SENSOR___PIN, WKPF_ENUM_PIN_PIN1);
                        if (retval != WKPF_OK)
                            return retval;
                        wuclass_magnetic_sensor.setup(wuobject);
                        
                        retval = wkpf_create_wuobject(wuclass_magnetic_sensor.wuclass_id, 6, 0, true);
                        if (retval != WKPF_OK)
                            return retval;
                        wkpf_get_wuobject_by_port(6, &wuobject);
                        retval = wkpf_internal_write_property_int16(wuobject, WKPF_PROPERTY_MAGNETIC_SENSOR___PIN, WKPF_ENUM_PIN_PIN2);
                        if (retval != WKPF_OK)
                            return retval;
                        wuclass_magnetic_sensor.setup(wuobject);
                        
            return retval;
        }