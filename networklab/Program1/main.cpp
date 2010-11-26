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
int main(void){
	vector<bool> v;
	int c;
	//get the message
	string message;
	cout<<"Please enter the Message bit pattern";
	cin>>message;
	//get a bool vector from the string
	//vector<bool> message = returnVector(a);
	//printVector(message);
	//append the message with 16 zeros
	string message_with_zeros=message+"0000000000000000";
	//cout<<message_with_zeros<<endl;
	//get the generator
	string generator;
	do{
		generator.erase();//so that the length of the string returns to zero
		cout<<"Please a 17 bit generator";
		cin>>generator;
	}while(17!=generator.size());
	//make the remainder string.
	cout<<message.size()<<endl;
	string remainder = string(GENERATOR_LENGTH,'-');
	//max possible length of remainder = 1 less than the generator.
	//get the first position of 1 in the message_with_zeros string.
	int pos = message.find('1');
	while(pos != string::npos ){
		// string::npos is a static constant == -1 indicating substring not found
		for (int i = pos ,j=0; i < generator.size() ; i++,j++){
			remainder[i]=XOR(message_with_zeros[i],	generator[j]);	
		}

		pos = message.find('1',pos+1);		
	}
	string checksum (remainder,2,16);
	cout<<checksum<<endl;
	//cout<<remainder<<endl;
	//cout<<remainder<<" "<<remainder.size()<<" message with zeros SIZE :"<<message_with_zeros.size()<<endl;
	//bool a=4^1;
	//cout<<a<<endl;
	return(0);
}
