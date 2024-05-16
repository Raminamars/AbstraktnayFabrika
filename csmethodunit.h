#ifndef CSMETHODUNIT_H
#define CSMETHODUNIT_H

#include<methodunit.h>

class CsMethodUnit: public MethodUnit
{
public:
    CsMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) {
        m_name = name;
        m_returnType = returnType;
        m_flags = flags;
    }
    void add(const std::shared_ptr<Unit>& unit, Unit::Flags /* flags */ = 0) override {
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level);
        if(m_flags & STATIC) {
            result += "static ";
        } else if(m_flags & VIRTUAL) {
            result += "final ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        if(m_flags & CONST) {
            result += " const";
        }
        result += " {\n";
        for(const auto& b : m_body) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
        return result;
    }
};

#endif // CSMETHODUNIT_H
