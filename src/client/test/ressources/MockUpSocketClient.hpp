#pragma once

#include "client/network/SocketClient.hpp"
#include "client/network/ServerConnectionInfo.hpp"
#include "client/network/SocketClientListener.hpp"

#include "bicyclade.pb.h"

/**
 * Mock-up on the socket that does not connect to any actual server. Any
 * message send to the server will be directly forward back to the onMessage()
 * socket listener callback.
 *
 * For test purpose and debugging only.
 */
class MockUpSocketClient : public SocketClient {
public:
    MockUpSocketClient(ServerConnectionInfo& i, SocketClientListener& l);
    ~MockUpSocketClient();

    // -----------------------------------
    // SocketClient Implementation
    // -----------------------------------
    void connect();
    void disconnect();
    void send(const proto::PContainer& message);
};
