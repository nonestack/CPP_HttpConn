#ifndef __HTTP_CONN_H__
#define __HTTP_CONN_H__

#include <sys/epoll.h>

#define BUF_SIZE 4096

class HttpConn{
    public:
        HttpConn(){}
        ~HttpConn(){}

    private:                                //成员函数
        void init(int sockfdarg, const sockaddr &addr);

    private:                                //静态成员变量
        static int epoll_fd;
    private:                                //成员变量
        int sockfd;
        char read_buf[BUF_SIZE];
        char write_buf[BUF_SIZE];
};

#endif