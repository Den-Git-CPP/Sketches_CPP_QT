
##  Регулярное выражение в качестве примера.
- соответствующее имени файла MS-DOS   
~~~
char regex_filename[] = «[a-zA-Z_] [a-zA-Z_0-9]*\\.[a-zA-Z0-9]+»;
~~~

- соответствующее в 24-часовом формате (т.е. ЧЧ:ММ)
~~~
\b([01]?[0-9]|2[0-3]):([0-5]\d)\b
~~~

## Разделение строки:
~~~
std::vector<std::string> split(const std::string &str, std::string regex)
{
    std::regex r{ regex };
    std::sregex_token_iterator start{ str.begin(), str.end(), r, -1 }, end;
    return std::vector<std::string>(start, end);
}
~~~
~~~
split("Some  string\t with whitespace ", "\\s+"); 

//out: "Some", "string", "with", "whitespace"
~~~