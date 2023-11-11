#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{   //1. Создание виджета с полем ввода
    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->show();

    //2. Подключение автодополнения
    QStringList wordList;
    wordList << "apple" << "banana" << "cherry";

    QCompleter *completer = new QCompleter(wordList, lineEdit);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    lineEdit->setCompleter(completer);
    //3
    /*
        — Если вы начинаете вводить "a", система предлагает варианты "apple" и "banana".
        — Если вы начинаете вводить "b", система предлагает вариант "banana".
    */
    //4. Дополнительная настройка
    // Метод setCompletionMode устанавливает минимальное количество символов, необходимых для отображения вариантов автодополнения
    // completer->setCompletionMode(QCompleter::PopupCompletion);

    // выбранный вариант автодополнения, используя метод setCompletionPrefix:
    // completer->setCompletionPrefix("app");

    //5. Начало и окончание автодополнения
    // lineEdit->setCompleter(nullptr);
    //connect(lineEdit, &QLineEdit::textChanged, [lineEdit, completer]() {
    // QString text = lineEdit->text();
    //  if (text.endsWith(",") || text.endsWith(" ")) {
    //     lineEdit->setCompleter(completer);
    //      }
    // });

    //6. Префиксный и постфиксный режимы
    //В префиксном режиме автодополнение выполняется всегда при вводе, а в постфиксном режиме автодополнение выполняется, только если введенный текст является префиксом одного из вариантов
    // completer->setCompletionMode(QCompleter::InlineCompletion);

}

Widget::~Widget()
{

}

