
          #include "native_wuclasses.h"
          #include "native_wuclasses_privatedatatypes.h"

          extern void wuclass_condition_selector_boolean_setup(wuobject_t *wuobject);
          extern void wuclass_condition_selector_boolean_update(wuobject_t *wuobject);

          
          wuclass_t wuclass_condition_selector_boolean = {
            WKPF_WUCLASS_CONDITION_SELECTOR_BOOLEAN,
            wuclass_condition_selector_boolean_setup,
            wuclass_condition_selector_boolean_update,
            4,
            0,
            0, // Initialise flags to 0, possibly set WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE from native_wuclasses_init
            NULL,
            {
            WKPF_PROPERTY_TYPE_BOOLEAN+WKPF_PROPERTY_ACCESS_WRITEONLY,
WKPF_PROPERTY_TYPE_BOOLEAN+WKPF_PROPERTY_ACCESS_READWRITE,
WKPF_PROPERTY_TYPE_BOOLEAN+WKPF_PROPERTY_ACCESS_READONLY,
WKPF_PROPERTY_TYPE_BOOLEAN+WKPF_PROPERTY_ACCESS_READONLY

            }
          };
          