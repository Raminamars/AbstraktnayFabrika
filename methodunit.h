#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <unit.h>
#include <memory>
#include <vector>
#include <classunit.h>

class MethodUnit : public Unit {
public:
    enum Modifier {// Перечисления Modifier, определяющее модификаторы доступа, в виде битовых флагов.
        STATIC = 1,
        CONST = 1 << 1,//сдвиг бита на 1 влево: = 10
        VIRTUAL = 1 << 2,//сдвиг бита на 2 влево: = 100.
        FINAL = 1 << 3,//для java сдвиг бита на 3 влево: = 1000. Модификатор final используется для завершения реализации методов
        ABSTRACT = 1 << 4,
        SYNCHRONIZED = 1 << 5,
        VOLATILE = 1 << 6
        // может быть доступен только одним потоком одновременно
    };
public:
    virtual void add(const std::shared_ptr<Unit>& unit, Unit::Flags  = 0) = 0;// Переопределение add() из базового класса Unit
    virtual std::string compile(unsigned int level = 0) const = 0;// Переопределение compile() из базового класса Unit
    // Компилирует метод в строковое представление
protected:
    std::string m_name;// Имя метода
    std::string m_returnType;// Тип возвращаемого значения метода
    Flags m_flags;// Флаги модификаторов метода, представленные битовой маской
    std::vector<std::shared_ptr<Unit>> m_body;// Вектор, содержащий тело метода (список единиц Unit)
};
#endif // METHODUNIT_H
