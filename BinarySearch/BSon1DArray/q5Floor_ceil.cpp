pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int fl=-1,cl=-1;
	int s=0,e=n-1;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(a[mid]==x)
		 {
			 fl=a[mid];
			 cl=a[mid];
			 break;
		 }
		 else if(a[mid]>x)
		 {
			 cl=a[mid];
			 e=mid-1;
		 }
		 else
		 {
			 fl=a[mid];
			 s=mid+1;
		 }
	}
	return {fl,cl};
}