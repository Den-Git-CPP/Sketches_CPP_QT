1. #include<QTimer>;
2. QTimer *timer;
3. {
  timer = new QTimer(this); //  создать таймер
  timer->setInterval(300);  //  установить интервал мс
  connect(timer, &QTimer::timeout, [=]() {
    toogleLights(); //  запускаемая функция
  });
  timer->start(); // запсутить класс
}

/*
 * Qt c++ Вычисление времени выполнения функции, программы
 */

{ // через std::chrono:
  auto tc1 = std::chrono::high_resolution_clock::now();
  // вычисления
  Sleep(100);
  // ..........
  auto tc2 = std::chrono::high_resolution_clock::now();
  qDebug() << "elapsed time std::chrono:"
           << QLocale().toString(
                  std::chrono::duration_cast<std::chrono::microseconds>(tc2 -
                                                                        tc1)
                      .count())
           << "мкс";
}

{ // через QElapsedTimer:
  QElapsedTimer ta1;
  ta1.start();
  // вычисления
  Sleep(100);
  // ..........
  qDebug() << "elapsed time QElapsedTimer:"
           << QLocale().toString(ta1.nsecsElapsed()) << "нс";
}

{ // через ipp:
  Ipp32s CPUFreq;
  ippGetCpuFreqMhz(&CPUFreq);
  Ipp64u tb1 = ippGetCpuClocks();
  // вычисления
  Sleep(100);
  // ..........
  Ipp64u tb2 = ippGetCpuClocks();
  qDebug() << "elapsed time ipp:"
           << QLocale().toString((tb2 - tb1) / (Ipp64f)CPUFreq) << "мкс";
}

{ // через QueryPerformanceCounter:
  LARGE_INTEGER frequency;
  QueryPerformanceFrequency(&frequency);
  LARGE_INTEGER td1;
  LARGE_INTEGER td2;
  QueryPerformanceCounter(&td1);
  // вычисления
  Sleep(100);
  // ..........
  QueryPerformanceCounter(&td2);
  qDebug() << "elapsed time QueryPerformanceCounter:"
           << QLocale().toString((double)(td2.QuadPart - td1.QuadPart) /
                                 frequency.QuadPart)
           << "c";
}

{ // через GetTickCount64:
  ULONGLONG te1 = GetTickCount64();
  // вычисления
  Sleep(100);
  // ..........
  ULONGLONG te2 = GetTickCount64();
  qDebug() << "elapsed time GetTickCount64:" << QLocale().toString(te2 - te1)
           << "мс";
}