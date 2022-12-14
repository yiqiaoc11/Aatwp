/* This file is to provide some operation to find maximum or minimum
value with respect to some elements of a given sequence at lowest
Time/Space complexity in measures of big O for users of different
ML platforms like Tensorflow/Pytorch in python/pybind environment. 
Auther: CYQ
*/
#include <pybind11/pybind11.h>

#include <vector>
#include <pybind11/stl.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

using namespace std;
namespace py = pybind11;

class Minmax {
public:
  Minmax() {}
  //find 3 unoverlapped subarray with length k to max their sum
  vector<int> Minmax::maxSumOfThreeSubarrays(<vector> nums, int k) {
    int m1, m2, m3 = 0;
    for(int i=0;i<3*k;i++) {
      if(i<k) {
        r1 += nums[i];
        m1 += nums[i];
      }
      if(i<2*k) {
        m2 += nums[i];
        if(i>=k)
          r2 += nums[i]
      }
      if(i>=2*k) {      
        r3 += nums[i];
        m3 += nums[i];
    }
    int i1, i2, i3 = 0, k, 2*k;
    for(int i=0;i<nums.size()-3*k;i++) {
      r1 += nums[i+k] - nums[i];
      r2 += nums[i+2*k] - nums[i+2*k-k];
      r3 += nums[i+3*k] - nums[i+3*k-k];
      if r1 > m1:
        i1, m1 = i+1, r1            
      if r2 + m1 > m2:
        i2, m2 = i+k+1, r2+m1
      if r3 + m2 > m3:
        i3, m3 = i+2*k+1, r3+m2
        res = vector<int>{i1, i2, i3};
    }
    return res;
  }
};

namespace py = pybind11;
PYBIND11_MODULE(cmake_aatwp, m) {
  m.doc() = R"pbdoc(
                   Pybind11 aatwp plugin
                   -----------------------
                   .. currentmodule:: cmake_aatwp
                   )pbdoc";

  py::class_<Minmax>(
                         m, "Minmax"
                         )
        .def(py::init<>())
        .def("maxSumOfThreeSubarrays", &Minmax::maxSumOfThreeSubarrays)
        ;

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
