#ifndef EXCELHELPER_H
#define EXCELHELPER_H

#include <QString>

#include "xlcell.h"

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

using namespace QXlsx;

// Этот класс содержит в себе только методы для чтения, но не записи, их надо будет добавить, если нужно
class ExcelHelper
{
public:
    ExcelHelper();
    ExcelHelper(const QString &documentPath);
    ~ExcelHelper();

    void setDocument(const QString &documentPath);
    const QString &getDocumentPath();
    QString readCell(int row, int col); // Считать ячейку
    QDate readCellAsDate(int row, int col); // Считать ячейку, как дату
    XlCell getCell(int row, int col); // Получить ячейку (XlCell - тоже самописный вспомогательный класс)
    int getRowCount();

    bool docExists();
private:
    QString m_documentPath;
    Document *m_doc;
};

#endif // EXCELHELPER_H
