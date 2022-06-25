#include <exception>

#include "http_conn.h"

//选择使用水平触发还是垂直触发
#define CONN_LT
//#define CONN_ET

void HttpConn::init(int sockfdarg, const sockaddr &addr){
    sockfd = sockfdarg;
    //添加client的address

    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sockfd, )
}

//修改epoll监察的fd
void addfd(int epoll_fd, int fd){
    epoll_event event;
    event.data.fd = fd;

#ifdef CONN_LT
    event.events = EPOLLIN | EPOLLHUP;
#endif

#ifdef CONN_ET
    event.events = EPOLLET | EPOLLIN | EPOLLHUP;
#endif

    if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event) == -1){
        throw std::exception();
    }
}