// #include "../inkcpp/include/story.h"
#include "story_wrapper.h"

#include <pybind11/stl.h>

#include <pybind11/pybind11.h>
namespace py = pybind11;

void init_inkpython(py::module &m) {

    py::class_<inkpython::StoryWrapper>(m, "Story")
	   .def(py::init<std::string>(), py::arg("filename"))
    .def("can_continue",
         py::overload_cast<>( &inkpython::StoryWrapper::can_continue, py::const_))
    .def("has_choices",
         py::overload_cast<>( &inkpython::StoryWrapper::has_choices, py::const_))
    .def("has_tags",
         py::overload_cast<>( &inkpython::StoryWrapper::has_tags, py::const_))
    .def("tags",
         py::overload_cast<>( &inkpython::StoryWrapper::tags, py::const_))
    .def("getline",
         py::overload_cast<>( &inkpython::StoryWrapper::getline))
    .def("choices",
         py::overload_cast<>( &inkpython::StoryWrapper::choices, py::const_))
    .def("choose",
         py::overload_cast<int>( &inkpython::StoryWrapper::choose),
         py::arg("index"))
    ;


    py::class_<ink::runtime::choice>(m, "Choice")
	  .def("index",
         py::overload_cast<>( &ink::runtime::choice::index, py::const_))
	  .def("text",
         py::overload_cast<>( &ink::runtime::choice::text, py::const_));

}