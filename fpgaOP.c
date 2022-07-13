#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> /* for flags such as read only, blocking */
#include <stdlib.h> /* stuff like malloc, rand, etc. */
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include "dma_utils.c"

int main() {
    uint64_t base_size = 65536;
    uint64_t size;
    int multiplicator = 4;
    char *to_dev_name = "/dev/xdma0_h2c_0"; /* device name for transferring from host to card */
    char *from_dev_name = "/dev/xdma0_c2h_0";  /* device name for transferring from card to end */
    char *write_allocated = NULL;
    char *read_allocated = NULL;
    uint64_t a, b, sel, res;
    int fpga_write = open(to_dev_name, O_RDWR);
    int fpga_read = open(from_dev_name, O_RDWR);
    
  /*******Operation to perform*******/
    switch(sel) {
        case 0:
            res = a + b;
        case 1:
            res = a - b;
        case 2:
            res = a * b;
        case 3:
            res = a / b;
        default:
            fprintf(stderr, "Error\n");
            return -1;
    }
    /***** program the FPGA *****/
    uint64_t* buf_a = &a;
    uint64_t* buf_b = &b;
    uint64_t* buf_res = &res;
    uint64_t* buf_sel = &sel;
    uint64_t address = 0x40000000;
    fprintf(stdout, "Writing a\n");
    write_from_buffer(to_dev_name, fpga_write, (char*)buf_a, (uint64_t)sizeof(uint64_t*), address); /* write to the file from the buffer */
    uint64_t address = 0x40010000;
    fprintf(stdout, "Writing b\n");
    write_from_buffer(to_dev_name, fpga_write, (char*)buf_b, (uint64_t)sizeof(uint64_t*), address);
    uint64_t address = 0x40020000;
    fprintf(stdout, "Writing sel\n");
    write_from_buffer(to_dev_name, fpga_write, (char*)buf_sel, (uint64_t)sizeof(uint64_t*), address);
    uint64_t address = 0x40030000;
    fprintf(stdout, "Writing res\n");
    write_from_buffer(to_dev_name, fpga_write, (char*)buf_res, (uint64_t)sizeof(uint64_t*), address);
    close(fpga_write);
    close(fpga_read);
    return 0;
}
