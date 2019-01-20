#pragma once
#include "pch.h"
class RawData
{
	public:
		int len=0;
		unsigned char * rawdata = 0;

		RawData();
		RawData(const unsigned char * oriPtr, unsigned int oriLen);
		~RawData();

		int printData();
		//u_char * getRawData();
};
