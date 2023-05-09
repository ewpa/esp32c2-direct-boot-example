/* ROM function interface esp32c3.rom.libgcc.ld for esp32c3
 *
 *
 * Generated from ./interface-esp32c3.yml md5sum 93b28a9e1fe42d212018eb4336849208
 *
 * Compatible with ROM where ECO version equal or greater to 0.
 */

#pragma once

extern int uart_tx_one_char(unsigned char c);
extern unsigned char uart_rx_one_char(unsigned char *ch);
