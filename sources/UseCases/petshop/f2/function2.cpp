/*
 * Use case petshop function2.cpp
 */
#include "CBasefunction.h"
#include <iostream>
int main(int argc, char *argv[]) {
    int redemarrage = atoi(argv[7]);
    int position = atoi(argv[6]);
    GUI_ARINC_partition("Partition2", position, redemarrage);
    int nbarg = argc;
    char **argument = new char*[argc];
    int i = 0;
    for (i = 0; i <= nbarg; i++) {
        argument[i] = argv[i];
    }
    COMMUNICATION_VECTOR myCvector;
    myCvector = init_communication(argument, NULL);
    Type_Message rMessage;
    int portID;
    int sock;
    vector_get(&(myCvector.vqueuing_port), 0, &portID);
    vector_get(&(myCvector.vqueuing_socket), 0, &sock);
    //    CQueuing Qservice;

    int ifmessage = 0;
    char sMessage[256];
    int j = 0;

    for (;;) {
        ifmessage = RECEIVE_QUEUING_MESSAGE(sock, &rMessage);
        if (ifmessage > 0) {
            std::cout << "			" << std::endl;
            std::cout << "Message from: " << rMessage.m_sender << " Length: " << rMessage.m_length << std::endl;
            std::cout << "Message: " << rMessage.m_message << std::endl;
        }
        
        sprintf(sMessage, "Message sent from Partition2 number: %d", j);
        SEND_QUEUING_MESSAGE(argv[0], portID, sock, myCvector.emetteur, rMessage.m_message);
        j++;
    }
    return 0;
}
