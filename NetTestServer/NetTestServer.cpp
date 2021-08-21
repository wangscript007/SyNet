// NetTestClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SyHost.h"

//std::map<std::string,Remote


int main()
{
    std::cout << "Hello World!\n";

    InitNetworking();

    SyHost* host = new SyHost(8888);

    while (true) {

        if (host->GetInUse()) {
            continue;
        }

        int ec = host->EventCount();
        int bb = 5;
        NetMsg* m1;

        for (int i = 0; i < ec; i++) {

            NetEvent evt = host->GetEvent(i);

            switch (evt.Type) {
            case NetEventType::NewClientConnected:

                 bb = 5;

                 m1 = new NetMsg("requestName", host->GetSendAck(),MsgSendType::Reliable, 256);
                 host->Send(m1, evt.Peer);
                 printf("Send name request to peer.\n");


                break;

            case NetEventType::NewMessage:

                auto msg = evt.Msg;

                if (msg->GetChannel() == "clientName")
                {
                    
                    std::string name = msg->PullString();

                    printf("ClientName=");
                    printf(name.c_str());
                    printf("\n");
                    evt.Peer->ID = name;


                }
                else {

                    std::string res = evt.Peer->ID + ":"+ msg->PullString();

                    printf("Client:");
                    printf(res.c_str());
                    printf("\n");

                    auto rm = new NetMsg("say", host->GetSendAck() ,MsgSendType::Reliable, 256);
                    rm->PushString(res);

                    host->BroadCast(rm);

                }
                    break;

            }

        }

        host->ClearEvents();


        /*
        for (int i = 0; i < host->PeerCount(); i++) {

            auto peer = host->GetPeer(i);

            if (peer->Msgs.size() > 0)
            {
                auto msg = peer->Msgs[0];
                peer->ClearMsgs();

                std::string res = msg->PullString();

                printf("Client:");
                printf(res.c_str());
                printf("\n");

                auto rm = new NetMsg("say", 0, 256);
                rm->PushString(res);

                host->BroadCast(rm);



            }

        }
        */
    }




}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
