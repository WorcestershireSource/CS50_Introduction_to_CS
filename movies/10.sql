SELECT DISTINCT(name) FROM people
    JOIN directors ON people.id = directors.person_id
    JOIN ratings ON directors.movie_id = movies.id
    WHERE rating <= 9.0;