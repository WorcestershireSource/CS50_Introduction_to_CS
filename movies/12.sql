SELECT title FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE title IN (SELECT title FROM movies WHERE name = "Johnny Depp")
    AND title IN (SELECT title FROM movies WHERE name = "Helena Bonham Carter");





JD = 136

HBC = 307

Corpse Bride  = 121164