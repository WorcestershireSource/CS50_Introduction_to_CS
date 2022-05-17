SELECT names FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN movies ON stars.movie_id = movies.id
    WHERE name = "Johnny Depp" OR "Helena Bonham Carter";