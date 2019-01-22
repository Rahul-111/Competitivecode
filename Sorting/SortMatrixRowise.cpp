#include<bits/stdc++.h>
using namespace std;
class Compare {
public:
    Compare(int col) : col_(col) {}
    bool operator()(std::vector<int >& lhs, std::vector<int >& rhs) {
        return lhs[col_] < rhs[col_];
    }
private:
    int col_; 
};
void sortrows(std::vector<std::vector<int > >& matrix, int col) {    
    std::sort(matrix.begin(),
              matrix.end(),
              Compare(col));
}
int main(){
	vector<vector<int > > v;
	int n=4;
	int x;
	cout<<"Enter the element of vector\n";
	for(int i=0;i<n;i++){
		vector<int > row;
		for(int j=0;j<3;j++){
			int x;
			cin>>x;
			row.push_back(x);
		}
		v.push_back(row);
	}
	sortrows(v,1);
	cout<<"\n After sorting wrt 2 col"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cout<<v[i][j]<<"\t";
		}
		cout<<endl;
	}
	sortrows(v,1);
}
