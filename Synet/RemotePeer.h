#pragma once
#include<winsock2.h>
#include <vector>
#include <map>
#include<string>
#include "NetMsg.h"
struct RemotePeer {

	char* addr;
	USHORT port;
	sockaddr_in rpc;
	long curAck = -1;


	std::vector<NetMsg*> Msgs;
	std::map<std::string, std::vector<NetMsg*>> MMsgs;
	std::vector<NetMsg*> reliableQueue;
	std::string ID;

	void ClearMsgs() {

		Msgs.resize(0);
		MMsgs.clear();


	}

};