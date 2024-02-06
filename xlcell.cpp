#include <QRegularExpression>

#include "xlcell.h"

XlCell::XlCell(int row, int col, QVariant content)
{
    _row = row;
    _col = col;
    _content = content.toString();
    _clearedContent = content.toString().remove("_x000D_").split("\n");
}

const QString &XlCell::content()
{
    return _content;
}

const QStringList &XlCell::clearedContent()
{
    return _clearedContent;
}

int XlCell::row()
{
    return _row;
}

int XlCell::col()
{
    return _col;
}
