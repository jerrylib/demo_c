/**
轮询播放0-f之间的数值。
**/
#include<reg51.h>
#include<intrins.h>

unsigned char code num[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f,0xdc,0x7c,0x39,0x5e,0x7b,0x71};

void delay() {
    unsigned int i = 50000;
    while(i--);
    _nop_();
}

void main() {
    char index = 0x01;
		char count = 0x00;
    while(1) {
        P2 = ~index;
        P0 = num[count++];
        index = index <<1;
				if(count%6 == 0){
					index = 0x01;
				}
				if(count >=16){
					index = 0x01;
					count = 0x00;
				}
				delay();
    }

}