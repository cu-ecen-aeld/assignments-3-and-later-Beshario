#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/queue.h>
#include <pthread.h>
#include <time.h>
#include <netinet/in.h>

// linkedlist data for each thread
typedef struct {
    pthread_t threadId;
    int client_fd;
    int isComplete;
    pthread_mutex_t *pMutex;
} thread_data_t;

// linked list nodes for threads
typedef struct node {
    thread_data_t* data;
    struct node* next;
} Node;



//thread functions
void* client_handler(void* arg);
void insertNode(thread_data_t* data);
void removeCompletedThreads();
void make_Daemon(void);
static void signal_handler (int signal_number);
void clean_up(void);
void *get_in_addr(struct sockaddr *sa);
