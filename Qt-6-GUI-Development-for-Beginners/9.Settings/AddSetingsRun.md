site:https://evileg.com/en/post/168/
## Write an application to autostart
~~~~~~~~~~~~~~~~~~
#ifdef Q_OS_WIN32
    QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    settings.setValue(APPLICATION_NAME, QDir::toNativeSeparators(QCoreApplication::applicationFilePath()));
    settings.sync();
#endif
~~~~~~~~~~~~~~~~~

## Delete an application from the startup
~~~~~~~~~~~~
#ifdef Q_OS_WIN32
    QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    settings.remove(APPLICATION_NAME);
#endif
~~~~~~~~~~~~~~
