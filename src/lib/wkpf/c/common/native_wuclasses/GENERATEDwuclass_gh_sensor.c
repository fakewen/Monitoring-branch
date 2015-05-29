
          #include "native_wuclasses.h"
          #include "native_wuclasses_privatedatatypes.h"

          extern void wuclass_gh_sensor_setup(wuobject_t *wuobject);
          extern void wuclass_gh_sensor_update(wuobject_t *wuobject);

          
          wuclass_t wuclass_gh_sensor = {
            WKPF_WUCLASS_GH_SENSOR,
            wuclass_gh_sensor_setup,
            wuclass_gh_sensor_update,
            2,
            sizeof(bool),
            0, // Initialise flags to 0, possibly set WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE from native_wuclasses_init
            NULL,
            {
            WKPF_PROPERTY_TYPE_BOOLEAN+WKPF_PROPERTY_ACCESS_READWRITE,
WKPF_PROPERTY_TYPE_REFRESH_RATE+WKPF_PROPERTY_ACCESS_READWRITE

            }
          };
          
              bool *wuclass_gh_sensor_getPrivateData(wuobject_t *wuobject) {
                return (bool *)wkpf_get_private_wuobject_data(wuobject);
              }
            