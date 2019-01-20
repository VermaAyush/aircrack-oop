#include "pch.h"
#include "RawData.h"

RawData::RawData(){

}
RawData::RawData(const unsigned char * oriPtr, unsigned int oriLen)
{
	len = oriLen;
	//printf("malloc - RawData\n");
	rawdata = (unsigned char *)malloc(len);
	memcpy((void *)rawdata, oriPtr, len);
}

RawData::~RawData()
{
	
	try{
		//free((void *)rawdata);
		//printf("free - RawData\n");
	}
	catch(...){
		1;
	};
	
}

int RawData::printData(){
	
	long unsigned int cnt=0;
	printf("0x%04lX| ",(cnt+1));
	for(;cnt < len; cnt++){
		printf("%02X ",rawdata[cnt]);
		if(cnt%16 == 15){
			printf("\n");
			printf("0x%04lX| ",(cnt+1));
		}
		else if (cnt%8 == 7) printf("| ");
	}
	printf("\n");
	return len;
	
	//printHex((u_int8_t *)rawdata,len);
}
/*
u_char * RawData::getRawData(){
	return rawdata;
}*/