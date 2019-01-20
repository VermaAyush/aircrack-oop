#include "pch.h"
#include "CaptureEngine.h"
#include "RawData.h"

#include <pcap.h>

CaptureEngine::CaptureEngine()
{
	//printf("Make CaptureEngine\n");
	dev = (char *)"mon0";
	printf("\tDevice : %s\n", dev);
	handle = pcap_open_live(dev, BUFSIZ, 1, 0 , errorbuf);
}


CaptureEngine::~CaptureEngine(){
	pcap_close(handle);
}

RawData * CaptureEngine::capture(){
	struct pcap_pkthdr * header;
	const u_char * packet;
	int res = pcap_next_ex(handle, &header,&packet);
	RawData * result = new RawData(packet,header->len);
	//printf("--------------------success at Capture engine size : %d\n",header->len);
	//result->printData();
	//printf("then how about main ----------------------------\n");
	return result;
	
}
