#pragma once
#include "SyConnection.h"
#include <mutex>
class SyClient : public SyConnection
{
public:

	SyClient(const char* ip, int port);
	void Update();
	void Connect();
	void Send(char* data, int len);
	void Send(NetMsg* msg);
	int GetAck();
	void CheckNet();
	int MsgCount();
	NetMsg* GetMsg(int id);
	void ClearMsgs();
	void lock() {
		gm.lock();
	}
	void unlock() {
		gm.unlock();
	}
	long GetSendAck() {
		sAck++;
		return sAck-1;
	}
	void CheckReliable();
private:

	struct sockaddr_in si_other;
	int s, slen = sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;
	std::vector<NetMsg*> Msgs;
	long sAck = 0;
	long rAck = 0;
	std::mutex gm;
	std::vector<NetMsg*> reliableQueue;

};

