//
// Created by Raffaele Montella on 09/01/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UIJsonObject.h" resolved

#include <QLineEdit>
#include <utility>
#include <QJsonArray>
#include <QCheckBox>
#include "UIObject.hpp"
#include "ui_UIObject.h"
#include "UIArray.hpp"


UIObject::UIObject(QWidget *parent, QJsonValueRef ref, QString key) :
        QWidget(parent), ui(new Ui::UIObject), m_ref(ref),m_key(std::move(key)) {
    ui->setupUi(this);

    ui->labelKey->setText(m_key);

    if (m_ref.isString()) {
        auto *widget = new QLineEdit();
        widget->setText(m_ref.toString());
        ui->verticalLayout_Value->addWidget(widget);

        connect(widget,&QLineEdit::textChanged, this, &UIObject::onTextChanged);

        m_widget = widget;
    } else if (m_ref.isBool()) {
        auto *widget = new QCheckBox();
        widget->setText("");
        widget->setChecked(m_ref.toBool());
        ui->verticalLayout_Value->addWidget(widget);

        connect(widget,&QCheckBox::stateChanged, this, &UIObject::onStateChanged);

        m_widget = widget;
    } else if (m_ref.isArray()) {
        auto *widget = new UIArray(nullptr, m_ref);
        ui->verticalLayout_Value->addWidget(widget);
        connect(widget,&UIArray::changed, this, &UIObject::onArrayDisplaysChanged);
        m_widget = widget;
    }

}

UIObject::~UIObject() {
    delete m_widget;
    delete ui;
}

void UIObject::onTextChanged() {
    qDebug()  << "UIObject::onTextChanged()";
    auto *widget = (QLineEdit *)m_widget;
    QString text = widget->text();
    m_ref = text;
    qDebug() << "m_ref:" << m_ref;
    emit changed();

}

void UIObject::onArrayDisplaysChanged() {
    qDebug()  << "UIObject::onArrayDisplaysChanged()";
    emit changed();
}

void UIObject::onStateChanged(int state) {
    qDebug()  << "UIJsonObject::onStateChanged(" << state << ")";
    auto *widget = (QCheckBox *)m_widget;
    m_ref = widget->isChecked();
    qDebug() << "m_ref:" << m_ref;
    emit changed();
}


