#ifndef CELL_H
#define CELL_H

#include <QVariant>
#include <QString>

class XlCell
{
public:
    XlCell(int row, int col, QVariant content);
    XlCell() { };
    const QString &content();
    const QStringList &clearedContent(); // Очищенное от "мусора" и разделенное на строки содержимое ячейки

    int row();
    int col();

private:
    int _row;
    int _col;
    QString _content;
    QStringList _clearedContent;
};

#endif // CELL_H
