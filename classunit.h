#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <unit.h>

class ClassUnit : public Unit
{
public:
    enum AccessModifier { //Список различныех модификаторов доступа
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        ITERNAL,
        PROTECTED_ITERNAL
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;// Вектор строк для хранения текстовых представлений модификаторов доступа
public:
    ClassUnit()=default;
    // Чисто виртуальный метод add для добавления нового элемента в класс
    // Принимает shared_ptr на объект Unit и флаги типа Unit::Flags
    virtual void add(const std::shared_ptr<Unit>& unit, Unit::Flags flags) = 0;
    // Чисто виртуальный метод compile, который возвращает строку
    // Принимает необязательный параметр level, который по умолчанию равен 0
    virtual std::string compile(unsigned int level = 0) const = 0;
protected:
    std::string m_name;//Поле m_name для хранения имени класса
    using Fields = std::vector<std::shared_ptr<Unit>>;// Определяем псевдоним Fields для вектора shared_ptr на объекты Unit
    std::vector<Fields> m_fields;// Вектор m_fields, содержащий векторы Fields,
    //для хранения элементов класса, сгруппированных по модификаторам доступа
};


#endif // CLASSUNIT_H
