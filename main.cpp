#include <QCoreApplication>
#include <classunit.h>
#include <methodunit.h>
#include <printoperatorunit.h>
#include <memory>
#include <iostream>
#include <factory.h>
#include <cppfactory.h>
#include <javafactory.h>
#include <csfactory.h>

using namespace std;

//Вектор строк, содержащий различные модификаторы доступа
const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private", "private protected", "file", "iternal", "protected iternal"};

// Функция, возвращающая указатель на объект фабрики в зависимости от выбранного языка
Factory* getFactory(string language){//для пользователя возращаем указатель
    // Создаем объект фабрики в зависимости от переданного языка
    if (language == "cpp"){
        return new CppFactory();
    } else if (language == "cs"){
        return new CsFactory();
    } else if (language == "java"){
        return new JavaFactory();
    } else {
        // Если язык не распознан, возвращаем базовый объект фабрики
        throw std::runtime_error("Error: Unsupported language\n");
    }
}

// Функция, генерирующая программу на основе выбранного языка
std::string generateProgram(string language) {
    try {
        Factory* factory = getFactory(language);// Создаем объект фабрики для выбранного языка
        // Создаем различные элементы программы с помощью фабрики
        std::shared_ptr<Unit> myClass = factory->createClass("myClass");
        std::shared_ptr<Unit> myMethod1 = factory->createMethod("myMethod1","void", 0);
        std::shared_ptr<Unit> myMethod2 = factory->createMethod("myMethod2","void", MethodUnit::STATIC);
        std::shared_ptr<Unit> myMethod3 = factory->createMethod("myMethod3","void", MethodUnit::VIRTUAL|MethodUnit::CONST);
        std::shared_ptr<Unit> myPrintOperator = factory->createPrintOperator(R"(Hello, world!)");
        std::shared_ptr<Unit> myMethod4= factory->createMethod("myMethod4","void",MethodUnit::STATIC);
        // Добавляем методы в класс
        myMethod4->add(myPrintOperator,0);
        myClass->add(myMethod1,ClassUnit::PUBLIC);
        myClass->add(myMethod2,ClassUnit::PRIVATE);
        myClass->add(myMethod3,ClassUnit::PUBLIC);
        myClass->add(myMethod4,ClassUnit::PROTECTED);
        return myClass->compile();// Компилируем и возвращаем строковое представление программы
    }
    catch (const std::runtime_error& e) {
        // Обрабатываем исключения, возникающие во время генерации программы
        std::cerr << e.what();//Оператор вывода, для вывода информации об исключении, возникшем во время выполнения программы.
        //Объект `e` является экземпляром класса `std::runtime_error` (или другого производного класса от `std::exception`), который был выброшен в блоке `try`/`catch`.
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    while(1){
        string language;//Переменная в которую будет сохранен язык программирования, выбранный пользователем.
        std::cin >> language;
        std::cout << generateProgram(language) << std::endl;
    }
    return a.exec();
}
