#pragma once
#include "RemotePeer.h"
#include "NetMsg.h"
enum NetEventType {

	NewClientConnected,ConnectedToHost,NewMessage,None,UserEvent

};

struct NetEvent {

	NetEventType Type;
	RemotePeer* Peer;
	NetMsg* Msg;
	int UserEvent;

	NetEvent() {

		Type = NetEventType::None;
		Peer = nullptr;
		Msg = nullptr;
		UserEvent = 0;
	}
	NetEvent(NetEventType t) {

		Type = t;
		Peer = nullptr;
		Msg = nullptr;
		UserEvent = 0;
	}


};

