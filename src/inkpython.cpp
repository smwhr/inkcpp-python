#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_inkpython(py::module &);

namespace mcl {

PYBIND11_MODULE(inkpython, m) {
    // Optional docstring
    m.doc() = "InkPython";
    
    init_inkpython(m);
}
}