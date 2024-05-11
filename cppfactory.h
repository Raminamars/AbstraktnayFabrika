#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include <factory.h>
#include <cppclassunit.h>
#include <cppmethodunit.h>
#include <cppprintoperatorunit.h>
#include <unit.h>

class CppFactory: public Factory
{
public:
    CppFactory();
    std::shared_ptr<ClassUnit> createClass(const std::string& name) override{
        return std::make_shared<CppClassUnit>(name);// создание умного указателя
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override{
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) override{
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};

#endif // CPPFACTORY_H
