#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("To-Do List Application");
    resize(400, 300);

    // Initialize custom UI elements
    lineEdit = new QLineEdit(this);
    addButton = new QPushButton("Add", this);
    listWidget = new QListWidget(this);
    removeButton = new QPushButton("Remove", this);
    clearAllButton = new QPushButton("Clear All", this);

    // Create layout and add widgets
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(lineEdit);
    topLayout->addWidget(addButton);

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(removeButton);
    bottomLayout->addWidget(clearAllButton);

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(listWidget);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);

    // Connect the signals to the slots
    connect(addButton, &QPushButton::clicked, this, &Widget::on_addButton_clicked);
    connect(removeButton, &QPushButton::clicked, this, &Widget::on_removeButton_clicked);
    connect(clearAllButton, &QPushButton::clicked, this, &Widget::on_clearAllButton_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_addButton_clicked()
{
    QString itemText = lineEdit->text();
    if (itemText.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Cannot add an empty item.");
    } else {
        listWidget->addItem(itemText);
        lineEdit->clear();
    }
}

void Widget::on_removeButton_clicked()
{
    QListWidgetItem *item = listWidget->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Warning", "No item selected for removal.");
    } else {
        delete item;
    }
}

void Widget::on_clearAllButton_clicked()
{
    listWidget->clear();
}
