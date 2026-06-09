int digitCount(int x){
  int cnt=0;
  while(x){
    cnt++;
    x/=10;
  }
  return cnt;
}
