#include <pybind11/pybind11.h>

#include <vector>
#include <pybind11/stl.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

using namespace std;
namespace py = pybind11;

class Arithmetics {
public:
  Arithmetics() {}  
  int Arithmetics::divide(int dividend, int divisor) {
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
  
  int Arithmetics::totalHammingDistance(vector<int> nums) {
    auto res = 0;
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
};

namespace py = pybind11;
PYBIND11_MODULE(cmake_example, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------
        .. currentmodule:: cmake_example
    )pbdoc";

  py::class_<Arithmetics>(
                         m, "Arithmetics"
                         )
        .def(py::init<>())
        .def("divide", &Arithmetics::divide)
        .def("totalHammingDistance", &Arithmetics::totalHammingDistance)
        ;

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
