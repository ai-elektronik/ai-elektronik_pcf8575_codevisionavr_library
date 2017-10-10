<include twi2.h>

//address tulis dan baca PCF8575, PERHATIKAN PIN ADRESS PADA PCF8575
//UNTUK MENGGANTI ADRESS!!

#define pcf8575_tulis 0b01001110
#define pcf8575_baca  0b01001111

//fungsi punya dua argumen masukan
// data_p00_p07 untuk pin P0 - P7
// data_p10_p17 untuk pin P10 - P17
void tulis_pcf8575(unsigned char data_p00_p07,unsigned char data_p10_p17){
twistart();
twiwrite(pcf8575_tulis);
twiwrite(data_p00_p07);
twiwrite(data_p10_p17);
twistop();
}

//data pada semua pin langsung dibaca semua
//hasilnya langsung 16 bit
unsigned int baca_pcf8575(){
unsigned char datap0,datap1;
twistart();
twiwrite(pcf8575_baca);
datap0=twiread(1); //baca data P00-P07
datap1=twiread(0); //baca data P11-P17
twistop();	

return  (datap0 | datap1 << 8)
}
