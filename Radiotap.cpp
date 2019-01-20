#include "pch.h"
#include "Radiotap.h"

Radiotap::Radiotap(){
    //printf("malloc - Radiotap\n");
    //hdr = (struct ieee80211_radiotap_header *)malloc(sizeof(ieee80211_radiotap_header));
}

Radiotap::~Radiotap(){
    //rintf("free - Radiotap\n");
    //free(hdr);
}

void Radiotap::printAttr(){
    printf("version : %02X\n",hdr->it_version);
    printf("len : %d\n",hdr->it_len);
    printf("field : %04X\n",hdr->it_present);
    /*
        u_int8_t        it_version;    
        u_int8_t        it_pad;
        u_int16_t       it_len;     
        u_int32_t       it_present;  
    */
}