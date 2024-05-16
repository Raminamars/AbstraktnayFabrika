#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include <factory.h>
#include <cppclassunit.h>
#include <cppmethodunit.h>
#include <cppprintoperatorunit.h>
#include <unit.h>

// Класс CppFactory наследуется от Factory и предоставляет конкретные реализации методов для создания объектов C++ классов
class CppFactory: public Factory
{
public:
    // Переопределение метода createClass для создания объекта типа CppClassUnit
    // Принимает имя класса в виде строки и возвращает std::shared_ptr на CppClassUnit
    std::shared_ptr<ClassUnit> createClass(const std::string& name) override{
        return std::make_shared<CppClassUnit>(name);// создание умного указателя на объект CppClassUnit
    }
    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override{
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) override{
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};

#endif // CPPFACTORY_H
