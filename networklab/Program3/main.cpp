#include<iostream>
#include<string>
#include<vector>

using namespace std;

int num;
class router{
	private:

		string adj_old,adj_new;
		vector<int> table_old,table_new;

	public:
		void copy(){
			table_new.assign(table_old.begin(),table_old.end());	
		}
		void build(int i){
			for(int j=0;j<n;j++){
				for(int k=0;(i!=j) && k<n;k++){
					if(table_old[j]!=99){
						if(table_new[j]+r[i].table_new[k] < table_new[k]){
							table_new[k]=table_new[j]+r[i].table_new[k];
							adj_new[k]='A'+j;							
						}	
					}
				}
			}
		}
		void display(){	
			cout<<"DESTINATION ROUTER: \n";
			for(int i=0;i<num;i++)	cout<<'A'+i<<" ";
			cout<<"ADJACENT ROUTER: \n";
			for(int i=0;i<num;i++)  cout<<adj_new[i]<<" ";
			cout<<"HOP COUNT: \n";
			for(int i=0;i<num;i++)  cout<<table_new[i]<<" ";
			cout<<endl;
		}
}r[10];
void build(){
		
}
int main(void){
	
	string a("hello");
	cout<<a+"!"<<endl;
	return 0;
}
