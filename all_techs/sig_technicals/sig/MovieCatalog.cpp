#include "MovieCatalog.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::string> split(const std::string &s, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

MovieCatalog::MovieCatalog(const std::string &movies_file) {
	std::ifstream ifs(movies_file.c_str(), std::ifstream::in);
	std::string s;

	std::cout << movies_file << " " << ifs.good() << std::endl;

	while (ifs.good() && std::getline(ifs, s)) {
		if ('#' == s[0]) continue;

		std::vector<std::string> v = split(s, ',');

		std::vector<std::string> genres = split(v[3], '|');
		for (auto &&genre : genres) {
			movies_[{genre, v[2]}].push_back(Movie{v[0], v[1], v[2], genres});
		}
	}
	ifs.close();
}

// TODO: modify the code in MovieCatalog.cpp and MovieCatalog.h to try to make
// get_movies() run faster. This may include changing the movies_ data
// structure, the class constructor function and get_movies.
std::vector<std::string> MovieCatalog::get_movies(
    const std::string &genre,
    const std::string &startYear,
    const std::string &endYear
) {
	std::vector<std::string> results;
	for (int year = std::stoi(startYear); year <= std::stoi(endYear); ++year) {
		auto &movies = movies_[{genre, std::to_string(year)}];
		std::transform(
		    movies.cbegin(),
		    movies.cend(),
		    std::back_inserter(results),
		    [](Movie const &movie) { return movie.name; }
		);
	}
	return results;
}
