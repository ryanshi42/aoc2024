# Movie Catalog Task

## Background

The local library is expanding to provide movies, and wants to create a catalog and recommendation system to allow patrons easier access.

To start, the librarians have a comma-delimited file with the following information on each movie:

* Title
* Publication year
* List of Genres (pipe-delimited)

If there is no genre the genre list is not empty, it will instead contain a placeholder of (no genres listed) to make it very clear.

The sample below is a subset of the actual file and shows the first few rows, the last few rows, and some in the middle:

```txt
#movieId,title,date,genres
1,Toy Story,1995,Adventure|Animation|Children|Comedy|Fantasy
2,Jumanji,1995,Adventure|Children|Fantasy
3,Grumpier Old Men,1995,Comedy|Romance
...
84764,Werewolves on Wheels,1971,Horror
84766,Fantasma,2006,Drama
84768,Glitterbug,1994,(no genres listed)
...
131260,Rentun Ruusu,2001,(no genres listed)
131262,Innocence,2014,Adventure|Fantasy|Horror
```

## Task

You have been given a working, though inefficient solution. Your task is to update the MovieCatalog data structure(s), constructor, and get_movies function to improve run-time performance. To that end, you should focus on updating the code in MovieCatalog.h and MovieCatalog.cpp. main.cpp contains unit tests which you can view but should not need to be modified.

Your changes must not alter the current signature of the get_movies method, but you are free to make any changes to this method's implementation, the CSV-loading constructor, the data structures used or any other classes involved.

`vector<string> get_movies(Genre, Start Year, End Year)`

## Notes

* The dates you receive in the query should be included in the search.
* There is not one correct solution to this exercise. You may assume that the input file contains only clean data.
* If there are any libraries you would like to use or packages you would like to reference, feel free to include them.
* **[execution time limit] 30 seconds**

### Free-Filesystem

Your solution, which can be written in one or multiple files, will be executed via the `main.sh` entry point.

### Language

C++ (G++ v11.1.0)

We support C++ (G++ v11.1.0). Feel free to use unordered_map, regex, range for, auto ... features from C++11, 14 and 17 standards.

You can use `std::cout << ... << std::endl` to print any data for debugging purposes.

The following libraries are available to be imported:

```cpp
#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <jsoncpp/json/json.h>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
```

Some best practices for C++:

* When declaring global variables in C++, initializing them during declaration will result in a syntax error. Instead, perform an initialization in the function/method.
* Static variables are disabled in C++, so using them will lead to unexpected results.
* Use C++11, 14 and 17 features, e.g. `for (auto x: vec) {...}` , `lambda functions [](int a, int b) -> bool {...}`.
