#define RUN_TEST_1  
#ifdef RUN_TEST_1

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "cmd_line.h"

int32_t test_func(uint8_t* argv) {
    printf("Chay ham test thanh cong! Tham so: %s\n", argv);
    return (int32_t)CMD_SUCCESS;
}

cmd_line_t my_table[] = {
    {(const int8_t*)"help", test_func, (const int8_t*)"Huong dan su dung"},
    {(const int8_t*)"test", test_func, (const int8_t*)"Lenh kiem tra"},
    {NULL, NULL, NULL} // Dòng NULL b?t bu?c d? k?t thúc b?ng
};

int main() {
    printf("--- Bat dau Unit Test ---\n");

    // Test truong hop dung
    uint8_t cmd1[] = "help"; 
    printf("Dang test lenh: %s\n", cmd1);
    uint8_t result1 = cmd_line_parser(my_table, cmd1); 
    
    if (result1 == CMD_SUCCESS) printf("=> PASS\n\n");
    else printf("=> FAIL (Ma loi: %d)\n\n", result1);

    // Test truong hop sai
    uint8_t cmd2[] = "sontungMTP";
    printf("Dang test lenh sai: %s\n", cmd2);
    uint8_t result2 = cmd_line_parser(my_table, cmd2);

    if (result2 == CMD_NOT_FOUND) printf("=> PASS: Da nhan dien dung lenh khong ton tai\n");
    else printf("=> FAIL: le ra phai bao NOT FOUND\n");

    return 0;
}
#endif
