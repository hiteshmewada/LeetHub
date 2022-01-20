// { Driver Code Starts
//Initial Template for C

#include<stdio.h>


 // } Driver Code Ends
//User function Template for C

int binary_to_decimal(char str[])
{
		    // Code here.
    int n=strlen(str),a=0,b=0;
    for(int i=n-1;i>=0;i--){
        if(str[i]=='1'){
            b+=pow(2,a);
        }
        a++;
    }
    return b;
}

// { Driver Code Starts.

int main(){
    int T;
    scanf("%d", &T);
    while(T--)
    {
    	char str[10000];
    	scanf("%s", &str);
    	int  ans = binary_to_decimal(str);
    	printf("%d\n", ans);
    }
	return 0;
}  // } Driver Code Ends