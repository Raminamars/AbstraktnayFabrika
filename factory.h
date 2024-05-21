#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include <unit.h>
#include <methodunit.h>
#include <classunit.h>
#include <printoperatorunit.h>

// Класс Factory является абстрактной фабрикой для создания различных компонентов программы
class Factory
{
public:
    // Виртуальный метод для создания объекта типа ClassUnit
    // Принимает имя класса в виде строки и возвращает shared_ptr на ClassUnit
    virtual std::shared_ptr<ClassUnit> createClass(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) = 0;
    virtual ~Factory() = default; // Виртуальный деструктор
};

#endif // FACTORY_H
