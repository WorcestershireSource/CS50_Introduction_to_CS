SELECT title FROM movies, stars, people
    WHERE movies.id = stars.movie_id
    AND stars.person_id = people.id
    AND name = "Johnny Depp"
    AND name = "Helena Bonham Carter";




JD = 136

HBC = 307

Corpse Bride  = 121164