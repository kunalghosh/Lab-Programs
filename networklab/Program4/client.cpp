#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
using namespace std;

int main(int argc,char **argv){
	
	int sockfd;
	struct sockaddr_in address;
	char filename[1024],message[1024];

	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd > 1)
		cout<<"Socket Created Successfully.\n";
	address.sin_family=AF_INET;
	if(argc < 2){
		cout<<"Please enter an IP address";
		close(sockfd);
		return(1);
	}
	inet_pton(AF_INET,argv[1],&address.sin_addr);
	address.sin_port=htons(16000);

	if(!connect(sockfd,(struct sockaddr*)&address,sizeof(address)))
		cout<<"Connection Successful"<<endl;
	else
		cout<<"Connection UnSuccessful"<<endl;
	
	cout<<"Please enter the filename:\n";
	cin>>filename;

	send(sockfd,filename,sizeof(filename),0);
	cout<<"Filename Request sent.\n";

	int cont;
	while(cont=recv(sockfd,message,200,0))
		cout<<message;
	if(cont==0){
		perror("RECIEVE ERROR");
	}
	cout<<"\nTransfer Complete.\n";
	close(sockfd);
	return(0);
}
