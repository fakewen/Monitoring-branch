#include <debug.h>
#include <string.h>
#include "wkcomm.h"
#include "wkpf_wuclasses.h"
#include "../common/native_wuclasses/native_wuclasses.h"
#include "../common/native_wuclasses/GENERATEDwuclass_or_gate.h"
#include "../common/native_wuclasses/GENERATEDwuclass_led.h"
#include "../common/native_wuclasses/GENERATEDwuclass_pir_sensor.h"
#include "../common/native_wuclasses/GENERATEDwuclass_ir_sensor.h"
#include "../common/native_wuclasses/GENERATEDwuclass_ultrasound_sensor.h"
#include "../common/native_wuclasses/GENERATEDwuclass_magnetic_sensor.h"

        wuclass_t* wkpf_process_enabled_wuclasses_xml_register_class(char* wuclassname, bool appCanCreateInstances) {
            printf("[posix init] Registering wuclass %s", wuclassname);
        
            if (!strcmp(wuclassname, "Or_Gate")) {
                wkpf_register_wuclass(&wuclass_or_gate);
                if (appCanCreateInstances)
                    wuclass_or_gate.flags |= WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE;
                return &wuclass_or_gate;
            }
            
            if (!strcmp(wuclassname, "LED")) {
                wkpf_register_wuclass(&wuclass_led);
                if (appCanCreateInstances)
                    wuclass_led.flags |= WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE;
                return &wuclass_led;
            }
            
            if (!strcmp(wuclassname, "PIR_Sensor")) {
                wkpf_register_wuclass(&wuclass_pir_sensor);
                if (appCanCreateInstances)
                    wuclass_pir_sensor.flags |= WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE;
                return &wuclass_pir_sensor;
            }
            
            if (!strcmp(wuclassname, "IR_Sensor")) {
                wkpf_register_wuclass(&wuclass_ir_sensor);
                if (appCanCreateInstances)
                    wuclass_ir_sensor.flags |= WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE;
                return &wuclass_ir_sensor;
            }
            
            if (!strcmp(wuclassname, "Ultrasound_Sensor")) {
                wkpf_register_wuclass(&wuclass_ultrasound_sensor);
                if (appCanCreateInstances)
                    wuclass_ultrasound_sensor.flags |= WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE;
                return &wuclass_ultrasound_sensor;
            }
            
            if (!strcmp(wuclassname, "Magnetic_Sensor")) {
                wkpf_register_wuclass(&wuclass_magnetic_sensor);
                if (appCanCreateInstances)
                    wuclass_magnetic_sensor.flags |= WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE;
                return &wuclass_magnetic_sensor;
            }
            
            printf("Unknown wuclass %s\n", wuclassname);
            return NULL;
        }