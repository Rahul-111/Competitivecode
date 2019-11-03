class Solution {
public:
    int maxArea(vector<int>& height) {
	int n;
	n=height.size();
	
	int minHeight=height[0],maxHeight=height[0];
	for(int i=1;i<n;i++){
		minHeight = min(minHeight,height[i]);
		maxHeight = max(maxHeight,height[i]);
	}

	int ans=0;
	for(int j=minHeight;j<=maxHeight;j++){
		int l,r;
		for(int i=0;i<n;i++){
			if(height[i]>=j){
				l=i;
				break;
			}
		}
		
		for(int i=n-1;i>=0;i--){
			if(height[i]>=j){
				r=i;
				break;
			}
		}
        if(l<r)
		 ans = max(ans,abs(l-r)*j);
	}
        return ans;
    }
};
// two pointer approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l,r;
        l=0,r=height.size()-1;
        int area=0;
        while(l<r){
            area = max(area,min(height[l],height[r])*(r-l));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return area;
    }
};
