#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H

#include<methodunit.h>

// Класс CppMethodUnit наследуется от MethodUnit и представляет метод на языке C++
class CppMethodUnit : public MethodUnit
{
public:
    // Конструктор, принимающий имя метода, возвращаемый тип и флаги
    CppMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) {
        m_name = name;// Инициализация имени метода
        m_returnType = returnType;// Инициализация возвращаемого типа
        m_flags = flags;// Инициализация флагов
    }
    // Переопределенный метод add для добавления новых элементов в тело метода
    // Принимает shared_ptr на объект Unit и флаги (по умолчанию 0)
    void add(const std::shared_ptr<Unit>& unit, Unit::Flags = 0) override {
        m_body.push_back(unit);// Добавляем элемент в вектор m_body
    }
     // Переопределенный метод compile, который возвращает строку, представляющую скомпилированный код метода
    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level); // Генерируем отступ в зависимости от уровня
         // Проверяем флаги и добавляем соответствующие спецификаторы (static или virtual)
        if(m_flags & STATIC) {
            result += "static ";
        } else if(m_flags & VIRTUAL) {
            result += "virtual ";
        }// Добавляем возвращаемый тип, имя метода и параметры (в данном случае, параметры пустые)
        result += m_returnType + " ";
        result += m_name + "()";
        if(m_flags & CONST) {// Проверяем флаг CONST и добавляем соответствующий спецификатор
            result += " const";
        }
        result += " {\n";// Начинаем тело метода
        for(const auto& b : m_body) {// Компилируем каждый элемент тела метода с увеличенным уровнем отступа
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n"; // Закрываем тело метода и добавляем финальный отступ и перевод строки
        return result;// Возвращаем скомпилированный результат
    }
};

#endif // CPPMETHODUNIT_H
