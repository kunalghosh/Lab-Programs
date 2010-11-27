//Program to perform CRC generation and error detection
//For the CRC-CCITT 16 bit checksum.

#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

#define GENERATOR_LENGTH 17

char XOR(char a , char b){
	if(a == '0' && b=='0')
		return '0';
	else if(a == '1' && b =='1')
		return '0';
	else
		return '1';
}
string divide(string message,string generator){
	string remainder(message.size(),'-');
	int pos;
	pos = message.find('1');
	while(pos<(message.size()-16)){		
		cout<<"POS is : "<<pos<<endl;
		for (int i = pos ,j=0; /*i < generator.size() &&*/ j<generator.size() ; i++,j++){
			remainder[i]=XOR(message[i],	generator[j]);	
		}
		cout<<"Till  Now remainder is:"<<remainder<<endl;
		pos = message.find('1',pos+1);		
	}
	return(remainder);
}
int main(void){
	vector<bool> v;
	int c;
	//get the message
	string message;
	cout<<"Please enter the Message bit pattern :";
	cin>>message;
	//get a bool vector from the string
	//append the message with 16 zeros
	string message_with_zeros=message+"0000000000000000";
	//get the generator
	string generator("10001000000100001");
	//make the remainder string.
	cout<<"The CRC-CCITT Generator is : "<<generator<<endl;
	cout<<"The message with zeros is  : "<<message_with_zeros<<endl;
	string remainder;
	remainder = divide(message_with_zeros,generator); 
	//max possible length of remainder = 1 less than the generator.
	//get the first position of 1 in the message_with_zeros string.
	cout<<"Remainder is: "<<remainder<<endl;
	string checksum (remainder,remainder.size()-16,16);
	cout<<"checksum :"<<checksum<<endl;

	string message_and_checksum;
	message_and_checksum = message + checksum;
	
	cout<<"Message to be sent to the reciever : "<<message_and_checksum<<endl;

	//AT THE RECIEVER END

	cout<<"Enter the Message recieved by the Reciever:";
	string reciever_message;
	cin>>reciever_message;

	remainder = divide(reciever_message,generator);
	int pos = remainder.find('1');
	if(pos == string::npos){
		cout<<"The message is error FREE !!"<<endl;
	}
	else{
		cout<<"The message contains ERRORS :(\n The Remainder is :"<<remainder<<endl;
	}
	return(0);
}
