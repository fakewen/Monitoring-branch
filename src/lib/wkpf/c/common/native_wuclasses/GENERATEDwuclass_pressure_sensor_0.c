
          #include "native_wuclasses.h"
          #include "native_wuclasses_privatedatatypes.h"

          extern void wuclass_pressure_sensor_0_setup(wuobject_t *wuobject);
          extern void wuclass_pressure_sensor_0_update(wuobject_t *wuobject);

          
          wuclass_t wuclass_pressure_sensor_0 = {
            WKPF_WUCLASS_PRESSURE_SENSOR_0,
            wuclass_pressure_sensor_0_setup,
            wuclass_pressure_sensor_0_update,
            4,
            0,
            0, // Initialise flags to 0, possibly set WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE from native_wuclasses_init
            NULL,
            {
            WKPF_PROPERTY_TYPE_REFRESH_RATE+WKPF_PROPERTY_ACCESS_READWRITE,
WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READWRITE,
WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READWRITE,
WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READWRITE

            }
          };
          