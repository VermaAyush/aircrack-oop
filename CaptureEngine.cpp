#include "pch.h"
#include "CaptureEngine.h"
#include "RawData.h"

#include <pcap.h>

CaptureEngine::CaptureEngine()
{
	//printf("Make CaptureEngine\n");
	dev = (char *)malloc(50);
	printf("Type network interface : ");
	scanf("%s",dev);
	printf("\tDevice : %s\n", dev);
	handle = pcap_open_live(dev, BUFSIZ, 1, 0 , errorbuf);
	//system("iwconfig mon0 channel 1");
	//system("iwconfig mon0 channel 1");

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
	//changeChannel();
	return result;
	
}

void CaptureEngine::changeChannel(){
	static int count=0;
	static int channel = 1;
	while(1){
		usleep(713);
		count ++;
		if(count >=  50){
			count%=50;
			channel++;
			channel%=14;
			char channels[17][3] = {"1", "7","13","2","8", "3","14","9", "4", "10","5","11","6","12"};
			char commandBase[30] = "iwconfig ";
			strcat(commandBase, dev);
			strcat(commandBase, " channel ");
			char commandRst[50];
			strcpy(commandRst, commandBase);
			strcat(commandRst, channels[channel]);
			//printf("command : %s\n", commandRst);
			system(commandRst);
		}
	}
	
	
}