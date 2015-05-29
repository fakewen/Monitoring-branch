#include "types.h"
#include "jlib_base.h"
#include "jlib_darjeeling3.h"
#include "jlib_wkpf_virtual.h"

dj_named_native_handler java_library_native_handlers[] = {
	{ "base", &base_native_handler },
	{ "darjeeling3", &darjeeling3_native_handler },
	{ "wkpf_virtual", &wkpf_virtual_native_handler },
};
uint8_t java_library_native_handlers_length = 3;

extern void vm_init();
extern void base_init();
extern void darjeeling3_init();
extern void uart_init();
extern void wkcomm_init();
extern void wkreprog_init();
extern void wkpf_init();
extern void wkpf_virtual_init();
void dj_libraries_init() {
	vm_init();
	base_init();
	darjeeling3_init();
	uart_init();
	wkcomm_init();
	wkreprog_init();
	wkpf_init();
	wkpf_virtual_init();
}
