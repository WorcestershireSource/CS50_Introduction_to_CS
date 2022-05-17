SELECT name FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN movies ON stars.movie_id = movies.id
    WHERE movie_id IN (SELECT movie_id FROM movies WHERE name = "Kevin Bacon" AND birth = 1958);

SELECT title FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE name = "Kevin Bacon" AND birth = 1958;