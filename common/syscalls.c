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

/* Non-blocking implementation
ssize_t _read(int fd, void * data, size_t size)
{
    (void)fd;
    char* cdata = (char*) data;
    size_t received;
    for (received = 0; received < size; ++received) {
        int status = uart_rx_one_char((uint8_t*) &cdata[received]);
        if (status != 0) {
            break;
        }
    }
    if (received == 0) {
        errno = EWOULDBLOCK;
        return -1;
    }
    return received;
}
*/

/* Blocking implementation */
ssize_t _read(int fd, void * data, size_t size)
{
    (void)fd;
    char* cdata = (char*) data;
    size_t received;
    for (received = 0; received < size; ++received) {
        int status = uart_rx_one_char((uint8_t*) &cdata[received]);
        if (status != 0) {
            if (received != 0) break;
            else --received;
        }
    }
    return received;
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
