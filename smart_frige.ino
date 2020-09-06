#include "IRremote.h"

//引导码+客户码+客户反码+数据码+数据反码+结束位
/*
 * An IR LED must be connected to Arduino PWM pin 3
 * 开机编码：L,A,A',B,B',C,C',  S, L,A,A',B,B',C,C'
 * L,A,A',B,B',C,C',  S, L,A,A',B,B',C,C',  S, L,A,A',Q,Q',Y,Y'
 * 用户码：4055，对应的二进制数：0100 0000 0101 0101；

  数据码：44，对应的二进制数为0100 0100，
  再加上NEC协议固定的引导码“9000,4500”，以及结束码“560,20000”。
 * L为引导码,
S为分隔码,
A为认别码(A=1011 0010=B2，预留方案时A=10110111=B7),
A'为A的反码,
B:命令妈
B'为B的反码,

C'为C的反码
*/
unsigned int zeroLow = 559;
unsigned int zeroHigh = 531;
unsigned int oneLow = 561;
unsigned  int oneHigh = 1578;


short int up_frige = 1;
short int off_frige = 0;
IRsend irsend;

void up_f(){

  short int khz = 38;
  unsigned int media_frige_Signal[] = {
    4400,4400,  //L
        //1011 0010 A
        oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,oneLow,oneHigh,          zeroLow,zeroHigh,zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,           //A
        //0100 1101 a
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,      oneLow,oneHigh,oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,         //A'
        //1011 1111 自动风 B
        oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,oneLow,oneHigh,          oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,        //B
        //0100 0000 b
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,       zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,            //B'
        //1101 0000 C 26摄氏度制冷
        oneLow,oneHigh,oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,    zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,           //C
        //0100 0000 c
        zeroLow,zeroHigh,zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,      oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,//C'
        540,5220,   //S
        4400,4400,  //L
        //1011 0010 A
        oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,oneLow,oneHigh,          zeroLow,zeroHigh,zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,           //A
        //0100 1101 a
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,      oneLow,oneHigh,oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,         //A'
        //1011 1111 自动风 B
        oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,oneLow,oneHigh,          oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,        //B
        //0100 0000 b
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,       zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,            //B'
        //1101 0000 C 26摄氏度制冷
        oneLow,oneHigh,oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,    zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,           //C
        //0100 0000 c
        zeroLow,zeroHigh,zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,      oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,//C'
        540     //end
};
  irsend.sendRaw(media_frige_Signal, sizeof(media_frige_Signal) / sizeof(media_frige_Signal[0]), khz); 
}

void off_f(){

    short int khz = 38;
    //unsigned int media_frige_Signal[] ={25524,4400,4400,
    // 550,1650,550,550,550,1600,550,1650,550,500,550,550,550,1650,550,500,550,550,550,1650,550,500,550,550,550,1650,550,1600,550,550,550,1600,550,1650,550,550,550,1600,550,1650,550,1600,550,1650,550,1600,550,1650,550,550,500,1650,550,550,550,550,500,550,550,550,550,550,550,550,500,550,550,1650,550,550,500,550,550,550,550,550,550,550,500,550,550,1650,550,550,500,1650,550,1650,500,1650,550,1650,500,1650,550,1650,550};
  unsigned int media_frige_Signal[] = {
    4400,4400,  //L
        4400,4400,  //L
        //1011 0010 A
        oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,oneLow,oneHigh,          zeroLow,zeroHigh,zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,           //A
        //0100 1101 a
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,      oneLow,oneHigh,oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,         //A'
        //1011 1111 B
        oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,oneLow,oneHigh,          oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,        //B
        //0100 0000 b
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,       zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,            //B'
        //1011 1111 C
        zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,    oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,           //C
        //0100 0000 c
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,      zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,//C'
        540,5220,   //S
        4400,4400,  //L
        //1011 0010 A
        oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,oneLow,oneHigh,          zeroLow,zeroHigh,zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,           //A
        //0100 1101 a
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,      oneLow,oneHigh,oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,         //A'
        //1011 1111 B
        oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,oneLow,oneHigh,          oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,        //B
        //0100 0000 b
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,       zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,            //B'
        //1011 1111 C
        zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,    oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,           //C
        //0100 0000 c
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,      zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,//C'
        540,5220,     //end
        4400,4400,    //L
        //1011 0010 A
        oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,oneLow,oneHigh,          zeroLow,zeroHigh,zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,           //A
        //0100 1101 a
        zeroLow,zeroHigh,oneLow,oneHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,      oneLow,oneHigh,oneLow,oneHigh,zeroLow,zeroHigh,oneLow,oneHigh,         //A'
        //0000 0000  Q //及时关闭
        zeroLow,zeroHigh ,zeroLow,zeroHigh ,zeroLow,zeroHigh,zeroLow,zeroHigh,   zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,  //Q
        oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,            oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh, //Q'

        //0000 0000 Y//某分钟
        zeroLow,zeroHigh ,zeroLow,zeroHigh ,zeroLow,zeroHigh,zeroLow,zeroHigh , zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,zeroLow,zeroHigh,  //Y
        oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh            ,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh,oneLow,oneHigh, //Y'
        540 //end
  };
  irsend.sendRaw(media_frige_Signal, sizeof(media_frige_Signal) / sizeof(media_frige_Signal[0]), khz); 
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}



void loop() {
     short int cmd = 0;
//  if(Serial.available()){
//    cmd = Serial.read() - 48;
//    Serial.println(cmd);
//    if(cmd == up_frige)
//      up_f();
//    else if(cmd == off_frige)
//      off_f(); 
//  }
    if(Serial.available()){
      cmd = Serial.read();
      while(1){
        Serial.println(cmd);
        delay(3000);
      }
    }
}
