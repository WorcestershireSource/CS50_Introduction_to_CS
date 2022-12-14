SELECT DISTINCT(title) FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE title IN (SELECT title FROM movies
        JOIN stars ON movies.id = stars.movie_id
        JOIN people ON stars.person_id = people.id
        WHERE name = "Helena Bonham Carter")
            AND title IN (SELECT title FROM movies
            JOIN stars ON movies.id = stars.movie_id
            JOIN people ON stars.person_id = people.id
            WHERE name = "Johnny Depp");