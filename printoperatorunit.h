#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include <unit.h>

class PrintOperatorUnit : public Unit {
public:
    virtual std::string compile(unsigned int level = 0) const = 0 ;// Переопределение чисто виртуальной функции compile() из базового класса Unit
    // Эта функция должна быть реализована в производных классах и возвращать
    // строковое представление печатающего оператора
protected:
    std::string m_text;// Текст, который будет выведен этим печатающим оператором
};
#endif // PRINTOPERATORUNIT_H
