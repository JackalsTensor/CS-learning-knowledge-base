bool isPrime(int n){
  if(n<2) return false;
  //优化原理：如果 n 有大于 sqrt(n) 的因数，必然对应一个小于 sqrt(n) 的因数
  for(int i=2;i*i<=n;i++){
    //如果 n 能被 i 整除，说明存在除 1 和自身外的因数，不是质数
    if(n%i==0) return false;
  }
  return true;
}
