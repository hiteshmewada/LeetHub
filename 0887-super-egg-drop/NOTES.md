int brk;// if egg is breaking at this floor then next floor might save
// int brk=f(e-1,k-1);
if(dp[e-1][k-1]!=-1){
brk=dp[e-1][k-1];
}
else{
brk=find(e-1,k-1);
dp[e-1][k-1]=brk;
}
int save;
if(dp[e][f-k]!=-1){
save=dp[e][f-k];
}
else{
save=find(e,f-k);
dp[e][f-k]=save;
}
int temp=max(brk,save);
ans=min(ans,temp+1);
}
return dp[e][f]=ans;
}
int superEggDrop(int k, int n) {
memset(dp,-1,sizeof(dp));
return find(k,n);
}
};
​
Binary Memo
​