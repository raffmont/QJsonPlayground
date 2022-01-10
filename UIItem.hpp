//
// Created by Raffaele Montella on 10/01/22.
//

#ifndef QJSONPLAYGROUND_UIITEM_HPP
#define QJSONPLAYGROUND_UIITEM_HPP

#include <QWidget>
#include <QJsonValueRef>
#include "UIObject.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class UIItem; }
QT_END_NAMESPACE

class UIItem : public QWidget {
Q_OBJECT

public:
    explicit UIItem(QWidget *parent, QJsonValueRef mRef);

    ~UIItem() override;

    signals:
    void changed();

private slots:
    void onExpand();
    void onChanged();

private:
    Ui::UIItem *ui;

    QJsonValueRef m_ref;


    QVector<UIObject *> m_items;
    QJsonObject m_jsonObjectRoot;
};


#endif //QJSONPLAYGROUND_UIITEM_HPP
