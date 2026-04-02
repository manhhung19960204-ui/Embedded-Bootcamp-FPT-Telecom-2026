//#define RUN_TEST_1  
#ifdef RUN_TEST_1

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "cmd_line.h" // Luôn ph?i include file header này

int32_t cmd_led_on(uint8_t* argv) {
	printf("[DEVICE]: Da bat den LED THANH CONG!\n");
	return(int32_t)CMD_SUCCESS;
}

int32_t cmd_get_version(uint8_t* argv) {
    printf("[DEVICE]: Phien ban phan mem VER 1 NAM 2026\n");
    return (int32_t)CMD_SUCCESS;
}

cmd_line_t my_table[] = {
    {(const int8_t*)"led_on",  cmd_led_on, (const int8_t*)"Bat den LED tren kit"},
    {(const int8_t*)"version", cmd_get_version, (const int8_t*)"Hien thi version cu a firmware"},
    {NULL, NULL, NULL} 
};

int main() {
	uint8_t input[20];
	
	printf("--- CHUONG TRINH DIEU KHIEN THIET BI ---\n");
	
	strcpy((char*)input, "led_on");
    printf("User nhap: %s\n", input);
    cmd_line_parser(my_table, input); 
    
    strcpy((char*)input, "version");
    printf("\nUser Nhap: %s\n", input);
    cmd_line_parser(my_table, input);    
}
#endif
