#pragma once

#include <string>
#include <vector>

struct Movie
{
    std::string id;
    std::string name;
    std::string year;
    std::vector<std::string> genres;
};

struct Key {
    std::string genre;
    std::string year;
    friend auto operator==(Key const& lhs, Key const& rhs) -> bool = default;
};

struct HashKey {
	size_t operator()(Key const& key) const {
		auto hash1 = std::hash<std::string>{}(key.genre);
		auto hash2 = std::hash<std::string>{}(key.year);
		return hash1 != hash2 ? hash1 ^ hash2 : hash1;
	}
};

class MovieCatalog
{
public:
    //
    // Load CSV data from the provided input file into data structures
    // suitable for querying the data using get_movies().
    //
    // CSV lines are in format "MovieId,Title,YearReleased,Genre[|Genre]".
    //
    MovieCatalog(const std::string& movies_file);

    //
    // Given a genre and an inclusive date range, return the movies released in
    // the year within the range and matching the genre.
    //
    // Dates are provided in YYYY format (e.g. 2014).
    // Returns a vector of movie titles that match the query.
    //
    std::vector<std::string> get_movies(const std::string& genre,
                                        const std::string& startYear,
                                        const std::string& endYear);

private:
    // TODO: change this data structure to optimize for lookup time
    std::unordered_map<Key, std::vector<Movie>, HashKey> movies_;
};
