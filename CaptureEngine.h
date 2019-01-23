#pragma once

#include "IEngine.h"
#include "RawData.h"
#include "PacketList.h"

#include <pcap.h>
#include <thread>

class CaptureEngine{
	private:
		pcap_t * handle;
		char * dev;
		bpf_u_int32 netp;
		char errorbuf[PCAP_ERRBUF_SIZE];
		PacketList * pktList;
		

		
	public:
		CaptureEngine(PacketList * pktList);
		~CaptureEngine();
		
		RawData * capture();
		void changeChannel(); 	
};


