SELECT title FROM (SELECT title FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE title IN (SELECT title FROM movies WHERE name = "Johnny Depp")))
    WHERE title IN (SELECT title FROM movies WHERE name = "Helena Bonham Carter");

SELECT title FROM movies
    WHERE id IN (SELECT movie_id FROM stars
        WHERE person_id )


SELECT title FROM movies
    WHERE id IN (SELECT movie_id FROM stars
        WHERE person_id IN (SELECT id FROM people
            WHERE name LIKE 'Helena Bonham Carter') AND (SELECT id FROM people
                WHERE name LIKE 'Johnny Depp'));


JD = 136

HBC = 307

Corpse Bride  = 121164