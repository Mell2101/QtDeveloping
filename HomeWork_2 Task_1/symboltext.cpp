#include "symboltext.h"

SymbolText::SymbolText(QString syb)
{
    str = syb;

}

QString SymbolText::pasteSymbol()
{
    QString symbol;
    if(str == "RUB")
    {
        return symbol = "₽";
    }
    else if(str == "EUR")
    {
        return symbol = "€";
    }
    else if(str == "PROM")
    {
        return symbol = "‰";
    }
    else if(str == "AUTH")
    {
        return symbol = "©";
    }
    else
    {
        return symbol = str;
    }

}

