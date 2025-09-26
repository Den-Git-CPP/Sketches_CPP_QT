//Стастья с  t.me/grokaemcpp

//std::chrono::zoned_time, который представляет собой пару из временной метки и временной зоны.
auto now = std::chrono::zoned_time{std::chrono::current_zone(), std::chrono::system_clock::now()};
//Функция std::chrono::current_zone() позволяет получить локальную временную зону.
//Можно также передать имя зоны:
auto msw_time = std::chrono::zoned_time{"Europe/Moscow", std::chrono::system_clock::now()};
//И это все прекрасно работает с std::format, который позволяет информацию о временной точки настолько подробно, насколько это возможно:
std::string get_time_string(const std::chrono::zoned_time<std::chrono::system_clock::duration>& zt) {
    return std::format("{:%Y-%m-%d %H:%M:%S %Z}", zt);
}

std::string get_detailed_time_string(const std::chrono::zoned_time<std::chrono::system_clock::duration>& zt) {
    return std::format("{:%A, %d %B %Y, %H:%M:%S %Z (UTC%z)}", zt);
}

std::cout << "Current time: " << get_time_string(now) << std::endl;
std::cout << "Detailed: " << get_detailed_time_string(now) << std::endl;

std::cout << "Time in Moscow: " << get_time_string(msw_time) << std::endl;
std::cout << "Detailed: " << get_detailed_time_string(msw_time) << std::endl;

// OUTPUT:
// Current time: 2025-09-11 17:50:48.035852842 UTC
// Detailed: Thursday, 11 September 2025, 17:50:48.035852842 UTC (UTC+0000)
// Time in Moscow: 2025-09-11 20:50:48.041000112 MSK
// Detailed: Thursday, 11 September 2025, 20:50:48.041000112 MSK (UTC+0300)
