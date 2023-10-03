### QT StyleSheet templates ###
Themes available:

## MacOS  Theme ##
## Ubuntu Theme ##
## Aqua    Theme ##
## NeonButtons Theme ##


Use StyleSheet:
 QFile file("stylesheet.qss");
 file.open(QFile::ReadOnly);
 QString styleSheet = QLatin1String(file.readAll());
 qApp->setStyleSheet(styleSheet);