#include<bits/stdc++.h>
using namespace std;
void sort_by_marks(int data[][2], int n){
  pair<int, int> *ptr = (pair<int, int>*) data;
  sort(ptr, ptr+n);
}
int main(){
	cout<<"Array"<<endl;
	int arr[4][2]={{0,5},
				 {4,1},
				 {1,3},
				 {2,3}
				};
	sort_by_marks(arr,4);			
//	qsort(arr,4,sizeof(*arr),[](const void *arg1, const void *arg2)->int
//        {
//            int const *lhs = static_cast<int const*>(arg1);
//            int const *rhs = static_cast<int const*>(arg2);
//            return (lhs[0] < rhs[0]) ? -1
//                :  ((rhs[0] < lhs[0]) ? 1
//                :  (lhs[1] < rhs[1] ? -1
//                :  ((rhs[1] < lhs[1] ? 1 : 0))));
//        });
//	
	cout<<"After Sorting"<<endl;
	
	for(int i=0;i<4;i++){
		cout<<arr[i][0]<<"  "<<arr[i][1]<<endl;
	}
}
