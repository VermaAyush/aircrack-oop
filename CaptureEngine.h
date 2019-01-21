#pragma once

#include "IEngine.h"
#include "RawData.h"

#include <pcap.h>
#include <thread>

class CaptureEngine{
	private:
		pcap_t * handle;
		char * dev;
		bpf_u_int32 netp;
		char errorbuf[PCAP_ERRBUF_SIZE];

		

		
	public:
		CaptureEngine();
		~CaptureEngine();
		
		RawData * capture();
		void changeChannel(); 	
};


