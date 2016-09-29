//#include <QApplication>
#include <QCoreApplication>
#include "Game.h"
#include "Widgets/Form.h"

int main(int argc, char *argv[])
{
//	QApplication a(argc, argv);
	QCoreApplication a(argc, argv);
	Game g;
	g.StartRound();
	
//	Form f;
//	f.show();
	
	return a.exec();
}
