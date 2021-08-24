#include <string>
#include <list>
#include <types.h>
#include "choice.h"

#ifndef STORYWRAPPER_H
#define STORYWRAPPER_H

namespace inkpython {

class StoryWrapper {

private:

    /// Filename
    std::string _filename;
    ink::runtime::runner _thread;

public:

    /// Constructor
    StoryWrapper(std::string filename);

    /// Get filename

    /// Story can continue
    /// @return bool
    bool can_continue() const;

    /// Story can continue
    /// @return next line
    std::string getline();

    /// Story has tags
    /// @return bool
    bool has_tags() const;

    /// Story tags
    /// @return bool
    std::list<std::string> tags() const;

    /// Story has tags
    /// @return bool
    bool has_choices() const;

    /// Story has tags
    /// @return bool
    std::list<ink::runtime::choice> choices() const;

    /// Story has tags
    /// @return void
    void choose(int index);
};

}

#endif