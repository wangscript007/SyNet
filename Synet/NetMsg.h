#pragma once
#include <string>

enum MsgSendType {

	Reliable,Unreliable

};

class NetMsg
{
public:

	NetMsg(std::string chan,int ack,MsgSendType sndType,char* buf, int len);
	NetMsg(std::string chan,int ack,MsgSendType sndType,int maxBuf);
	NetMsg(char* buf, int bsize);
	void PushInt(int v);
	void PushFloat(float v);
	void PushShort(short v);
	void PushDouble(double v);
	void PushChar(char v);
	void PushString(std::string v);
	void PushLong(long v);
	int PullInt();

	float PullFloat();
	short PullShort();
	double PullDouble();
	char PullChar();
	std::string PullString();
	long PullLong();

	char* GetBuf();
	int GetSize();
	std::string GetChannel();
	int GetAck();
	int GetPos() {
		return pos;
	}
	MsgSendType GetSendType() {
		return sType;
	}
	int GetLastSend() {
		return lastSend;
	}
	void SetLastSend(int send) {
		lastSend = send;
	}
private:
	std::string chan;
	int ack = 0;
	char* buf;
	int size = 0;
	int pos;
	MsgSendType sType;
	int lastSend;
//	RemotePeer* intended;
};

