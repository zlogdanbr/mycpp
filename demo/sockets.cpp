
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#include <iostream>
#include <winsock2.h>
#include <iphlpapi.h>
#include <ws2tcpi

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")

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