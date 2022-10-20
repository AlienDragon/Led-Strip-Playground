#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QVBoxLayout>


class Sidebar : public QWidget
{
    Q_OBJECT
public:
    explicit Sidebar(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;


signals:


private:
    QVBoxLayout *layout;

};

#endif // SIDEBAR_H
