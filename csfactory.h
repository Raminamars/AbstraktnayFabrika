#ifndef CSFACTORY_H
#define CSFACTORY_H

#include <factory.h>
#include <csclassunit.h>
#include <csmethodunit.h>
#include <csprintoperatorunit.h>
#include <unit.h>

class CsFactory: public Factory
{
public:
    CsFactory() = default;
    ~CsFactory()= default;
    std::shared_ptr<ClassUnit> createClass(const std::string& name) const {
        return std::make_shared<CsClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
        return std::make_shared<CsMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperator(const std::string& text) const {
        return std::make_shared<CsPrintOperatorUnit>(text);
    }
};

#endif // CSFACTORY_H
