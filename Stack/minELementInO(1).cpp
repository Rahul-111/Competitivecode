//algo for find min in O(1) time and space complexity
//push
//1. if stack is empty insert x,minElement<-x
//2.if stack is non empty compare x with minElement
//3a. x>=minELement insert x
//3b. x<minElement then insert 2*x-minElement , minElement<-x;
//
//
//Pop
//1.Remove element form y<-top
//2. y>=minElement minELement<-minElement (continue) 
//3. y<minElement do minElement = 2*minElement -y
#include<bits/stdc++.h>
using namespace std;
class Stack{
	stack<int > s;
	int minElement;
	public:
		void push(int x){
			if(s.size()==0){
				s.push(x);
				minElement=x;
			}	
			else{
				if(x>=minElement){
					s.push(x);
				}
				else{
					s.push(2*x-minElement);
					minElement = x;
				}
			}
		}
		int pop(){
			if(s.size()==0)
				return -1;
			int y = s.top();
			s.pop();
			if(y>=minElement)
				minElement = minElement;
			else{
				minElement = 2*(this->minElement) - y;
			}
			return y;
		}
		int pop(){
			//output of pop should be correct
    			if(s.empty())
        			return -1;
    			int k;
    			if(s.top()<minEle){ 
        			int m=minEle;
        			minEle=2*minEle-s.top();
        			k=m;
    			}
    			else
    			k=s.top();
    			s.pop();
    			return k;
		}
		int getMin(){
			if(s.size()==0){
				return -1;
			}
			return minElement;
		}
};
int main(){
	Stack k;
	k.push(18);
	k.push(19);
	k.push(29);
	k.push(15);
	k.push(16);
	
	cout<<"Min "<<k.getMin()<<endl;
	int x=k.pop();
	cout<<"Min = "<<k.getMin()<<endl;
	
	x=k.pop();
	cout<<"Min = "<<k.getMin()<<endl;
	
	x=k.pop();
	cout<<"Min = "<<k.getMin()<<endl;
	return 0;
}
