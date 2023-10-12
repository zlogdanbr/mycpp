/*win_init.c*/

#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int main() 
{
	WSADATA d;

	if (WSAStartup(MAKEWORD(2, 2), &d)) 
	{
		std::cout << "Failed to initialize.\n";
		return -1;
	}

	WSACleanup();
	std::cout << "Ok.\n";
	return 0;
}