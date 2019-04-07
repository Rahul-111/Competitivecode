#include<iostream>
using namespace std;
void generateParenthesis(int index,int n,int open,int close,char output[]){
	if(index == 2*n){
		output[index]='\0';
		cout<<output<<endl;
		return ;
	}
	
	if(open <n){
		output[index]='(';
		generateParenthesis(index+1,n,open+1,close,output);
	}
	if(close<open){
		output[index]=')';
		generateParenthesis(index+1,n,open,close+1,output);
	}
}
int main(){
	int n;
	char output[100];
	cin>>n;
	generateParenthesis(0,n,0,0,output);
	
	return 0;
}
