#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include <unit.h>
#include <methodunit.h>
#include <classunit.h>
#include <printoperatorunit.h>

class Factory
{
public:
    virtual std::shared_ptr<ClassUnit> createClass(const std::string& name);
    virtual std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags);
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text);
};

#endif // FACTORY_H
