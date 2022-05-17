SELECT names FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN movies ON stars.movie_id = movies.id
    WHERE movie_id IN (name = "Kevin Bacon" AND birth = 1958);