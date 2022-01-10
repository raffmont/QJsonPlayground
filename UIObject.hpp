//
// Created by Raffaele Montella on 09/01/22.
//

#ifndef QJSONPLAYGROUND_UIOBJECT_HPP
#define QJSONPLAYGROUND_UIOBJECT_HPP

#include <QWidget>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class UIObject; }
QT_END_NAMESPACE

class UIObject : public QWidget {
Q_OBJECT

public:
    explicit UIObject(QWidget *parent, QJsonValueRef ref, QString key);

    ~UIObject() override;

signals:
    void changed();

public slots:
    void onTextChanged();
    void onArrayDisplaysChanged();
    void onStateChanged(int state);


private:
    QJsonValueRef m_ref;
    QString m_key;
    Ui::UIObject *ui;
    QWidget *m_widget;
};


#endif //QJSONPLAYGROUND_UIOBJECT_HPP
