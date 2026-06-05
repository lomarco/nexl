#pragma once

#include <stdint.h>



typedef struct {
  uint64_t signature;
  uint32_t revision;
  uint32_t headerSize;
  uint32_t crc32;
  uint32_t reserved;
} efi_table_header;
