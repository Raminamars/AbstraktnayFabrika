#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H

#include<printoperatorunit.h>

class CppPrintOperatorUnit: public PrintOperatorUnit
{
public:
    explicit CppPrintOperatorUnit(const std::string& text) {// Конструктор, принимает текст, выводимый печатающим оператором
        m_text=text;
    }
    // Переопределение виртуальной функции compile() из базового класса PrintOperatorUnit
    // Возвращает строковое представление на C++ печатающего оператора printf()
    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";// генерация отступа с заданным уровнем вложенности и текста m_text
    }
};

#endif // CPPPRINTOPERATORUNIT_H
