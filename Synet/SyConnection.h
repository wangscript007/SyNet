#pragma once



//#include "RemotePeer.h"
#include<stdio.h>
#include<vector>
#include <string>
#include "NetEvent.h"
#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define BUFLEN 512

void InitNetworking();

class SyConnection
{
public:

	void PushEvent(NetEvent evt);
	NetEvent GetEvent(int id);
	int EventCount();
	void ClearEvents();

protected:
	void* Addr;
	void* Host;
	SOCKET s;
	std::vector<NetEvent> Events;

};

