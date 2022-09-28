#include<vector>
#include <torch/extension.h>

using namespace std;

class Arithmetics {
public:
  Arithmetics() {}  
  
  int Arithmetics::divide(int dividend, int divisor) {
    int res = 0;
    bool isNegative = (dividend > 0) ^ (divisor > 0);
    dd = abs(dividend);
    ds = abs(divisor);
    if(dd < ds)
      return res;
    for(int b=15;b>=0;b--) {
      if(dd > ds<<b) {
        res += 1<<b;
        dd -= ds<<b;
      }
    }
    return res*-1?isNegative:res;
  }
  
  int Arithmetics::totalHammingDistance(at::Tensor input) {
    int res = 0;    
    vector<int> nums(input.data_ptr<int>(),input.data_ptr<int>()+input.numel());
    for(int b=0;b<32;b++) {
      ones = 0;
      for (auto n: nums) {
        if(0 ^ n>>b)
            ones += 1;
        res += ones*(nums.size()-ones);
      }
    }
    return res
};

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m)
{
    pybind11::class_<Arithmetics>(m, "Arithmetics")
        .def(pybind11::init<DlQuantization::QuantizationMode>())
        .def("divide", &Arithmetics::divide)
}
