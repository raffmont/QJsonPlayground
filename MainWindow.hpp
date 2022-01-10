//
// Created by Raffaele Montella on 09/01/22.
//

#ifndef QJSONPLAYGROUND_MAINWINDOW_HPP
#define QJSONPLAYGROUND_MAINWINDOW_HPP

#include <QWidget>
#include "UIObject.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void pushButton_Save_onClick();

private:
    Ui::MainWindow *ui;
    QVector<UIObject *> m_items;
    QJsonObject m_jsonObjectRoot;
};


#endif //QJSONPLAYGROUND_MAINWINDOW_HPP
