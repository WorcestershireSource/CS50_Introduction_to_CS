SELECT title FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE movie_id = (SELECT movie_id FROM stars
        JOIN people ON stars.person_id = people.id
        WHERE name = "Johnny Depp" AND name = "Helena Bonham Carter");




JD = 136

HBC = 307

Corpse Bride  = 121164