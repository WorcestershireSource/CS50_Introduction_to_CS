SELECT name FROM people
    JOIN stars ON people.id = stars.person_id
    WHERE movie_id IN (SELECT movie_id FROM stars
        JOIN people on stars.person_id = people.id
        WHERE (name = "Kevin Bacon" AND birth = 1958))
    AND name != "Kevin Bacon";

SELECT title, movie_id FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE (name = "Kevin Bacon" AND birth = 1958);

SELECT name FROM people
    JOIN stars ON people.id = stars.person_id
    WHERE movie_id IN (112384, 112453);