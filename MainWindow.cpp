//
// Created by Raffaele Montella on 09/01/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QFile>
#include <QJsonDocument>
#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "UIObject.hpp"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QFile jsonFile("/Users/raffaelemontella/CLionProjects/fairwindplusplus/cmake-build-debug/data/it.uniparthenope.fairwind.apps.chart/config.json");
    jsonFile.open(QFile::ReadOnly);
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFile.readAll());
    jsonFile.close();

    m_jsonObjectRoot = jsonDocument.object();

    for (const auto& key:m_jsonObjectRoot.keys()) {
        qDebug() << "key:" << key;
        QJsonValueRef ref = m_jsonObjectRoot[key];
        auto *uiJsonObject = new UIObject(nullptr, ref,key);
        ui->verticalLayout->addWidget(uiJsonObject);
        m_items.append(uiJsonObject);
    }

    connect(ui->pushButton_Save,&QPushButton::clicked,this,&MainWindow::pushButton_Save_onClick);

}

MainWindow::~MainWindow() {

    for (const auto item:m_items) {
        delete item;
    }

    delete ui;
}

void MainWindow::pushButton_Save_onClick() {
    QFile jsonFile("/Users/raffaelemontella/Desktop/config.json");
    jsonFile.open(QFile::WriteOnly);
    QJsonDocument jsonDocument = QJsonDocument(m_jsonObjectRoot);
    jsonFile.write(jsonDocument.toJson());
    jsonFile.close();
}

