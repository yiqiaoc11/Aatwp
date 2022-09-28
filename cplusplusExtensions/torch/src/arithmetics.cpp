#include<vector>
using namespace std;

int16 divide(int16 dividend, int16 divisor, int16 qval) {
  int res = 0;
  bool isNegative = (dividend > 0) ^ (divisor > 0);
  dd = abs(dividend);
  ds = abs(divisor);
  if(dd < ds)
    return res;  
  for(int b=15;b>=0;b--)
    res += (1<<b)?(dd > ds << b):0;
  return res*(-1?isNegative:1);
}
