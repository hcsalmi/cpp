#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
    private:

        std::string name;
        std::string title;
        SpellBook _spellbook;
        
        Warlock();
        Warlock(const Warlock &src);
        Warlock &operator=(const Warlock &src);

    public:
        Warlock(const std::string &name, const std::string &title);
        ~Warlock();

        const std::string &getName() const;
        const std::string &getTitle() const;

        void    setTitle(const std::string &title);
        void    introduce() const;

        void    learnSpell(ASpell *spell);
        void    forgetSpell(std::string name);
        void    launchSpell(std::string spell, ATarget &target);
};

#endif
