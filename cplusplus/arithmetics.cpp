
  int Arithmetics::divide(at::Tensor dividend, at::Tensor divisor) {
    int dividend = dividend.data<int>()();
    int divisor = divisor.data<int>();
    auto res = 0;
    bool isNegative = (dividend > 0) ^ (divisor > 0);
    dd = abs(dividend);
    ds = abs(divisor);
    if(dd < ds)
      return res;
    for(int b=sizeof(int)*8-1;b>=0;b--) {
      if(dd > ds<<b) {
        res += 1<<b;
        dd -= ds<<b;
      }
    }
    return res*-1?isNegative:res;
  }
  
  int Arithmetics::totalHammingDistance(at::Tensor input) {
    auto res = 0;    
    vector<int> nums(input.data_ptr<int>(),input.data_ptr<int>()+input.numel());
    for(int b=0;b<sizeof(int)*8;b++) {
      ones = 0;
      for (auto n: nums) {
        if(0 ^ n>>b)
            ones += 1;
        res += ones*(nums.size()-ones);
      }
    }
    return res
  }
