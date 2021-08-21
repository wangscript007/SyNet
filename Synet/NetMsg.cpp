#include "NetMsg.h"

NetMsg::NetMsg(std::string chan,int ac,MsgSendType sendType,char* bbuf, int bsize)
{

	buf = new char[bsize];
	for (int i = 0; i < bsize; i++) {

		buf[i] = bbuf[i];

	}
	sType = sendType;
	size = bsize;
	ack = ac;

}

NetMsg::NetMsg(std::string chan,int ac,MsgSendType sendType,int  bsize) {

	buf = new char[bsize];
	pos = 0;
	size = bsize;
	sType = sendType;
	ack = ac;
	PushString(chan);
	PushInt(ack);
	PushInt((int)sendType);


}

NetMsg::NetMsg(char* bbuf, int bsize) {

	buf = new char[bsize];
	for (int i = 0; i < bsize; i++) {

		buf[i] = bbuf[i];

	}

	//buf = bbuf;
	size = bsize;
	pos = 0;
	chan = PullString();
	ack = PullInt();
	sType = (MsgSendType)PullInt();

}

void NetMsg::PushChar(char v) {

	buf[pos++] = v;

}

void NetMsg::PushDouble(double v) {

	int bc = 0;
	char* bv = (char*)&v;
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
		
}

void NetMsg::PushFloat(float v) {

	int bc = 0;
	char* bv = (char*)&v;
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];

}

void NetMsg::PushInt(int v) {

	int bc = 0;
	char* bv = (char*)&v;
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];

}

void NetMsg::PushShort(short v) {

	int bc = 0;
	char* bv = (char*)&v;
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];

}

void NetMsg::PushString(std::string v) {

	PushInt((int)v.length());
	for (int bc = 0; bc < v.length(); bc++)
	{
		PushChar((char)v[bc]);
	}

}

void NetMsg::PushLong(long v) {

	long bc = 0;
	char* bv = (char*)&v;
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
	buf[pos++] = bv[bc++];
}


char NetMsg::PullChar() {

	return buf[pos++];

}

short NetMsg::PullShort() {

	short r = 0;
	char* sr = (char*)&r;
	sr[0] = buf[pos++];
	sr[1] = buf[pos++];
	return r;

}

int NetMsg::PullInt() {

	int r = 0;
	char* rv = (char*)&r;
	rv[0] = buf[pos++];
	rv[1] = buf[pos++];
	rv[2] = buf[pos++];
	rv[3] = buf[pos++];
	return r;

}

float NetMsg::PullFloat() {

	float r = 0;
	char* rv = (char*)&r;
	rv[0] = buf[pos++];
	rv[1] = buf[pos++];
	rv[2] = buf[pos++];
	rv[3] = buf[pos++];
	return r;

}

double NetMsg::PullDouble() {

	int r = 0;
	char* rv = (char*)&r;
	rv[0] = buf[pos++];
	rv[1] = buf[pos++];
	rv[2] = buf[pos++];
	rv[3] = buf[pos++];
	rv[4] = buf[pos++];
	rv[5] = buf[pos++];
	rv[6] = buf[pos++];
	rv[7] = buf[pos++];
	return r;

}

std::string NetMsg::PullString() {

	int sl = PullInt();
	char* st = new char[sl+1];
	for (int s = 0; s < sl; s++) {
		st[s] = PullChar();
	}
	st[sl] = "\0"[0];

	return std::string(st);

}

long NetMsg::PullLong() {

	long r = 0;
	char* rv = (char*)&r;
	rv[0] = buf[pos++];
	rv[1] = buf[pos++];
	rv[2] = buf[pos++];
	rv[3] = buf[pos++];
	rv[4] = buf[pos++];
	rv[5] = buf[pos++];
	rv[6] = buf[pos++];
	rv[7] = buf[pos++];
	return r;

}

char* NetMsg::GetBuf()
{

	return buf;

}

int NetMsg::GetSize() {

	return size;

}

std::string NetMsg::GetChannel() {

	return chan;

}

int NetMsg::GetAck() {

	return ack;

}