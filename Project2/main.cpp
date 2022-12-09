#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>
#include"SerialPort.h"

char output[MAX_DATA_LENGTH];
const char* port = "\\\\.\\COM6";
SerialPort arduino(port);
int main() {
	system("D://Video//1.mp4");
	Sleep(3500);
	keybd_event(VK_SPACE, 0x20, KEYEVENTF_EXTENDEDKEY, 0);
	int flag = 0;
	while (arduino.isConnected()) {
		arduino.readSerialPort(output, MAX_DATA_LENGTH);
		if (output[0] == '0' && flag == 0) {
			keybd_event(VK_SPACE, 0x20, KEYEVENTF_EXTENDEDKEY, 0);
			Sleep(2000);
			keybd_event(VK_SPACE,0x20,KEYEVENTF_EXTENDEDKEY,0);
			flag = 1;
		}
		if (output[0] == '1') flag = 0;
	}
	return 0;
}