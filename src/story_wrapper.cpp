#include "story_wrapper.h"
#include "story.h"
#include "runner.h"

#include <list>
#include <string>
#include <iostream>
#include <stdexcept>


#include <pybind11/pybind11.h>
namespace py = pybind11;

namespace inkpython {

StoryWrapper::StoryWrapper(std::string filename) {

    try
    {
        
        int foundAt = filename.find(".json");
        if (foundAt == filename.length() - 5){
            std::cerr 
                << "You must firt compile to binary format using inkcpp_cl : " 
                << std::endl
                << " $ inkcpp_cl "
                <<  filename.c_str()
                << std::endl
                ;
            throw std::invalid_argument("cannot read json input");

        }else{
            _filename = filename;
        }

        using namespace ink::runtime;
        story* myInk = story::from_file(_filename.c_str());
        _thread = myInk->new_runner();    
        

    }
    catch (const std::exception& e)
    {
        std::cerr << "Unhandled ink runtime exception: " << e.what() << std::endl;
    }
        
}

bool StoryWrapper::can_continue() const {
    return _thread->can_continue();
}

std::string StoryWrapper::getline(){
    return _thread->getline();
}

bool StoryWrapper::has_tags() const {
    return _thread->has_tags();
}

std::list<std::string> StoryWrapper::tags() const{

    std::list<std::string> tagSet;

    for (int i = 0; i < _thread->num_tags(); ++i) {
        tagSet.insert(tagSet.begin(), _thread->get_tag(i));
    }
    tagSet.reverse();
    return tagSet;
}

bool StoryWrapper::has_choices() const {
    return _thread->has_choices();
}

std::list<ink::runtime::choice> StoryWrapper::choices() const{

    std::list<ink::runtime::choice> choiceSet;

    for (const ink::runtime::choice& c : *_thread){
        choiceSet.insert(choiceSet.begin(), c);
    }
    choiceSet.reverse();

    return choiceSet;
}

void StoryWrapper::choose(int index) {
    return _thread->choose(index - 1);
}

}