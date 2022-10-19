# Algorithm Acceleration Toolkit With Pybind
AATWP is a C++ API module that provides advanced algorithm acceleration for python applications in Pytorch/Tensorflow framework. Complexed algorithms logic were implemented upon non-tensor data in low Time/Space complexity with Time/Memory restraints to improve learning, inference, filtering or data preparation to save latency and storage in real-time applications. 

example:
import build.cmake_aatwp

from build.cmake_aatwp import *

cmake .. && make && python3 ../test.py
