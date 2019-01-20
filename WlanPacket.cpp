#include "pch.h"
#include "WlanPacket.h"



WlanPacket::WlanPacket()
{

}

WlanPacket::WlanPacket(RawData * packet)
{
    len = packet->len;
    rawdata = packet->rawdata;
}

WlanPacket::~WlanPacket(){
	try{
        radiotap.~Radiotap();
        dot11mac.~Dot11Mac();
    }catch(...){};
}

void WlanPacket::printAttr(){
    printf("this is WlanPacket\n");
    printf("length : %d\n",len);
    printf("raw data : %p \n", rawdata);
    printf("radiotap : %p \n", &radiotap);
    printf("Dot11mac : %p \n", &dot11mac);
    printf("radiotap hdr : %p \n", radiotap.hdr);
    printf("Dot11mac hdr : %p \n", dot11mac.hdr);
    
}