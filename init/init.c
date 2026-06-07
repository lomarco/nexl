#include <nexl/efi.h>

efi_status_t __efiapi EfiMain(efi_handle_t handle, efi_system_table *system_table) {
  u16 msg[] = u"Hello";
  efi_status_t status;
  status = system_table->out->clear_screen(system_table->out);
  if (status != 0)
    return status;
  status = system_table->out->output_string(system_table->out, msg);
  if (status != 0)
    return status;
  return 0;
}
