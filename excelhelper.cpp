#include <QString>
#include <QVector>

#include "excelhelper.h"

[[nodiscard]] bool ExcelHelper::docExists()
{
    return m_doc->load();
}

ExcelHelper::ExcelHelper()
{
    m_doc = new Document();
}

ExcelHelper::ExcelHelper(const QString &documentPath)
{
    m_documentPath = documentPath;
    m_doc = new Document(documentPath);
}

ExcelHelper::~ExcelHelper()
{
    delete m_doc;
}

void ExcelHelper::setDocument(const QString &documentPath)
{
    m_documentPath = documentPath;
    m_doc = new Document(documentPath);
}

[[nodiscard]] const QString &ExcelHelper::getDocumentPath()
{
    return m_documentPath;
}

[[nodiscard]] QString ExcelHelper::readCell(int row, int col)
{
    if (docExists())
    {
        return m_doc->read(row, col).toString();
    }
    else
    {
        qCritical() << "Документ не найден!";
        return "";
    }
}

[[nodiscard]] QDate ExcelHelper::readCellAsDate(int row, int col)
{
    if (docExists())
    {
        QString strDate = m_doc->read(row, col).toString();
        int intDate = strDate.toInt();
        if (intDate != 0)
        {
            QDate baseDate(1900, 1, 1);
            return baseDate.addDays(intDate - 1);
        }
        else
        {
            return QDate::fromString(strDate, "yyyy-MM-dd");
        }
    }
    else
    {
        qCritical() << "Документ не найден!";
        return QDate();
    }
}

int ExcelHelper::getRowCount()
{
    int rowCount = 0;
    if(docExists())
    {
        rowCount = m_doc->dimension().rowCount();
    }
    return rowCount;
}

[[nodiscard]] XlCell ExcelHelper::getCell(int row, int col)
{
    QVariant content;

    if(docExists())
    {
        content = m_doc->read( row, col );
    }
    else
    {
        qCritical() << "Документ не найден!";
    }
    return XlCell(row, col, content);
}
