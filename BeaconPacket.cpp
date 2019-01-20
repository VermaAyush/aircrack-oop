#include "BeaconPacket.h"



BeaconPacket::BeaconPacket(){

}

BeaconPacket::BeaconPacket(RawData * pkt){
    len = pkt->len;
    rawdata = pkt->rawdata;
    radiotap.hdr = (struct ieee80211_radiotap_header *)pkt->rawdata;
    dot11mac.hdr = (ieee80211_frame *)(pkt->rawdata+(radiotap.hdr->it_len));
    analyze();
}

BeaconPacket::~BeaconPacket(){

}

void BeaconPacket::analyze(){
    //printf("\n---------------analyze beacon frame\n");
    beaconHdr = (BEACON_FRAME *)((u_int8_t *)dot11mac.hdr + 0x18);
    /*Get BSSID*/
    memcpy(BSSID,dot11mac.hdr->i_addr3,6);
    //printf("BSSID : %02X:%02X:%02X:%02X:%02X:%02X\n",BSSID[0],BSSID[1],BSSID[2],BSSID[3],BSSID[4],BSSID[5]);
    /*Get ESSID*/
    //printf("length of ESSID : %d\n", beaconHdr->length);
    memset(ESSID,0,33);
    memcpy(ESSID,(u_int8_t *)beaconHdr+14,beaconHdr->length);
    //printf("ESSID : %s\n",ESSID);


    /*
    u_int8_t * BSSID = dot11mac.hdr->i_addr3;
        int pwr; -> 32
        int Beacons;
        int data;
        int Channel;'
        int MB;
        char encrypt[5];
        char CIPHER[5];
        char AUTH[5];
        char ESSID[33];
    */
}

