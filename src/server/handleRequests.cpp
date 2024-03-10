#include "server/handleRequests.h"

#include "db/db_interface.h"
#include "messageProtocol.h"

#include <cstring>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

//todo`
//create a verified variable to confim a connection OP has been sent and established

HandleConnection::HandleConnection()
    : connid(-1) {
    cout << "Error handling connection" << endl;
}
HandleConnection::HandleConnection(int conn)
    : connid(conn) {
    handle();
}
void HandleConnection ::handle() {
    //read into the buffer
    char buffer[BUFFER_SIZE];
    readConn(buffer);
    //parse it
    parseRequest(buffer);

    //build struct
    //identify res
    //send res
    //follow the command parsed
    return;
}
void HandleConnection ::readConn(char buffer[BUFFER_SIZE]) {
    //int total_read = 0;
    //while (total_read < BUFFER_SIZE ) {
    //    int bytes_read = 0;
    //    bytes_read = read(connid, buffer + total_read, BUFFER_SIZE - total_read);
    //
    //    total_read += bytes_read;
    //    if (bytes_read == 0) {
    //        break;
    //    } else if (bytes_read == -1) {
    //        // Handle error
    //        break;
    //    }
    //}
    return;
}

void HandleConnection ::printMsg(MsgHeader x) {
    cout << "-------" << endl;
    cout << "Printing Message Header" << endl;
    cout << "MessageLength: " << x.messageLength << endl;
    cout << "requestID: " << x.requestID << endl;
    cout << "ResponseTo: " << x.responseTo << endl;
    cout << "OpCode: " << x.opCode << endl;
    cout << "-------" << endl;
    //Op code
}
void HandleConnection ::parseRequest(char buffer[BUFFER_SIZE]) {
    //read msg headero
    MsgHeader header;
    // Receive data into a buffer
    int bytesRead = recv(connid, &header, sizeof(MsgHeader), 0); //read the header first
    //create a database in private
    //memcpy(&header, buffer, sizeof(MsgHeader));
    printMsg(header);
    //cout << "buffer: " << buffer << endl;
    //cout << "Buffer_size: "<< sizeof(buffer) << endl;
    cout << "header_size: " << sizeof(MsgHeader) << endl;
    if (header.opCode == 0) {
        cout << "CONNECT" << endl;
        OP_CONNECT connectData;
        bytesRead += recv(connid, &connectData.username, sizeof(connectData.username), 0);
        bytesRead += recv(connid, &connectData.password, sizeof(connectData.password), 0);
        // for (size_t i = 0; i < bytesRead; ++i) { //Debug message
        //   cout << ((unsigned char*)&connectData)[i];
        // }
        // cout << endl;
        if (bytesRead == -1) {
            perror("Error receiving data");
            return;
        } else if (bytesRead == 0) {
            std::cerr << "Connection closed by the client\n";
            return;
        } else if (bytesRead != sizeof(OP_CONNECT)) {
            std::cerr << "Received incomplete data\n";
            return;
        }
        cout << "User: " << connectData.username << endl;

        cout << "User: " << connectData.password << endl;
    }
    //cout << "Parse this: " << buffer << endl;
    return;
}
