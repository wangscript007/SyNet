#pragma once
#include<thread>
#include "SyConnection.h"
#include <mutex>

class SyHost :
    public SyConnection
{
public:

    SyHost(int port);
    void CheckNet();

    void AddPeer(RemotePeer* peer);
    RemotePeer* FindPeer(char* ip, USHORT port);
    bool HasPeer(char* ip, USHORT port);
    int PeerCount() {
        return peers.size();
    }

    RemotePeer* GetPeer(int id) {

        return peers[id];

    }

    bool GetInUse() {
        return InUse;
    }

    long GetSendAck() {
        sAck++;
        return sAck - 1;
    }

    void Send(char* buf, int len, RemotePeer* peer);
    void Send(NetMsg* m, RemotePeer* peer);

    void BroadCast(NetMsg* msg);
    void lock() {
        gm.lock();
    }
    void unlock() {
        gm.unlock();
    }

    void CheckReliable();
    void Confirm(NetMsg* msg,RemotePeer* p);

private:
    bool InUse = false;
    struct sockaddr_in server, si_other;
    char buf[BUFLEN];
    WSADATA wsa;
    int slen, recv_len;
    std::vector<RemotePeer*> peers;
    std::mutex gm;
    long sAck = 0;
};

