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

bool isPalindrome(int x)
{
    int i = 0, j = 0, length = 0;
    int* res = NULL;
    if(x < 0)
        return 0;
    
    length = int_length(x);
    res = (int*) malloc(sizeof(int) * length);
    for(i=0; i<length; i++)
    {
        res[i] = x % 10;
        x /= 10;
    }
    for(i=0,j=length-1; i<j; i++,j--)
    {
        if(res[i] != res[j])
            return 0;
    }
    return 1;
}

