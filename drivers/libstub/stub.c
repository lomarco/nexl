#include "efistub.h"

efi_status_t __efiapi EfiMain(efi_handle_t handle, efi_system_table *system_table) {
  u16 msg[] = u"Hello";
  efi_status_t status;
  status = system_table->ConOut->clear_screen(system_table->ConOut);
  if (status != 0)
    return status;
  status = system_table->ConOut->output_string(system_table->ConOut, msg);
  if (status != 0)
    return status;
  return 0;
}
