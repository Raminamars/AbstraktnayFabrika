#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include<classunit.h>

class CppClassUnit: public ClassUnit
{
public:
    explicit CppClassUnit(const std::string& name) {// Явный конструктор, принимающий имя класса и инициализирующий член m_name
        m_name = name;
        m_fields.resize(ACCESS_MODIFIERS.size());// Изменяем размер вектора m_fields, чтобы он соответствовал количеству модификаторов доступа
    }
    void add(const std::shared_ptr<Unit>& unit, Unit::Flags flags) override {// Переопределенный метод add
        int accessModifier = PRIVATE;// По умолчанию модификатор доступа - PRIVATE
        if(flags < ACCESS_MODIFIERS.size()) {// Если флаги в допустимом диапазоне,то используем их значение как индекс
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);// Добавляем элемент в соответствующий вектор внутри m_fields
    }
    std::string compile(unsigned int level = 0) const override// Переопределенный метод, который возвращает строку,
        //представляющую скомпилированный код класса
    {// Начинаем с генерации отступа и имени класса
        std::string result = generateShift(level) + "class " + m_name + " {\n";
        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {// Перебираем все модификаторы доступа
            if(m_fields[i].empty()) {
                continue;// Пропускаем пустые секции
            }
            result += ACCESS_MODIFIERS[i] + ":\n";// Добавляем модификатор доступа
            for(const auto& f : m_fields[i]) {
                result += f->compile(level + 1);// Компилируем каждый элемент с увеличенным уровнем отступа
            }
            result += "\n";// Добавляем перевод строки после всех элементов текущего модификатора доступа
        }// Закрываем класс и добавляем финальный отступ и перевод строки
        result += generateShift(level) + "};\n";
        return result;// Возвращаем скомпилированный результат
    }
};

#endif // CPPCLASSUNIT_H
