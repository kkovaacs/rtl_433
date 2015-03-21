#include "rtl_433.h"

static int dooya_callback(uint8_t bb[BITBUF_ROWS][BITBUF_COLS], int16_t bits_per_row[BITBUF_ROWS]) {
  if (debug_output)
    debug_callback(bb, bits_per_row);

  if (bb[0][0] == 0x0E && bb[1][0] == 0x0E && bb[2][0] == 0x0E &&
      bb[0][1] == 0xFF && bb[1][1] == 0xFF && bb[2][1] == 0xFF &&
      bb[0][2] == 0xFA && bb[1][2] == 0xFA && bb[2][2] == 0xFA &&
      bb[0][3] == 0x8E && bb[1][3] == 0x8E && bb[2][3] == 0x8E) {
    fprintf(stderr, "found\n");
    return 1;
  }
  return 0;
}

r_device dooya = {
    /* .id             = */ 18,
    /* .name           = */ "Dooya remote control v1.6",
    /* .modulation     = */ OOK_PWM_P,
    /* .short_limit    = */ 150,
    /* .long_limit     = */ 500,
    /* .reset_limit    = */ 5000,
    /* .json_callback  = */ &dooya_callback,
};
