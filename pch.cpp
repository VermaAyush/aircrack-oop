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

void printBins(u_int8_t *data, u_int64_t size){
	int i = 0;
	int mask=1;
	u_int64_t cnt = 0;
	//printf("0x%04lX| ",(cnt));
	for(cnt = 0; cnt < size/8; cnt++){
		for(i = 0; i< 8 ; i++){
			mask *=2;
		}
		mask/=2;

		while(mask){
			if(mask&(data[cnt])) printf("1");
			else printf("0");
			mask >>=1;
		}
		printf(" ");
		
		if( cnt % 4 == 3){
			printf("\n");
			//printf("0x%04lX| ",(cnt+1));
		}
		else if (cnt % 2 == 1) printf("| ");
		mask =1;
	}
	if(size-(cnt*8)){
		for(i = 0; i< (size-cnt) ; i++){
			mask *=2;
		}
		mask/=2;
		while(mask){
			if(mask&(*data)) printf("1");
			else printf("0");
			mask >>=1;
		}

	}

	
	
}