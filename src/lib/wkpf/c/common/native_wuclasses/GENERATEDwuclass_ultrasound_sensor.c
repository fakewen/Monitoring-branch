
          #include "native_wuclasses.h"
          #include "native_wuclasses_privatedatatypes.h"

          extern void wuclass_ultrasound_sensor_setup(wuobject_t *wuobject);
          extern void wuclass_ultrasound_sensor_update(wuobject_t *wuobject);

          
          wuclass_t wuclass_ultrasound_sensor = {
            WKPF_WUCLASS_ULTRASOUND_SENSOR,
            wuclass_ultrasound_sensor_setup,
            wuclass_ultrasound_sensor_update,
            2,
            0,
            0, // Initialise flags to 0, possibly set WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE from native_wuclasses_init
            NULL,
            {
            WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READONLY,
WKPF_PROPERTY_TYPE_REFRESH_RATE+WKPF_PROPERTY_ACCESS_READWRITE

            }
          };
          