#include <iostream>
#include <WinSock2.h>
#include<WS2tcpip.h>
#include<tchar.h>
#pragma comment(lib,"Ws2_32.lib")
using namespace std;
int main(){
    WSADATA wsaData;
    int wsaerr;
    WORD wVersionRequested=MAKEWORD(2,2);
    wsaerr = WSAStartup(wVersionRequested,&wsaData);//初始化 Winsock 服务
    SOCKET serverSocket;
    serverSocket=INVALID_SOCKET;
    serverSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);//初始化服务器端的 socket ，地址族为 IPv4 ,类型为 TCP
    sockaddr_in service; //地址结构体，用于绑定服务器 socket
    service.sin_family=AF_INET; //设置地址族为 IPv4 
    service.sin_addr.s_addr = inet_addr("127.0.0.1"); //设置服务器监听的 IP 地址为本地地址
    service.sin_port=htons(55555); //设置服务器监听的端口号，转换为网络字节序
    bind(serverSocket, (SOCKADDR*)&service, sizeof(service)); //将服务器 socket 绑定到指定的 IP 地址和端口 
    listen(serverSocket, 1); //监听连接请求
    SOCKET clientSocket;
    clientSocket= INVALID_SOCKET;
    clientSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);//初始化客户端 socket
    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr("127.0.0.1");
    clientService.sin_port = htons(55555);// 设置客户端的地址
    connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService));//连接
    char buffer[200];
    printf("Enter the message: ");
    cin.getline(buffer,200);//发送消息
    SOCKET acceptSocket;
    acceptSocket = accept(serverSocket,NULL,NULL); // 接收连接请求
    int sbyteCount = send(clientSocket,buffer,200,0);
    char receiveBuffer[200];
    int rbyteCount = recv(acceptSocket, receiveBuffer, 200, 0);
    cout << "Received data: " << receiveBuffer << endl;//接收消息
    closesocket(clientSocket);
    closesocket(serverSocket);
    closesocket(acceptSocket);
    WSACleanup();//清理
    return 0;
}