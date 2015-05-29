
          #include "native_wuclasses.h"
          #include "native_wuclasses_privatedatatypes.h"

          extern void wuclass_server_setup(wuobject_t *wuobject);
          extern void wuclass_server_update(wuobject_t *wuobject);

          
          wuclass_t wuclass_server = {
            WKPF_WUCLASS_SERVER,
            wuclass_server_setup,
            wuclass_server_update,
            1,
            0,
            0, // Initialise flags to 0, possibly set WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE from native_wuclasses_init
            NULL,
            {
            WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READWRITE

            }
          };
          