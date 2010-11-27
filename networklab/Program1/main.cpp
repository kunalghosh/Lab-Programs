//Program to perform CRC generation and error detection
//For the CRC-CCITT 16 bit checksum.

#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

#define GENERATOR_LENGTH 17

/*
void printVector(vector<bool> test){
	for(int i=0;i!=test.size();i++){
		cout<<test[i];
	}
	cout<<endl;
}

vector<bool> returnVector(string a){
	
	vector<bool> v;
	for(int i=0;i!=a.size();i++){    
		int temp = int(a[i])-int('0');
		v.push_back(temp);
	}
	return v;

}
*/

char XOR(char a , char b){
	if(a == '0' && b=='0')
		return '0';
	else if(a == '1' && b =='1')
		return '0';
	else
		return '1';
}
string divide(string message,string generator){
	//string remainder(GENERATOR_LENGTH,'-');
	string remainder(message.size(),'-');
	//cout<<remainder<<endl;
	//cout<<"POS is : "<<pos<<endl;
	int pos;
	pos = message.find('1');
	while(/*pos != string::npos && */pos<(message.size()-16)){		
		cout<<"POS is : "<<pos<<endl;
		// string::npos is a static constant == -1 indicating substring not found
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
	//vector<bool> message = returnVector(a);
	//printVector(message);
	//append the message with 16 zeros
	string message_with_zeros=message+"0000000000000000";
	//cout<<message_with_zeros<<endl;
	//get the generator
	string generator("10001000000100001");
	/*do{
		generator.erase();//so that the length of the string returns to zero
		cout<<"Please a 17 bit generator :";
		cin>>generator;
	}while(17!=generator.size());*/
	//make the remainder string.
	//cout<<message.size()<<endl;
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



	//cout<<remainder<<endl;
	//cout<<remainder<<" "<<remainder.size()<<" message with zeros SIZE :"<<message_with_zeros.size()<<endl;
	//bool a=4^1;
	//cout<<a<<endl;
	return(0);
}
