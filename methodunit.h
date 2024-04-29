#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <unit.h>
#include <memory>
#include <vector>
#include <classunit.h>

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags
                                                                           flags );
    virtual void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) = 0;
    virtual std::string compile( unsigned int level = 0 ) const = 0;
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};
#endif // METHODUNIT_H
