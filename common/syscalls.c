#include <stdio.h>
#include <stdbool.h>
#include "romfuncs.h"

ssize_t _write(int fildes, const void *buf, size_t nbyte)
{
    (void)fildes;
    const uint8_t *cbuf = (const uint8_t *) buf;
    for (size_t i = 0; i < nbyte; ++i) {
        uart_tx_one_char(cbuf[i]);
    }
    return nbyte;
}

void _exit(int exit_code)
{
    while (true) {
        ;
    }
}

void syscalls_init(void)
{
}
