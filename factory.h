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
    // По умолчанию бросает исключение std::runtime_error с сообщением "Language not supported"
    virtual std::shared_ptr<ClassUnit> createClass(const std::string& name){
        throw std::runtime_error("Language not supported");
    }
    virtual std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags){
        throw std::runtime_error("Language not supported");
    }
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text){
        throw std::runtime_error("Language not supported");
    }
};

#endif // FACTORY_H
