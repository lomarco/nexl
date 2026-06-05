#pragma once

#include <stdint.h>

typedef void *efi_handle_t;
typedef uint64_t efi_status_t;
typedef uint64_t efi_uint_t;
typedef char16_t efi_char16_t;
typedef void *efi_event_t;


typedef struct {
  uint64_t signature;
  uint32_t revision;
  uint32_t headerSize;
  uint32_t crc32;
  uint32_t reserved;
} efi_table_header;
typedef struct {
  efi_table_header Hdr;
  char16_t *FirmwareVendor;
  uint32_t FirmwareRevision;
  efi_handle_t ConsoleInHandle;
  efi_simple_text_input_protocol *ConIn;
  efi_handle_t ConsoleOutHandle;
  efi_simple_text_output_protocol *ConOut;
  efi_handle_t StandardErrorHandle;
  efi_simple_text_output_protocol *StdErr;
  EFI_RUNTIME_SERVICES *RuntimeServices;
  EFI_BOOT_SERVICES *BootServices;
  UINTN NumberOfTableEntries;
  EFI_CONFIGURATION_TABLE *ConfigurationTable;
} efi_system_table;
