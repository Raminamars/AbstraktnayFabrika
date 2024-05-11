#include <QCoreApplication>
#include <classunit.h>
#include <methodunit.h>
#include <printoperatorunit.h>
#include <memory>
#include <iostream>
#include <factory.h>

using namespace std;
const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private" };

Factory* getFactory(string language){//для пользователя возращаем указатель
    if (language == "cpp"){
        return new CppFactory();
    }
    if (language == "cs"){
        return new CsFactory();
    }
    if (language == "java"){
        return new JavaFactory();
    }
    return new Factory();
}

std::string generateProgram(string language) {
    Factory* factory = getFactory(language);
    std::shared_ptr<Unit> myClass = factory->createClass("myClass");
    std::shared_ptr<Unit> myMethod1 = factory->createMethod("myMethod1","void", 0);
    std::shared_ptr<Unit> myMethod2 = factory->createMethod("myMethod2","void", MethodUnit::STATIC);
    std::shared_ptr<Unit> myMethod3 = factory->createMethod("myMethod3","void", MethodUnit::VIRTUAL|MethodUnit::CONST);
    std::shared_ptr<Unit> myPrintOperator = factory->createPrintOperator(R"(Hello, world!\n)");
    std::shared_ptr<Unit> myMethod4= factory->createMethod("myMethod4","void",MethodUnit::STATIC);
    myMethod4->add(myPrintOperator,0);
    myClass->add(myMethod1,ClassUnit::PUBLIC);
    myClass->add(myMethod2,ClassUnit::PRIVATE);
    myClass->add(myMethod3,ClassUnit::PUBLIC);
    myClass->add(myMethod4,ClassUnit::PROTECTED);
    return myClass->compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string language;
    std::cin >> language;
    std::cout << generateProgram(language) << std::endl;
    return a.exec();
}
