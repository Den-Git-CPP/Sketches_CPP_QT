1. #include <QTimer>
2. QTimer * timer;
3.  {
        timer = new QTimer(this);   //  создать таймер
        timer->setInterval(300);    //  установить интервал мс
        connect(timer,&QTimer::timeout,[=](){
        toogleLights();             //  запускаемая функция
            });
        timer->start();             // запсутить класс
    }
    