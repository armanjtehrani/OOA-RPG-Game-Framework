#include <iostream>

#define PLATFORM_WINDOWS	1
#define PLATFORM_MAC		2
#define PLATFORM_UNIX		3

#if defined (_WIN32)
#define PLATFORM PLATFORM_WINDOWS
#elif defined (_APPLE_)
#define PLATFORM PLATFORM_MAC
#else
#define PLATFORM PLATFORM_UNIX
#endif


#if PLATFORM == PLATFORM_WINDOWS
#include <WinSock2.h>

#elif PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#endif


#if PLATFORM == PLATFORM_WINDOWS
#pragma comment( lib, "wsock32.lib" )
#endif


bool InitializeSockets()
{
#if PLATFORM == PLATFORM_WINDOWS
	WSADATA WsaData;
	return WSAStartup(MAKEWORD(2, 2), &WsaData) == NO_ERROR;
#else
	return true;
#endif
}


void ShutdownSockets()
{
#if PLATFORM == PLATFORM_WINDOWS
	WSACleanup();
#endif
}



int main()
{
	int handle = socket(AF_INET,
		SOCK_DGRAM,
		IPPROTO_UDP);
	std::cout << PLATFORM << std::endl;
	if (handle <= 0)
	{
		printf("failed to create socket\n");
		system("pause");
		//return false;
	}
	unsigned short port = 5000;
	sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port =
		htons((unsigned short)port);

	if (bind(handle,
		(const sockaddr*)&address,
		sizeof(sockaddr_in)) < 0)
	{
		printf("failed to bind socket\n");
		system("pause");
		return false;
	}
	system("pause");
	return 0;
}