#pragma once

#include <nexl/efi.h>

typedef void(__efiapi *efi_event_notify_t)(efi_event_t, void *);

typedef struct efi_generic_dev_path efi_device_path_protocol_t;

typedef enum {
  EfiTimerCancel,
  EfiTimerPeriodic,
  EfiTimerRelative
} EFI_TIMER_DELAY;

typedef struct {
  u16 scan_code;
  efi_char16_t unicode_char;
} efi_input_key_t;

struct efi_simple_text_input_protocol {
  void *reset;
  efi_status_t(__efiapi *read_keystroke)(efi_simple_text_input_protocol_t *,
                                         efi_input_key_t *);
  efi_event_t wait_for_key;
};

typedef struct {
  s32 maxmode;
  s32 mode;
  s32 attribute;
  s32 cursorcolumn;
  s32 cursorrow;
  boolean cursorvisible;
} simple_text_output_mode;

struct efi_simple_text_output_protocol {
  efi_status_t (__efiapi *efi_text_reset)(efi_simple_text_output_protocol_t *, boolean extver);
  efi_status_t (__efiapi *efi_text_string)(efi_simple_text_output_protocol_t *, u16 *str);
  efi_status_t (__efiapi *efi_text_test_string)(efi_simple_text_output_protocol_t *, u16 *str);
  efi_status_t (__efiapi *efi_text_query_mode)(efi_simple_text_output_protocol_t *, u64 modenum, u64 *col, u64 *rows);
  efi_status_t (*__efiapi efi_text_set_mode)(efi_simple_text_output_protocol_t *, u64 modenum);
  efi_status_t (__efiapi *efi_text_set_attribute)(efi_simple_text_output_protocol_t *, u64 attr);
  efi_status_t (__efiapi *efi_text_clear_screen)(efi_simple_text_output_protocol_t *);
  efi_status_t (__efiapi *efi_text_set_cursor_pos)(efi_simple_text_output_protocol_t *, u64 col, u64 row);
  efi_status_t (__efiapi *efi_text_enable_cur)(efi_simple_text_output_protocol_t *, boolean);
  simple_text_output_mode *mode;
};

struct efi_boot_services {
  efi_table_header hdr;
  void *raise_tpl;
  void *restore_tpl;
  efi_status_t(__efiapi *allocate_pages)(int, int, unsigned long,
                                         efi_physical_addr_t *);
  efi_status_t(__efiapi *free_pages)(efi_physical_addr_t, unsigned long);
  efi_status_t(__efiapi *get_memory_map)(unsigned long *, void *,
                                         unsigned long *, unsigned long *,
                                         u32 *);
  efi_status_t(__efiapi *allocate_pool)(int, unsigned long, void **);
  efi_status_t(__efiapi *free_pool)(void *);
  efi_status_t(__efiapi *create_event)(u32, unsigned long, efi_event_notify_t,
                                       void *, efi_event_t *);
  efi_status_t(__efiapi *set_timer)(efi_event_t, EFI_TIMER_DELAY, u64);
  efi_status_t(__efiapi *wait_for_event)(unsigned long, efi_event_t *,
                                         unsigned long *);
  void *signal_event;
  efi_status_t(__efiapi *close_event)(efi_event_t);
  void *check_event;
  void *install_protocol_interface;
  void *reinstall_protocol_interface;
  void *uninstall_protocol_interface;
  efi_status_t(__efiapi *handle_protocol)(efi_handle_t, efi_guid_t *, void **);
  void *__reserved;
  void *register_protocol_notify;
  efi_status_t(__efiapi *locate_handle)(int, efi_guid_t *, void *,
                                        unsigned long *, efi_handle_t *);
  efi_status_t(__efiapi *locate_device_path)(efi_guid_t *,
                                             efi_device_path_protocol_t **,
                                             efi_handle_t *);
  efi_status_t(__efiapi *install_configuration_table)(efi_guid_t *, void *);
  efi_status_t(__efiapi *load_image)(bool, efi_handle_t,
                                     efi_device_path_protocol_t *, void *,
                                     unsigned long, efi_handle_t *);
  efi_status_t(__efiapi *start_image)(efi_handle_t, unsigned long *,
                                      efi_char16_t **);
  efi_status_t(__efiapi *exit)(efi_handle_t, efi_status_t, unsigned long,
                               efi_char16_t *);
  efi_status_t(__efiapi *unload_image)(efi_handle_t);
  efi_status_t(__efiapi *exit_boot_services)(efi_handle_t, unsigned long);
  void *get_next_monotonic_count;
  efi_status_t(__efiapi *stall)(unsigned long);
  void *set_watchdog_timer;
  void *connect_controller;
  efi_status_t(__efiapi *disconnect_controller)(efi_handle_t, efi_handle_t,
                                                efi_handle_t);
  void *open_protocol;
  void *close_protocol;
  void *open_protocol_information;
  void *protocols_per_handle;
  efi_status_t(__efiapi *locate_handle_buffer)(int, efi_guid_t *, void *,
                                               unsigned long *,
                                               efi_handle_t **);
  efi_status_t(__efiapi *locate_protocol)(efi_guid_t *, void *, void **);
  efi_status_t(__efiapi *install_multiple_protocol_interfaces)(efi_handle_t *,
                                                               ...);
  efi_status_t(__efiapi *uninstall_multiple_protocol_interfaces)(efi_handle_t,
                                                                 ...);
  void *calculate_crc32;
  void(__efiapi *copy_mem)(void *, const void *, unsigned long);
  void(__efiapi *set_mem)(void *, unsigned long, unsigned char);
  void *create_event_ex;
};
