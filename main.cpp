#include "dialog.h"
#include <QApplication>
int main(int argc, char *argv[])
{
	QCoreApplication::addLibraryPath("\plugins");
	QCoreApplication::addLibraryPath("\bin");
	QCoreApplication::addLibraryPath("\imageformats");
	QCoreApplication::addLibraryPath("\platforms");
	//UI basic parameter


	//get information

	//show UI
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
