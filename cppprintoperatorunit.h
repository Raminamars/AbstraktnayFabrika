#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H

#include<printoperatorunit.h>

class CppPrintOperatorUnit: PrintOperatorUnit
{
public:
    explicit CppPrintOperatorUnit(const std::string& text) {
        m_text=text;
    }
    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // CPPPRINTOPERATORUNIT_H
