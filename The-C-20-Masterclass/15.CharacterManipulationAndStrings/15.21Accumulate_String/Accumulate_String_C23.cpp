//Чтобы соединить список строк разделителем нужно просто написать:

//1.через потоки
std::string join(const std::vector<std::string>& vec, const std::string& delimiter) {
    if (vec.empty()){
        return "";
    } 
    std::ostringstream oss;
    oss << vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        oss << delimiter << vec[i];
    }
    return oss.str();
}

//2. через std::accumulate:
std::string join(const std::vector<std::string>& vec, const std::string& delimiter) {
    if (vec.empty()){
        return "";
    }
    
    return std::accumulate(
                std::next(vec.begin()), vec.end(),
                vec[0],
                [&delimiter](const std::string& a, const std::string& b) {
                    return a + delimiter + b;
                    }
    );
}
//С++23 наконец-то появилось хоть что-то похожее на адекватное решение. Используем std::views::join_with
std::string join(const std::vector<std::string> &vec, const std::string &delimiter) {

    return vec | std::views::join_with(delimiter) | std::ranges::to<std::string>();
}
