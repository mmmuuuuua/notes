

//server.cpp

int server_(){
    int listenfd, connfd;
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return -1;

    struct sockaddr_in serverAddr, clinetAddr;
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htons(INADDR_ANY);
    serverAddr.sin_port = htons(8888);

    if(bind(listenfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1)
        return -1;
    
    if(listen(listenfd, 2048) == -1)
        return -1;

    socklen_t clilenlen;
    while(1){
        if((connfd = accept(listenfd, (struct sockaddr*)&clinetAddr, &clilenlen)) == -1)
            return -1;
    }
    
}


//client.cpp

int client_(){
    int clientfd;
    if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;
    
    s
    struct sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port(8888);
    if(inet_pton(AF_INET, argv[1], &serverAddr.sin_addr) < 0){
        return -1;
    }

    if(connect(clientfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
        return -1;
    
    
}