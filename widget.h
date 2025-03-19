#ifndef WIDGET_H
#define WIDGET_H
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>
#include <QListWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_clearAllButton_clicked();

private:
    Ui::Widget *ui;

    // Custom UI elements
    QLineEdit *lineEdit;
    QPushButton *addButton;
    QListWidget *listWidget;
    QPushButton *removeButton;
    QPushButton *clearAllButton;
};

#endif // WIDGET_H
