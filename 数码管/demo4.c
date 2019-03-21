/**
 自动增数器
**/
#include <reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char

sbit dula = P2 ^ 6;
sbit wela = P2 ^ 7;

uchar code num[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f,
                    0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71,
                    0x76, 0x38, 0x86};
uchar bai, shi, ge, t0, location, flag;
uint total;

void delay(int i)
{
  while (i--)
    ;
}
/**
数值展示
**/
void displayNum(uchar shiwang, uchar wang, uchar qian, uchar bai, uchar shi, uchar ge)
{
  P0 = num[shiwang];
  P2 = ~location;
  location = location << 1;
  delay(100);
  P0 = 0x00;

  P0 = num[wang];
  P2 = ~location;
  location = location << 1;
  delay(100);
  P0 = 0x00;

  P0 = num[qian];
  P2 = ~location;
  location = location << 1;
  delay(100);
  P0 = 0x00;

  P0 = num[bai];
  P2 = ~location;
  location = location << 1;
  delay(100);
  P0 = 0x00;

  P0 = num[shi];
  P2 = ~location;
  location = location << 1;
  delay(100);
  P0 = 0x00;

  P0 = num[ge];
  P2 = ~location;
  location = location << 1;
  delay(100);
  P0 = 0x00;

  location = 0x01;
}

/**
初始化系统参数
**/
void init()
{
  bai = 0;
  shi = 0;
  ge = 0;
  total = 432;
  t0 = 0;
  location = 0x01;
  TMOD = 0X01;
  TH0 = 0Xfc;
  TL0 = 0x18;
  EA = 1;
  ET0 = 1;
  TR0 = 1;
  flag = 1;
}

void main()
{
  init();
  while (1)
  {
    bai = total / 100;
    shi = total % 100 / 10;
    ge = total % 10;
    displayNum(7, 6, 5, bai, shi, ge);
    delay(20);
  }
}

void timer0() interrupt 1
{
  TH0 = 0Xfc;
  TL0 = 0x18;
  t0++;
  if (flag == 1)
  {
    if (t0 % 50 == 0)
    {
      total--;
      if (total == 410)
      {
        flag = 0;
      }
    }
  }
  else
  {
    displayNum(16, 14, 17, 17, 0, 18);
  }
}