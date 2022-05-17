SELECT title FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE "Johnny Depp" AND name = "Helena Bonham Carter";