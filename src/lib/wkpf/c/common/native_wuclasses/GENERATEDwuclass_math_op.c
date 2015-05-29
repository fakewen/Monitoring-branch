
          #include "native_wuclasses.h"
          #include "native_wuclasses_privatedatatypes.h"

          extern void wuclass_math_op_setup(wuobject_t *wuobject);
          extern void wuclass_math_op_update(wuobject_t *wuobject);

          
          wuclass_t wuclass_math_op = {
            WKPF_WUCLASS_MATH_OP,
            wuclass_math_op_setup,
            wuclass_math_op_update,
            5,
            0,
            0, // Initialise flags to 0, possibly set WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE from native_wuclasses_init
            NULL,
            {
            WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_WRITEONLY,
WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_WRITEONLY,
WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READWRITE,
WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READONLY,
WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READONLY

            }
          };
          