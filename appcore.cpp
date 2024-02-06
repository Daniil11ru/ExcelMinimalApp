#include "appcore.h"
#include "excelhelper.h"

Appcore::Appcore(QObject *parent)
    : QObject{parent}
{
    m_engine.rootContext()->setContextProperty("appcore", this); // Передаем в QML-движок ссылку на объект нашего
                                                                 // класса Appcore, чтобы его поля и методы
                                                                 // Были доступны в QML.
    m_engine.addImportPath(":/");
    m_engine.load(QUrl(QStringLiteral("ExcelMinimalApp/Main.qml"))); // Загружаем файл Main.qml,
                                                                     // который содержит в себе главное окно приложения.
}

[[nodiscard]] QString Appcore::readFirstCell(QString docPath) // Не обращай внимание на [[nodiscard]],
                                                              // можешь это не использовать
{
    ExcelHelper eh(docPath); // ExcelHelper - созданный нами вспомогательный класс для работы с Excel
    if (eh.docExists())
        return eh.readCell(1, 1); // В Excel счет ячеек и столбцов начинается с 1
    return "";
}
