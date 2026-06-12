#pragma once

#include <nexl/types.h>

#define __efiapi __attribute__((ms_abi))

typedef void *efi_handle_t;
typedef u64 efi_status_t;
typedef u64 efi_uint_t;
typedef u16 efi_char16_t;
typedef void *efi_event_t;
typedef u64 efi_physical_addr_t;

typedef struct efi_simple_text_input_protocol efi_simple_text_input_protocol_t; // TODO: Impl it into driver/ dir
typedef struct efi_simple_text_output_protocol efi_simple_text_output_protocol_t; // TODO: Impl it into driver/ dir
typedef struct efi_boot_services efi_boot_services_t; // TODO: Impl it into driver/ dir

typedef struct {
  u64 signature;
  u32 revision;
  u32 headerSize;
  u32 crc32;
  u32 reserved;
} efi_table_header;

typedef struct {
  efi_table_header hdr;
  u32 get_time;
  u32 set_time;
  u32 get_wakeup_time;
  u32 set_wakeup_time;
  u32 set_virtual_address_map;
  u32 convert_pointer;
  u32 get_variable;
  u32 get_next_variable;
  u32 set_variable;
  u32 get_next_high_mono_count;
  u32 reset_system;
  u32 update_capsule;
  u32 query_capsule_caps;
  u32 query_variable_info;
} efi_runtime_services_t;

typedef struct {
  u32 Data1;
  u16 Data2;
  u16 Data3;
  u8 Data4[8];
} efi_guid_t;

typedef struct {
  efi_guid_t VendorGuid;
  void *VendorTable;
} efi_configuration_table;

typedef struct {
  efi_table_header Hdr;
  u16 *FirmwareVendor;
  u32 FirmwareRevision;
  efi_handle_t ConsoleInHandle;
  efi_simple_text_input_protocol_t *ConIn;
  efi_handle_t ConsoleOutHandle;
  efi_simple_text_output_protocol_t *ConOut;
  efi_handle_t StandardErrorHandle;
  efi_simple_text_output_protocol_t *StdErr;
  efi_runtime_services_t *RuntimeServices;
  efi_boot_services_t *BootServices;
  unsigned long NumberOfTableEntries;
  efi_configuration_table *ConfigurationTable;
} efi_system_table;
