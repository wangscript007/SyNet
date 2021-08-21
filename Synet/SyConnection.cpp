#pragma once 

#include "SyConnection.h"

void InitNetworking() {

   


}


void SyConnection::PushEvent(NetEvent evt) {

	Events.push_back(evt);

}

int SyConnection::EventCount() {

	return Events.size();

}

NetEvent SyConnection::GetEvent(int id) {

	return Events[id];

}

void SyConnection::ClearEvents() {

	Events.resize(0);

}
