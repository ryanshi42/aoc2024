#include "MovieCatalog.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>

const std::string test_filename("movies_formatted.csv");

class Timer
{
public:
    Timer()
    {
        timestamp_ = std::chrono::steady_clock::now();
    }

    float elapsed()
    {
        std::chrono::duration<float> fs =
            std::chrono::steady_clock::now() - timestamp_;
        return fs.count();
    }
private:
    std::chrono::steady_clock::time_point timestamp_;
};

bool compare_results(std::vector<std::string> lhs, std::vector<std::string> rhs)
{
    if (rhs.size() == 0)
    {
        // Only some of the test cases provide data to compare with. If no
        // data is provided, assume a match.
        return true;
    }

    if (lhs.size() != rhs.size())
    {
        return false;
    }

    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());
    return lhs == rhs;
}

void run_test(MovieCatalog& s, const std::string& genre, const std::string& start,
              const std::string& end, size_t num_expected,
              const std::vector<std::string>& expected = {})
{
    std::cout << "---\n";
    std::cout << "get_movies(" << genre << ',' << start << ',' << end << "): ";
    Timer t;
    auto results = s.get_movies(genre, start, end);
    std::cout << "took " << t.elapsed() << " seconds: ";
    if (results.size() != num_expected)
    {
        std::cout << "FAILED" << std::endl;
        std::cout << "Expected " << num_expected << " movies, but got "
                  << results.size() << std::endl;
    }
    else if (!compare_results(results, expected))
    {
        std::cout << "FAILED" << std::endl;
        std::cout << "Results do not match expected movies" << std::endl;
    }
    else
    {
        std::cout << "PASSED" << std::endl;
    }
}

// Run test cases
int main()
{
    MovieCatalog catalog(test_filename);
    run_test(catalog, "IMAX", "1891", "2038", 196);
    run_test(catalog, "IMAX", "1980", "1993", 4,
             {"Hail Columbia!", "Chronos", "Beauty and the Beast", "Titanica"});
    run_test(catalog, "Fantasy", "1999", "1999", 28);
    run_test(catalog, "Fakeout", "1980", "2015", 0);
    run_test(catalog, "IMAX", "1994", "1994", 4,
             {"Lion King The", "Africa: The Serengeti", "Destiny in Space",
              "Into the Deep"});
    run_test(catalog, "Musical", "1989", "1990", 10,
             {"Little Mermaid The", "Eddie and the Cruisers II: Eddie Lives!",
              "Meet the Feebles", "Leningrad Cowboys Go America",
              "Phantom of the Opera The", "Mo' Better Blues",
              "Graffiti Bridge", "Cry-Baby",
              "Disney Sing Along Songs: Under the Sea", "Jetsons: The Movie"});
    run_test(catalog, "(no genres listed)", "2000", "2005", 21);
    run_test(catalog, "IMAX", "2015", "2010", 0);

    return 0;
}
