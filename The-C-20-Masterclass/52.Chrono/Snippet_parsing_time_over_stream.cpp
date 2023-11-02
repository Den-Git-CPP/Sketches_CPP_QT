std::string Function::replace_format_time(const std::string& str_time)
{
	std::tm t = {};
	std::istringstream ss(str_time);
	std::ostringstream os;

	ss >> std::get_time(&t, "%Y-%m-%dT%H:%M:%SZ");
	if (ss.fail()) { std::cout << "Parse DATE_TIME failed\n"; }
	else {
		os << std::put_time(&t, "%H:%M:%S %d-%m-%Y  UTC");
	}
	return os.str();
}
