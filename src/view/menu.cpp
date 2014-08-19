#include "menu.h"

Menu::Menu(QWidget *parent) :
    QMenu(parent)
{
    configureAction = new QAction(tr("Configure"), this);
    quitAction = new QAction(tr("Quit"), this);
    this->addAction(configureAction);
    this->addAction(quitAction);

    connect(configureAction, SIGNAL(triggered()), this, SLOT(configureSlot()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quitSlot()));

}

void Menu::quitSlot() {
    emit quit();
}

void Menu::configureSlot() {
    emit configure();
}
