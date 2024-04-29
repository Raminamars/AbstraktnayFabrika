#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <unit.h>
#include <memory>
#include <vector>

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    virtual void add( const std::shared_ptr< Unit >& unit, Flags flags ) = 0;
    virtual std::string compile( unsigned int level = 0 ) const = 0;
protected:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};


#endif // CLASSUNIT_H
