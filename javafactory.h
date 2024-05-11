#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include <factory.h>
#include <javaclassunit.h>
#include <javamethodunit.h>
#include <javaprintoperatorunit.h>
#include <unit.h>

class JavaFactory: public Factory
{
public:
    JavaFactory();
    std::shared_ptr<ClassUnit> createClass(const std::string& name) const {
        return std::make_shared<JavaClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) const {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};

#endif // JAVAFACTORY_H
