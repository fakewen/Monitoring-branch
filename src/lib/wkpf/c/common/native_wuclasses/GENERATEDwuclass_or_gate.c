
          #include "native_wuclasses.h"
          #include "native_wuclasses_privatedatatypes.h"

          extern void wuclass_or_gate_setup(wuobject_t *wuobject);
          extern void wuclass_or_gate_update(wuobject_t *wuobject);

          
          wuclass_t wuclass_or_gate = {
            WKPF_WUCLASS_OR_GATE,
            wuclass_or_gate_setup,
            wuclass_or_gate_update,
            3,
            sizeof(bool),
            0, // Initialise flags to 0, possibly set WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE from native_wuclasses_init
            NULL,
            {
            WKPF_PROPERTY_TYPE_BOOLEAN+WKPF_PROPERTY_ACCESS_WRITEONLY,
WKPF_PROPERTY_TYPE_BOOLEAN+WKPF_PROPERTY_ACCESS_WRITEONLY,
WKPF_PROPERTY_TYPE_BOOLEAN+WKPF_PROPERTY_ACCESS_READONLY

            }
          };
          
              bool *wuclass_or_gate_getPrivateData(wuobject_t *wuobject) {
                return (bool *)wkpf_get_private_wuobject_data(wuobject);
              }
            