#include <QCoreApplication>
#include "Game.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	
	Game g;
	g.StartRound();
	
	return 1;
}
