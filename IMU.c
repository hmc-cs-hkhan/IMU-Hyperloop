#include "libBBB.h"

unsigned char* readIMU(){
	//read from a serial port with a specific header
	int device = initSPI(NULL);
	identifyHeader();
	//read IMU data after identifing header
	unsigned char* hexData;
	readBufferSPI(device, 32, hexData);
	//return the number read 
	return IMUData;
}

int identifyHeader(int device){
	while(true){
		unsigned char* firstByte;
		readByteSPI(device, firstByte);
		if(firstByte == 0xFE){
			unsigned char* restOfHeader;
			readBufferSPI(device, 3, restOfHeader)
			if (restOfHeader == 0x8100AA){
				return 0;
			}
		}
			
	}

}

// unsigned char[] byteParser(unsigned char* hexData){
// 	//split the hexdata into an array for different data values
// 	unsigned char xRot, yRot, zRot, yAcc, zAcc, status, seqnum, temp, crc;
// 	unsigned char data[10];
// 	xRot = hexData[0:4];
// 	yRot = hexData[4:8];
// 	zRot = hexData[8:12];
// 	xAcc = hexData[12:16];
// 	yAcc = hexData[16:20];
// 	zAcc = hexData[20:24];
// 	status = hexData[24];
// 	seqnum = hexData[25];
// 	temp = hexData[26:28];
// 	crc = hexData[28:32] ;
// 	IMUData = [xRot,yRot,zRot,xAcc,yAcc,zAcc,status,seqnum,temp,crc];
// 	return IMUData

// }


unsigned char* main(){
	unsigned char* hexdata = readIMU();
	printf("Read from IMU");
	for (int i = 0; i < 10; i++){
    printf("%02X", hexData[i]);
	}
	return hexData;

}
