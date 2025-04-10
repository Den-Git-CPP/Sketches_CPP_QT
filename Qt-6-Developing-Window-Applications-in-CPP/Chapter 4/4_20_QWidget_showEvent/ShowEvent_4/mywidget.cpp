#include "mywidget.h"
#include "./ui_mywidget.h"

MyWidget::MyWidget (QWidget* parent) : QWidget (parent), ui (new Ui::MyWidget)
{
    ui->setupUi (this);
    // Create a state machine
    stateMachine = new QStateMachine (this);

    // Create states and transitions
    initialState = new QState ();
    finalState   = new QState ();

    // Connect signals and slots
    connect (initialState, &QState::entered, this, &MyWidget::onInitialStateEntered);
    connect (finalState, &QState::entered, this, &MyWidget::onFinalStateEntered);

    // Set the initial state and start the machine
    stateMachine->setInitialState (initialState);
    stateMachine->start ();
}

MyWidget::~MyWidget ()
{
    delete ui;
}

void MyWidget::showEvent (QShowEvent* event)
{
    // Trigger a transition to the initial state
    stateMachine->emit ("show");
    QWidget::showEvent (event);
}
