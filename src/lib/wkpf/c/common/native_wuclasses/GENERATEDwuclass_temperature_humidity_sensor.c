
          #include "native_wuclasses.h"
          #include "native_wuclasses_privatedatatypes.h"

          extern void wuclass_temperature_humidity_sensor_setup(wuobject_t *wuobject);
          extern void wuclass_temperature_humidity_sensor_update(wuobject_t *wuobject);

          
          wuclass_t wuclass_temperature_humidity_sensor = {
            WKPF_WUCLASS_TEMPERATURE_HUMIDITY_SENSOR,
            wuclass_temperature_humidity_sensor_setup,
            wuclass_temperature_humidity_sensor_update,
            3,
            0,
            0, // Initialise flags to 0, possibly set WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE from native_wuclasses_init
            NULL,
            {
            WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READONLY,
WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READONLY,
WKPF_PROPERTY_TYPE_REFRESH_RATE+WKPF_PROPERTY_ACCESS_READWRITE

            }
          };
          