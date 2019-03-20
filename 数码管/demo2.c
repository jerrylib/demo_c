
/**
播放1-9之间的数值
**/
#include<reg51.h>
#include<intrins.h>

void delay2ms(void);
void main() {
    unsigned char count = 0;
    unsigned char disNum = 0x01;
    unsigned char code num[] = {0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};
    while(1) {
        P2 = ~disNum;
        P0 =num[count++];
        //disNum = disNum <<1;
        if(count >= 10 ) {
            disNum = 0x01;
            count = 0;
        }
        delay2ms();
    }
}

void delay2ms(void) {
    unsigned char a,b;
    for(b=400; b>0; b--)
        for(a=248; a>0; a--);
    _nop_();
}