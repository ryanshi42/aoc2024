from typing import Iterable

from movie import Movie

# My defined functions
from bisect import bisect_left, bisect_right
from collections import defaultdict

class MovieCatalog:
    def __init__(self, filename: str) -> None:
        """
        :param filename: Full path to movie info file
        :return: None
        """
        
        # Note: this is a mapping from genre
        self.genre_to_movies = defaultdict(lambda: [])
        
        with open(filename) as file:
            for line in file: 
                # Note: could put a try except block here to prevent program from crashing on errored input
                line = line.strip()
                (movie_id, title, year, piped_genres) = line.split(',')
                if movie_id == "#movieId":
                    continue
                    
                # Set allows for fast O(1) lookup if needed later
                genres = piped_genres.split("|")
                
                genre_set = set(genres)
                new_movie = Movie(movie_id, title, int(year), genre_set)
                
                for genre in genres:
                    self.genre_to_movies[genre].append(new_movie)
                
        for movie_list in self.genre_to_movies.values():
            movie_list.sort(key=lambda m: m.publication_year)

    def get_movies(self, genre: str, start_year: int, end_year: int) -> Iterable[Movie]:
        """
        Returns Movies that are in the supplied genre and between the year range from the movie catalog
        :param genre: Genre to search for
        :param start_year: Inclusive start publication year
        :param end_year: Inclusive end publication year
        :return: Movie objects of movies matching the search criteria
        """

        # Search your movie catalog storage to return the correct movies
        # res = Search Result
        res = []
        
        # Check edge cases
        movie_list = self.genre_to_movies[genre]
        if not movie_list:
            return res
        elif movie_list[-1].publication_year < start_year:
            return res
        elif movie_list[0].publication_year > end_year:
            return res
            
        # Up to here there definitely exist some movies in the range
        # idx = bisect_left(movie_list, start_year, key=lambda m: m.publication_year)
        
        # for i in range(idx, len(movie_list)):
        #     movie = movie_list[i]
        #     if movie.publication_year >= start_year and movie.publication_year <= end_year:
        #         res.append(movie)
        #     if publication_year > end_year:
        #         break
        # return res
                
        # Generator solution?
        l = bisect_left(movie_list, start_year, key=lambda m: m.publication_year)
        r = bisect_right(movie_list, end_year, key=lambda m: m.publication_year)

        # This code is wrong
        # if movie_list[l].publication_year > start_year:
        #     l += 1
        if movie_list[r].publication_year > end_year:
            r -= 1

        # print(movie_list[l], movie_list[r], start_year, end_year)
        return (movie_list[i] for i in range(l, r + 1))


def movie_generator(movie_list, l, r):
    for i in range(l, r + 1):
        yield movie_list[i]
