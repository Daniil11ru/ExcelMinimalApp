#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "appcore.h"

// Все, что делает эта демонстрационная программа - это выводит на экран содержимое первой ячейки Excel-файла

// В main создается объект "главного" класса Appcore и запускается приложение.
// В конструкторе Appcore загружается главное окно (файл Main.qml).
// В Main.qml описан интерфейс главного окна и происходит вызов метода в Appcore для получения
// значения первой ячейки файла doc.xlsx.

// Для работы программы необходимо поместить файл doc.xlsx (есть в репозитории) в директорию билда
// (build-ExcelMinimalApp-...)

// Точка входа в программу, как и обычно
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QGuiApplication app(argc, argv); // Объект Qt-приложения с графическим интерфейсом
    Appcore appcore; // Объект созданного нами класса, который частично управляет логикой приложения
                     // и предоставляет вспомогательные методы

    app.setApplicationName("ExcelMinimalApp");

    return app.exec(); // Запуск приложения
}
