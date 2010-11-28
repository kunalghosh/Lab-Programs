#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
using namespace std;
int main(void){

	int sockfd,client1;
	char message[1024],file[1024];
	struct sockaddr_in address,cli_address;

	//Create Socket
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd>0)
		cout<<"Socket Created...."<<endl;
	//bind the socket to an ip address
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=INADDR_ANY;
	address.sin_port=htons(16000);

	if(bind(sockfd,(struct sockaddr *)&address,sizeof(address))==0)
		cout<<"Socket Bound.."<<endl;
	//listen on the socket
	listen(sockfd,3);
	//accept the connection on the socket
	int add_size=sizeof(struct sockaddr_in);
	if((client1=accept(sockfd,(struct sockaddr *)&cli_address,(socklen_t *)&add_size))>0){
		cout<<"Connected to Client on IP: "<<inet_ntoa(cli_address.sin_addr)<<endl;
	}
	
	int status=recv(client1,file,1024,0);
	if(status < 0){
		cout<<"Error occurred\n";
		close(sockfd);
		perror("Recieve ERROR");
		return(1);
	}
	cout<<"Request For the File name: "<<file<<endl;
	/*
	ifstream f;
	f.open(file);
	perror("Error Opening File");
	f.getline(message);
	cout<<message<<endl;
	perror("Error Reading File");
	send(client1,message,strlen(message),0);
	perror("ERROR AFTER 1st SEND:");
	*/
	int fd=open(file,O_RDONLY);
	perror("Error Opening File");
	int mlen=read(fd,message,200);
	perror("Error Reading File");
	while(mlen>0){
		send(client1,message,mlen,0);
		perror("SEND ERROR:");
		mlen=read(fd,message,200);
		perror("");
	}
	cout<<"FILE SENT ........\n";	
	close(sockfd);
	return(0);
}
