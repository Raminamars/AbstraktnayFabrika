#ifndef UNIT_H
#define UNIT_H

#include <memory>// Включаем заголовок для работы с умными указателями std::shared_ptr
#include <QCoreApplication>// Включаем заголовок для основного класса приложения Qt
#include <iostream>// Включаем заголовок для работы с потоками ввода-вывода

class Unit {
public:
    using Flags = unsigned int;// Определяем тип Flags как unsigned int, который будет использоваться для флагов
public:
    virtual ~Unit() = default;//Для гарантии корректного разрушения объектов
    //производных классов при удалении через указатель на базовый класс.
    virtual void add(const std::shared_ptr<Unit>& , Unit::Flags) { //Ф-я для добавления дочернего элемента в объект Unit
        throw std::runtime_error("Not supported");// По умолчанию throw генерирует исключение типа runtime_error с сообщением,
        //что операция не поддерживается или не может быть выполнена
    }
    virtual std::string compile(unsigned int level = 0) const =0;//Чисто виртуальная метод для компиляции объекта Unit в строковое представление
    // Должен быть переопределен в производных классах
protected:
    virtual std::string generateShift(unsigned int level) const//Метод генерирует строку, состоящую из пробелов, количество которых
    // зависит от значения параметра level.
    {
        static const auto DEFAULT_SHIFT = " ";// Константа, определяющая строку, используемую для отступа.
        std::string result;
        for(unsigned int i = 0; i < level; ++i) {//цикл для генерации строки с отступами. За каждый уровень добавляется один пробел.
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};
#endif // UNIT_H
// shared_ptr <Unit> - умный указатель, который управляет временем жизни объекта типа Unit. Он является счетчиком ссылок
// для отслеживания кол-ва владельцев объекта и автоматически удаляет объект, когда последний владелец перестает ссылаться на него.
