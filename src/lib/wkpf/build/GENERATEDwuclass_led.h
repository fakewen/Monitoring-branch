
          #include "native_wuclasses.h"
          #include "native_wuclasses_privatedatatypes.h"

          #ifndef WUCLASS_LEDH
          #define WUCLASS_LEDH

          extern wuclass_t wuclass_led;

          extern bool *wuclass_led_getPrivateData(wuobject_t *wuobject);

          #endif
          