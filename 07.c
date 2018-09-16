int int_length(int a)
{
  int i = 0;
  while(a != 0)
  {
    i ++;
    a /= 10;
  }
  return i;
}

long dec_power(int x)
{
  long tmp = 1;
  while(x>0)
  {
    tmp *= 10;
    x --;
  }
  return tmp;
}

int reverse(int x)
{
  int i = 0, length = 0, flag = 0;
  int* res = NULL;
  long long ret = 0;
  length = int_length(x);
  res = (int*) malloc(length*sizeof(int));

  if(x < 0)
  {
      x = -x;
      flag = 1;
  }
    
  for(i=0; i<length; i++)
  {
    res[i] = x % 10;
    x /= 10;
  }
      
  if(length == 10 && res[0] > 2)
      return 0;

  for(i=0;i<length;i++)
  {
    ret += res[length-1-i]*dec_power(i); 
  }
  printf("%ld", ret);
  if(ret > 2147483647 || ret < -2147483647)
      return 0;
  if(flag == 1)  
      ret = -ret;
  return (int)ret;
}

