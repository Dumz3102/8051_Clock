#include<regx52.h>
#include"..\Lib\Delay.h"

// Khai bao LED 7 doan
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

// Khai bao chan
#define LED_PORT P2
sbit LEDG1_PIN = P3^0;  //Led gio 1
sbit LEDG2_PIN = P3^1;  //Led gio 2
sbit LEDP1_PIN = P3^2;  //Led phut 1
sbit LEDP2_PIN = P3^3;  //Led phut 2
sbit LEDGY1_PIN = P3^4; //Led giay 1
sbit LEDGY2_PIN = P3^5; //Led giay 2

void main(){
     // Khai bao bien	
     unsigned char gio,phut,giay;
	   unsigned char chuc,dvi;
	   unsigned int i;
	   gio = phut = giay = 0;

     while(1){
			 
		 for(i = 0;i<166;i++){	 
			 //Hien thi gio
			 chuc = gio/10;
			 dvi  = gio%10;
			 //Hien thi led 1
			 LED_PORT = Code7Seg[chuc];
			 LEDG1_PIN = 0;
			 Delay_ms(1);
			 LEDG1_PIN = 1;
			 //Hien thi led 2
			 LED_PORT = Code7Seg[dvi];
			 LEDG2_PIN = 0;
			 Delay_ms(1);
			 LEDG2_PIN = 1;
			 
       //Hien thi phut
			 chuc = phut/10;
			 dvi  = phut%10;
			 //Hien thi led 1
			 LED_PORT = Code7Seg[chuc];
			 LEDP1_PIN = 0;
			 Delay_ms(1);
			 LEDP1_PIN = 1;
			 //Hien thi led 2
			 LED_PORT = Code7Seg[dvi];
			 LEDP2_PIN = 0;
			 Delay_ms(1);
			 LEDP2_PIN = 1;  
			 
			 //Hien thi giay
			 chuc = giay/10;
			 dvi  = giay%10;
			 //Hien thi led 1
			 LED_PORT = Code7Seg[chuc];
			 LEDGY1_PIN = 0;
			 Delay_ms(1);
			 LEDGY1_PIN = 1;
			 //Hien thi led 2
			 LED_PORT = Code7Seg[dvi];
			 LEDGY2_PIN = 0;
			 Delay_ms(1);
			 LEDGY2_PIN = 1;
		 }
		 giay++;
		 if(giay == 60){
       giay = 0; 
			 phut++;
			 if(phut == 60){
          phut = 0;
				  gio++;
				  if(gio == 24){
             gio = 0;
          }
         }
       }
     }
}