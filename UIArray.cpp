//
// Created by Raffaele Montella on 10/01/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UIArrayDisplays.h" resolved

#include <QJsonArray>
#include <QLabel>
#include "UIArray.hpp"
#include "ui_UIArray.h"
#include "UIItem.hpp"


UIArray::UIArray(QWidget *parent, QJsonValueRef mRef) :
        QWidget(parent), ui(new Ui::UIArray), m_ref(mRef) {
    ui->setupUi(this);

    m_jsonArray = m_ref.toArray();
    for (QJsonValueRef item:m_jsonArray) {
        if (item.isObject()) {
            auto *uiItem = new UIItem(nullptr,item);
            ui->verticalLayout_Container->addWidget(uiItem);
            m_uiItems.append(uiItem);

            connect(uiItem,&UIItem::changed, this, &UIArray::onChanged);
        }
    }
}

UIArray::~UIArray() {
    for (auto item:m_uiItems) {
        delete item;
    }
    delete ui;
}

void UIArray::onChanged() {
    qDebug() << "UIArray::onChanged()";
    m_ref = m_jsonArray;
}



