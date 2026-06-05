#pragma once

#include <stdint.h>

typedef void *efi_handle_t;
typedef uint64_t efi_status_t;
typedef uint64_t efi_uint_t;
typedef char16_t efi_char16_t;
typedef void *efi_event_t;

typedef union efi_simple_text_input_protocol efi_simple_text_input_protocol_t; // TODO: Impl it into driver/ dir
typedef union efi_simple_text_output_protocol efi_simple_text_output_protocol_t;
typedef union efi_boot_services efi_boot_services_t;

typedef struct {
  uint64_t signature;
  uint32_t revision;
  uint32_t headerSize;
  uint32_t crc32;
  uint32_t reserved;
} efi_table_header;

typedef struct {
	efi_table_header hdr;
	uint32_t get_time;
	uint32_t set_time;
	uint32_t get_wakeup_time;
	uint32_t set_wakeup_time;
	uint32_t set_virtual_address_map;
	uint32_t convert_pointer;
	uint32_t get_variable;
	uint32_t get_next_variable;
	uint32_t set_variable;
	uint32_t get_next_high_mono_count;
	uint32_t reset_system;
	uint32_t update_capsule;
	uint32_t query_capsule_caps;
	uint32_t query_variable_info;
} efi_runtime_services_t;

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
  efi_runtime_services_t *RuntimeServices;
  efi_boot_services *BootServices;
  UINTN NumberOfTableEntries;
  EFI_CONFIGURATION_TABLE *ConfigurationTable;
} efi_system_table;
