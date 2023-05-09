#include <stdio.h>
#include <stdbool.h>
#include "romfuncs.h"

ssize_t _write(int fd, const void * data, size_t size)
{
    (void)fd;
    const char* cdata = (const char*) data;
    for (size_t i = 0; i < size; ++i) {
        if (cdata[i] == '\n')
        {
            uart_tx_one_char('\r');
        }
        uart_tx_one_char(cdata[i]);
    }
    return size;
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
