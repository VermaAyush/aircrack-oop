#include "pch.h"

u_int16_t printHex(u_int8_t * data, long unsigned int len){
    long unsigned int cnt=0;
	printf("0x%04lX| ",(cnt+1));
	for(;cnt < len; cnt++){
		printf("%02X ",data[cnt]);
		if(cnt%16 == 15){
			printf("\n");
			printf("0x%04lX| ",(cnt+1));
		}
		else if (cnt%8 == 7) printf("| ");
	}
	printf("\n");
	return len;
}