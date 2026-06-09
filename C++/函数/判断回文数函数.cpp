bool isPalindrome(int x){
	int t=x,rev=0;
	while(t){
		rev=rev*10+t%10;
		t/=10;
	}
	return rev==x;
}
