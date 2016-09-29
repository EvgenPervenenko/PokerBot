#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "Entities/Card.h"

namespace Ui {
	class Form;
}

class Form : public QWidget
{
	Q_OBJECT
	
public:
	explicit Form(QWidget *parent = 0);
	~Form();
	
private slots:
    void on_calculateButton_clicked();

private:
    Entities::Card GetCardBySign( const QString & );

private:
	Ui::Form *ui;
};

#endif // FORM_H
