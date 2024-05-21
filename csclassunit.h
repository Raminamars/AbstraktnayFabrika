#ifndef CSCLASSUNIT_H
#define CSCLASSUNIT_H

#include<classunit.h>

class CsClassUnit: public ClassUnit
{
public:
    explicit CsClassUnit(const std::string& name) {
        m_name = name;
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
    void add(const std::shared_ptr<Unit>& unit, Unit::Flags flags) override {
        int accessModifier = PRIVATE;
        if(flags < ACCESS_MODIFIERS.size()) {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }
    std::string compile(unsigned int level = 0) const override
    {
        std::string result = generateShift(level) + "class " + m_name + " {\n";
        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            if(m_fields[i].empty()) {
                continue;
            }
            for(const auto& f : m_fields[i]) {
                result += ACCESS_MODIFIERS[i];
                result += f->compile(level + 1);
            }
            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }
};
#endif // CSCLASSUNIT_H
