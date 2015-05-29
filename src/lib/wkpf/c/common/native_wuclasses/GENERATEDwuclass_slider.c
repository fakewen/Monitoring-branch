
          #include "native_wuclasses.h"
          #include "native_wuclasses_privatedatatypes.h"

          extern void wuclass_slider_setup(wuobject_t *wuobject);
          extern void wuclass_slider_update(wuobject_t *wuobject);

          
          wuclass_t wuclass_slider = {
            WKPF_WUCLASS_SLIDER,
            wuclass_slider_setup,
            wuclass_slider_update,
            4,
            0,
            0, // Initialise flags to 0, possibly set WKPF_WUCLASS_FLAG_APP_CAN_CREATE_INSTANCE from native_wuclasses_init
            NULL,
            {
            WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READWRITE,
WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READWRITE,
WKPF_PROPERTY_TYPE_SHORT+WKPF_PROPERTY_ACCESS_READWRITE,
WKPF_PROPERTY_TYPE_REFRESH_RATE+WKPF_PROPERTY_ACCESS_READWRITE

            }
          };
          