SELECT name FROM people
    JOIN stars ON people.id = stars.person_id
    WHERE movie_id  (SELECT movie_id WHERE (name = "Kevin Bacon" AND birth = 1958));

SELECT title, movie_id FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE (name = "Kevin Bacon" AND birth = 1958);

SELECT name FROM people
    JOIN stars ON people.id = stars.person_id
    WHERE movie_id IN (112384, 112453);